#pragma once

#include "Signal.h"

typedef struct SignalRepository {
	Signal* signals;
	int length;
} SignalRepository;

SignalRepository SignalRepositoryConstructor();

void add(SignalRepository* signalRepository, Signal signal);

void update(SignalRepository* signalRepository, Signal signal);

void delete(SignalRepository* signalRepository, int signalId);

void getAll(SignalRepository* signalRepository, char* formattedSignalsList);

void getByType(SignalRepository* signalRepository, char type[], char* formattedSignalsList);