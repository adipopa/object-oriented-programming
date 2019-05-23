#include "WatchlistCSVRepository.h"

WatchlistCSVRepository::WatchlistCSVRepository(std::vector<Recording> watchlist) : WatchlistRepository{ watchlist } {}

void WatchlistCSVRepository::saveToWatchlist(const Recording & recording) {
	this->watchlist.push_back(recording);
	this->exportToCSV();
}

void WatchlistCSVRepository::setMylistLocation(const std::string & mylistLocation) {
	this->mylistLocation = mylistLocation;
	this->exportToCSV();
}

void WatchlistCSVRepository::exportToCSV() {
	if (this->mylistLocation.empty()) {
		return;
	}

	std::ofstream outputStream(this->mylistLocation);

	for (auto const& recording : this->watchlist) {
		outputStream << recording;
	}

	outputStream.close();
}

void WatchlistCSVRepository::openMylist() {
	std::string path = "\"" + this->mylistLocation + "\"";
	ShellExecuteA(NULL, NULL, "C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE", path.c_str(), NULL, SW_SHOWMAXIMIZED);
}

WatchlistCSVRepository::~WatchlistCSVRepository() {}
