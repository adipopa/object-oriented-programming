#include "Testing.h"

Testing* TestingConstructor() {
	Testing* testing = (Testing*)malloc(sizeof(Testing));
	testing->signalRepository = SignalRepositoryConstructor();
	testing->signalValidator = SignalValidatorConstructor(testing->signalRepository);
	testing->signalController = SignalControllerConstructor(testing->signalValidator, testing->signalRepository);
	testing->historyController = HistoryControllerConstructor();
	return testing;
}

void testCreateSignal(Testing* testing) {
	Signal* signal1 = SignalConstructor(1, "AM", "damage-inner", 9);
	Signal* signal2 = SignalConstructor(2, "FM", "damage-outer", 7);
	Signal* signal3 = SignalConstructor(3, "FM", "damage-outer", 8);
	Signal* signal4 = SignalConstructor(4, "SM", "damage-inner", 9);
	Signal* signal5 = SignalConstructor(5, "SM", "sensor-reading", 8);

	createSignal(testing->signalController, signal1);
	createSignal(testing->signalController, signal2);
	createSignal(testing->signalController, signal3);
	createSignal(testing->signalController, signal4);
	createSignal(testing->signalController, signal5);

	DynamicArray* signals = testing->signalController->signalRepository->signals;

	assert(signals->length == 5);
	assert(((Signal*)signals->elements[0])->id == 1);
	assert(strcmp(((Signal*)signals->elements[0])->modulatedSignal, "AM") == 0);
	assert(strcmp(((Signal*)signals->elements[0])->type, "damage-inner") == 0);
	assert(strcmp(((Signal*)signals->elements[1])->type, "damage-outer") == 0);
	assert(((Signal*)signals->elements[2])->priorityNumber == 8);
	assert(((Signal*)signals->elements[3])->priorityNumber == 9);
	assert(((Signal*)signals->elements[4])->priorityNumber == 8);

	SignalDestructor(signal1);
	SignalDestructor(signal2);
	SignalDestructor(signal3);
	SignalDestructor(signal4);
	SignalDestructor(signal5);
}

void testUpdateSignal(Testing* testing) {
	Signal* signal1 = SignalConstructor(1, "FM", "damage-inner", 8);
	Signal* signal2 = SignalConstructor(2, "AM", "damage-inner", 7);
	Signal* signal3 = SignalConstructor(3, "AM", "sensor-reading", 9);

	updateSignal(testing->signalController, signal1);
	updateSignal(testing->signalController, signal2);
	updateSignal(testing->signalController, signal3);

	DynamicArray* signals = testing->signalController->signalRepository->signals;

	assert(signals->length == 5);
	assert(((Signal*)signals->elements[0])->id == 1);
	assert(strcmp(((Signal*)signals->elements[0])->modulatedSignal, "FM") == 0);
	assert(strcmp(((Signal*)signals->elements[0])->type, "damage-inner") == 0);
	assert(strcmp(((Signal*)signals->elements[1])->type, "damage-inner") == 0);
	assert(((Signal*)signals->elements[2])->priorityNumber == 9);

	SignalDestructor(signal1);
	SignalDestructor(signal2);
	SignalDestructor(signal3);
}

void testDeleteSignal(Testing* testing) {
	Signal* signal4 = SignalConstructor(4, "", "", 0);
	Signal* signal5 = SignalConstructor(5, "", "", 0);

	deleteSignal(testing->signalController, signal4);
	deleteSignal(testing->signalController, signal5);

	DynamicArray* signals = testing->signalController->signalRepository->signals;

	assert(signals->length == 3);

	SignalDestructor(signal4);
	SignalDestructor(signal5);
}

void testGetSignal(Testing* testing) {
	Signal* signal1 = getSignal(testing->signalController, 1);
	Signal* signal2 = getSignal(testing->signalController, 2);
	Signal* signal3 = getSignal(testing->signalController, 3);

	assert(signal1->id == 1);
	assert(strcmp(signal1->modulatedSignal, "FM") == 0);
	assert(strcmp(signal1->type, "damage-inner") == 0);
	assert(strcmp(signal2->type, "damage-inner") == 0);
	assert(signal3->priorityNumber == 9);

	SignalDestructor(signal1);
	SignalDestructor(signal2);
	SignalDestructor(signal3);
}

