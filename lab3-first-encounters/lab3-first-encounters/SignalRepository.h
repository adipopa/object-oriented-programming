#pragma once

#include "Signal.h"

typedef struct SignalRepository {
	Signal* signals;
	int length;
} SignalRepository;

SignalRepository SignalRepositoryConstructor();

void addToRepository(SignalRepository* signalRepository, Signal signal);

void updateInRepository(SignalRepository* signalRepository, Signal signal);

void deleteFromRepository(SignalRepository* signalRepository, int signalId);

void getAll(SignalRepository* signalRepository, char* formattedSignalsList);

void getByType(SignalRepository* signalRepository, char type[], char* formattedSignalsList);

void SignalRepositoryDestructor(SignalRepository* signalRepository);