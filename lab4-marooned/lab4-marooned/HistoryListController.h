#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

#include "DynamicArray.h"
#include "SignalController.h"

typedef struct HistoryListController {
	DynamicArray* undoList;
	int itemsIndex;

	SignalController* signalController;
} HistoryListController;

HistoryListController* HistoryListControllerConstructor(SignalController* signalController);

void appendUndoList(HistoryListController* historyListController, DynamicArray* items);

int undoItems(HistoryListController* historyListController);

int redoItems(HistoryListController* historyListController);

DynamicArray* getUndoItems(HistoryListController* historyListController);

int canListUndo(HistoryListController* historyListController);

int canListRedo(HistoryListController* historyListController);

void HistoryListControllerDestructor(HistoryListController* historyListController);