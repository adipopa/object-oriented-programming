#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <crtdbg.h>

#include "SignalController.h"
#include "HistoryController.h"

typedef struct Testing {
	SignalValidator* signalValidator;
	SignalRepository* signalRepository;
	SignalController* signalController;
	HistoryController* historyController;
} Testing;

Testing* TestingConstructor();

void testCreateSignal(Testing* testing);
void testUpdateSignal(Testing* testing);
void testDeleteSignal(Testing* testing);
void testGetSignal(Testing* testing);
void testGetSignals(Testing* testing);
void testGetSignalsByModulatedSignal(Testing* testing);
void testGetSignalsByType(Testing* testing);
void testGetSignalsByPriorityNumberAsc(Testing* testing);
void testGetSignalsByPriorityNumberDesc(Testing* testing);

void testSignalController(Testing* testing);

void testCreateOperation(Testing* testing);
void testUndoOperation(Testing* testing);
void testRedoOperation(Testing* testing);
void testGetUndoOperation(Testing* testing);
void testGetRedoOperation(Testing* testing);
void testCanUndo(Testing* testing);
void testCanRedo(Testing* testing);

void testHistoryController(Testing* testing);

void printTestsPassed(Testing* testing);

void runTests(Testing* testing);

void TestingDestructor(Testing* testing);