void testGetSignals(Testing* testing) {
	DynamicArray* allSignals = getSignals(testing->signalController);

	assert(allSignals->length == 3);
	assert(((Signal*)allSignals->elements[0])->id == 1);
	assert(strcmp(((Signal*)allSignals->elements[0])->modulatedSignal, "FM") == 0);
	assert(strcmp(((Signal*)allSignals->elements[0])->type, "damage-inner") == 0);
	assert(strcmp(((Signal*)allSignals->elements[1])->type, "damage-inner") == 0);
	assert(((Signal*)allSignals->elements[2])->priorityNumber == 9);

	DynamicArrayDestructor(allSignals);
}

void testGetSignalsByModulatedSignal(Testing* testing) {
	DynamicArray* signalsByModulatedSignal = getSignalsByModulatedSignal(testing->signalController, "AM");

	assert(signalsByModulatedSignal->length == 2);
	assert(((Signal*)signalsByModulatedSignal->elements[0])->id == 2);
	assert(strcmp(((Signal*)signalsByModulatedSignal->elements[0])->modulatedSignal, "AM") == 0);
	assert(strcmp(((Signal*)signalsByModulatedSignal->elements[0])->type, "damage-inner") == 0);
	assert(strcmp(((Signal*)signalsByModulatedSignal->elements[1])->type, "sensor-reading") == 0);
	assert(((Signal*)signalsByModulatedSignal->elements[1])->priorityNumber == 9);

	DynamicArrayDestructor(signalsByModulatedSignal);
}

void testGetSignalsByType(Testing* testing) {
	DynamicArray* signalsByType = getSignalsByType(testing->signalController, "damage-inner");

	assert(signalsByType->length == 2);
	assert(((Signal*)signalsByType->elements[0])->id == 1);
	assert(strcmp(((Signal*)signalsByType->elements[0])->modulatedSignal, "FM") == 0);
	assert(strcmp(((Signal*)signalsByType->elements[0])->type, "damage-inner") == 0);
	assert(strcmp(((Signal*)signalsByType->elements[1])->type, "damage-inner") == 0);
	assert(((Signal*)signalsByType->elements[1])->priorityNumber == 7);

	DynamicArrayDestructor(signalsByType);
}

void testGetSignalsByPriorityNumberAsc(Testing* testing) {
	DynamicArray* signalsByPropertyNumberAsc = getSignalsByPriorityNumberAsc(testing->signalController, 9);

	assert(signalsByPropertyNumberAsc->length == 2);
	assert(((Signal*)signalsByPropertyNumberAsc->elements[0])->id == 2);
	assert(strcmp(((Signal*)signalsByPropertyNumberAsc->elements[0])->modulatedSignal, "AM") == 0);
	assert(strcmp(((Signal*)signalsByPropertyNumberAsc->elements[0])->type, "damage-inner") == 0);
	assert(strcmp(((Signal*)signalsByPropertyNumberAsc->elements[1])->type, "damage-inner") == 0);
	assert(((Signal*)signalsByPropertyNumberAsc->elements[1])->priorityNumber == 8);

	DynamicArrayDestructor(signalsByPropertyNumberAsc);
}

void testGetSignalsByPriorityNumberDesc(Testing* testing) {
	DynamicArray* signalsByPropertyNumberDesc = getSignalsByPriorityNumberDesc(testing->signalController, 9);

	assert(signalsByPropertyNumberDesc->length == 2);
	assert(((Signal*)signalsByPropertyNumberDesc->elements[0])->id == 1);
	assert(strcmp(((Signal*)signalsByPropertyNumberDesc->elements[0])->modulatedSignal, "FM") == 0);
	assert(strcmp(((Signal*)signalsByPropertyNumberDesc->elements[0])->type, "damage-inner") == 0);
	assert(strcmp(((Signal*)signalsByPropertyNumberDesc->elements[1])->type, "damage-inner") == 0);
	assert(((Signal*)signalsByPropertyNumberDesc->elements[1])->priorityNumber == 7);

	DynamicArrayDestructor(signalsByPropertyNumberDesc);
}


