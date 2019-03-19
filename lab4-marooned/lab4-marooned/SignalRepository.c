#include "SignalRepository.h"

SignalRepository* SignalRepositoryConstructor() {
	SignalRepository* signalRepository = (SignalRepository*)malloc(sizeof(SignalRepository));
	signalRepository->signals = DynamicArrayConstructor(copySignal, SignalDestructor);
	return signalRepository;
}

void addToRepository(SignalRepository* signalRepository, Signal* signal) {
	addToArray(signalRepository->signals, signal);
}

void updateInRepository(SignalRepository* signalRepository, Signal* signal) {
	int signalIndex = getElementIndex(signalRepository->signals, signalCompareFn, signal);
	updateInArray(signalRepository->signals, signalIndex, signal);
}

void deleteFromRepository(SignalRepository* signalRepository, Signal* signal) {
	int signalIndex = getElementIndex(signalRepository->signals, signalCompareFn, signal);
	deleteFromArray(signalRepository->signals, signalIndex);
}

Signal* getFromRepository(SignalRepository* signalRepository, int signalId) {
	Signal* signal = SignalConstructor(signalId, "", "", 0);
	int signalIndex = getElementIndex(signalRepository->signals, signalCompareFn, signal);
	SignalDestructor(signal);
	return getFromArray(signalRepository->signals, signalIndex);
}

DynamicArray* getAll(SignalRepository* signalRepository) {
	return copyArray(signalRepository->signals);
}

DynamicArray* getByModulatedSignal(SignalRepository* signalRepository, char* modulatedSignal) {
	return filterArray(signalRepository->signals, signalModulatedSignalFilterFn, modulatedSignal);
}

DynamicArray* getByType(SignalRepository* signalRepository, char* type) {
	return filterArray(signalRepository->signals, signalTypeFilterFn, type);
}

DynamicArray* getByPriorityNumberAsc(SignalRepository* signalRepository, int priorityNumber) {
	DynamicArray* signalsByPriorityNumber = filterArray(signalRepository->signals, signalPriorityNumberFilterFn, &priorityNumber);
	return sortArray(signalsByPriorityNumber, signalModulatedSignalAscSortFn);
}

DynamicArray* getByPriorityNumberDesc(SignalRepository* signalRepository, int priorityNumber) {
	DynamicArray* signalsByPriorityNumber = filterArray(signalRepository->signals, signalPriorityNumberFilterFn, &priorityNumber);
	return sortArray(signalsByPriorityNumber, signalModulatedSignalDescSortFn);
}

void signalsToString(DynamicArray* signals, char* formattedSignalsList) {
	for (int i = 0; i < signals->length; i++) {
		char formattedSignal[32] = "";
		signalToString(((Signal*)signals->elements[i]), formattedSignal);
		strcat(formattedSignalsList, formattedSignal);
	}
}

void SignalRepositoryDestructor(SignalRepository* signalRepository) {
	if (signalRepository != NULL) {
		DynamicArrayDestructor(signalRepository->signals);
		free(signalRepository);
	}
}