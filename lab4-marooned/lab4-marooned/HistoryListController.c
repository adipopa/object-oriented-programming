#include "HistoryListController.h"

HistoryListController* HistoryListControllerConstructor(SignalController* signalController) {
	HistoryListController* historyListController = (HistoryListController*)malloc(sizeof(HistoryListController));
	historyListController->undoList = DynamicArrayConstructor(copyArray, DynamicArrayDestructor);
	historyListController->itemsIndex = -1;

	DynamicArray* emptyItems = DynamicArrayConstructor(copyArray, DynamicArrayDestructor);
	appendUndoList(historyListController, emptyItems);
	DynamicArrayDestructor(emptyItems);

	historyListController->signalController = signalController;
	return historyListController;
}

void appendUndoList(HistoryListController* historyListController, DynamicArray* items) {
	if (canListRedo(historyListController)) {
		deleteAllFromIndex(historyListController->undoList, historyListController->itemsIndex + 1);
	}
	addToArray(historyListController->undoList, items);
	historyListController->itemsIndex++;
}

int undoItems(HistoryListController* historyListController) {
	if (!canListUndo(historyListController)) {
		return 0;
	}
	historyListController->itemsIndex--;
	DynamicArray* undoItems = getUndoItems(historyListController);
	DynamicArrayDestructor(historyListController->signalController->signalRepository->signals);
	historyListController->signalController->signalRepository->signals = undoItems;
	return 1;
}

int redoItems(HistoryListController* historyListController) {
	if (!canListRedo(historyListController)) {
		return 0;
	}
	historyListController->itemsIndex++;
	DynamicArray* undoItems = getUndoItems(historyListController);
	DynamicArrayDestructor(historyListController->signalController->signalRepository->signals);
	historyListController->signalController->signalRepository->signals = undoItems;
	return 1;
}

DynamicArray* getUndoItems(HistoryListController* historyListController) {
	return getFromArray(historyListController->undoList, historyListController->itemsIndex);
}

int canListUndo(HistoryListController* historyListController) {
	return historyListController->itemsIndex > 0;
}

int canListRedo(HistoryListController* historyListController) {
	return historyListController->itemsIndex < historyListController->undoList->length - 1;
}

void HistoryListControllerDestructor(HistoryListController* historyListController) {
	if (historyListController != NULL) {
		DynamicArrayDestructor(historyListController->undoList);
		free(historyListController);
	}
}