void testSignalController(Testing* testing) {
	testCreateSignal(testing);
	testUpdateSignal(testing);
	testDeleteSignal(testing);
	testGetSignal(testing);
	testGetSignals(testing);
	testGetSignalsByModulatedSignal(testing);
	testGetSignalsByType(testing);
	testGetSignalsByPriorityNumberAsc(testing);
	testGetSignalsByPriorityNumberDesc(testing);
}

void testCreateOperation(Testing* testing) {
	Signal* signal1 = SignalConstructor(4, "SM", "damage-inner", 7);
	createSignal(testing->signalController, signal1);
	Operation* undoOperation1 = OperationConstructor(deleteSignal, testing->signalController, signal1);
	Operation* redoOperation1 = OperationConstructor(createSignal, testing->signalController, signal1);

	Signal* oldSignal2 = getSignal(testing->signalController, 4);
	Signal* newSignal2 = SignalConstructor(4, "AM", "sensor-reading", 8);
	updateSignal(testing->signalController, newSignal2);
	Operation* undoOperation2 = OperationConstructor(updateSignal, testing->signalController, oldSignal2);
	Operation* redoOperation2 = OperationConstructor(updateSignal, testing->signalController, newSignal2);

	createOperation(testing->historyController, undoOperation1, redoOperation1);
	createOperation(testing->historyController, undoOperation2, redoOperation2);

	DynamicArray* undoOperations = testing->historyController->undoOperations;
	DynamicArray* redoOperations = testing->historyController->redoOperations;
	int operationIndex = testing->historyController->operationIndex;

	assert(undoOperations->length == 2);
	assert(redoOperations->length == 2);
	assert(operationIndex == 1);
	assert(((Operation*)undoOperations->elements[0])->operationFn == deleteSignal);
	assert(((Operation*)redoOperations->elements[0])->operationFn == createSignal);
	assert(((Operation*)undoOperations->elements[1])->operationFn == updateSignal);
	assert(((Operation*)redoOperations->elements[1])->operationFn == updateSignal);
	assert(((Operation*)undoOperations->elements[0])->signalController == testing->signalController);
	assert(((Operation*)redoOperations->elements[1])->signalController == testing->signalController);
	assert(((Operation*)undoOperations->elements[0])->signal->id == signal1->id);
	assert(((Operation*)redoOperations->elements[0])->signal->id == signal1->id);
	assert(((Operation*)undoOperations->elements[1])->signal->id == oldSignal2->id);
	assert(((Operation*)redoOperations->elements[1])->signal->id == newSignal2->id);

	SignalDestructor(signal1);
	SignalDestructor(oldSignal2);
	SignalDestructor(newSignal2);

	OperationDestructor(undoOperation1);
	OperationDestructor(redoOperation1);
	OperationDestructor(undoOperation2);
	OperationDestructor(redoOperation2);
}

void testUndoOperation(Testing* testing) {
	DynamicArray* signals = testing->signalController->signalRepository->signals;

	assert(signals->length == 4);
	assert(((Signal*)signals->elements[3])->id == 4);
	assert(strcmp(((Signal*)signals->elements[3])->modulatedSignal, "AM") == 0);
	assert(strcmp(((Signal*)signals->elements[3])->type, "sensor-reading") == 0);
	assert(((Signal*)signals->elements[3])->priorityNumber == 8);

	undoOperation(testing->historyController);

	assert(signals->length == 4);
	assert(((Signal*)signals->elements[3])->id == 4);
	assert(strcmp(((Signal*)signals->elements[3])->modulatedSignal, "SM") == 0);
	assert(strcmp(((Signal*)signals->elements[3])->type, "damage-inner") == 0);
	assert(((Signal*)signals->elements[3])->priorityNumber == 7);

	undoOperation(testing->historyController);

	assert(signals->length == 3);
	assert(((Signal*)signals->elements[2])->id == 3);
	assert(strcmp(((Signal*)signals->elements[2])->modulatedSignal, "AM") == 0);
	assert(strcmp(((Signal*)signals->elements[2])->type, "sensor-reading") == 0);
	assert(((Signal*)signals->elements[2])->priorityNumber == 9);
}

void testRedoOperation(Testing* testing) {
	DynamicArray* signals = testing->signalController->signalRepository->signals;

	assert(signals->length == 3);
	assert(((Signal*)signals->elements[2])->id == 3);
	assert(strcmp(((Signal*)signals->elements[2])->modulatedSignal, "AM") == 0);
	assert(strcmp(((Signal*)signals->elements[2])->type, "sensor-reading") == 0);
	assert(((Signal*)signals->elements[2])->priorityNumber == 9);

	redoOperation(testing->historyController);

	assert(signals->length == 4);
	assert(((Signal*)signals->elements[3])->id == 4);
	assert(strcmp(((Signal*)signals->elements[3])->modulatedSignal, "SM") == 0);
	assert(strcmp(((Signal*)signals->elements[3])->type, "damage-inner") == 0);
	assert(((Signal*)signals->elements[3])->priorityNumber == 7);

	redoOperation(testing->historyController);

	assert(signals->length == 4);
	assert(((Signal*)signals->elements[3])->id == 4);
	assert(strcmp(((Signal*)signals->elements[3])->modulatedSignal, "AM") == 0);
	assert(strcmp(((Signal*)signals->elements[3])->type, "sensor-reading") == 0);
	assert(((Signal*)signals->elements[3])->priorityNumber == 8);
}

void testGetUndoOperation(Testing* testing) {
	Operation* undoOperation1 = getUndoOperation(testing->historyController);

	assert(undoOperation1->operationFn == updateSignal);
	assert(undoOperation1->signalController == testing->signalController);
	assert(undoOperation1->signal->id == 4);

	undoOperation(testing->historyController);

	Operation* undoOperation2 = getUndoOperation(testing->historyController);

	assert(undoOperation2->operationFn == deleteSignal);
	assert(undoOperation2->signalController == testing->signalController);
	assert(undoOperation2->signal->id == 4);

	OperationDestructor(undoOperation1);
	OperationDestructor(undoOperation2);
}

void testGetRedoOperation(Testing* testing) {
	Operation* redoOperation1 = getRedoOperation(testing->historyController);

	assert(redoOperation1->operationFn == createSignal);
	assert(redoOperation1->signalController == testing->signalController);
	assert(redoOperation1->signal->id == 4);

	redoOperation(testing->historyController);

	Operation* redoOperation2 = getRedoOperation(testing->historyController);

	assert(redoOperation2->operationFn == updateSignal);
	assert(redoOperation2->signalController == testing->signalController);
	assert(redoOperation2->signal->id == 4);

	OperationDestructor(redoOperation1);
	OperationDestructor(redoOperation2);
}

void testCanUndo(Testing* testing) {
	assert(canUndo(testing->historyController) == 1);
	undoOperation(testing->historyController);
	assert(canUndo(testing->historyController) == 1);
	undoOperation(testing->historyController);
	assert(canUndo(testing->historyController) == 0);
}

void testCanRedo(Testing* testing) {
	assert(canRedo(testing->historyController) == 1);
	redoOperation(testing->historyController);
	assert(canRedo(testing->historyController) == 1);
	redoOperation(testing->historyController);
	assert(canRedo(testing->historyController) == 0);
}


void testHistoryController(Testing* testing) {
	testCreateOperation(testing);
	testUndoOperation(testing);
	testRedoOperation(testing);
	testGetUndoOperation(testing);
	testGetRedoOperation(testing);
	testCanUndo(testing);
	testCanRedo(testing);
}

void printTestsPassed(Testing* testing) {
	FILE *fp = fopen("TestsPassed.txt", "r");
	if (fp == NULL) {
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	char ch;
	while ((ch = fgetc(fp)) != EOF) {
		printf("%c", ch);
	}
	printf("\n\n");
	fclose(fp);
}


void runTests(Testing* testing) {
	testSignalController(testing);
	testHistoryController(testing);
	
	printTestsPassed(testing);
}

void TestingDestructor(Testing* testing) {
	if (testing != NULL) {
		SignalControllerDestructor(testing->signalController);
		HistoryControllerDestructor(testing->historyController);
		free(testing);
	}
}