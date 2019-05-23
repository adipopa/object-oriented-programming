#include "WatchlistHTMLRepository.h"

WatchlistHTMLRepository::WatchlistHTMLRepository(std::vector<Recording> watchlist) : WatchlistRepository{ watchlist } {}

void WatchlistHTMLRepository::saveToWatchlist(const Recording & recording) {
	this->watchlist.push_back(recording);
	this->exportToHTML();
}

void WatchlistHTMLRepository::setMylistLocation(const std::string & mylistLocation) {
	this->mylistLocation = mylistLocation;
	this->exportToHTML();
}

void WatchlistHTMLRepository::exportToHTML() {
	if (this->mylistLocation.empty()) {
		return;
	}

	std::ofstream outputStream(this->mylistLocation);

	outputStream << "<!DOCTYPE html>\n";
	outputStream << "<html>\n";
	outputStream << "<head><title>Watchlist</title></head>\n";
	outputStream << "<body>\n";
	outputStream << "<table border=\"1\">\n";

	outputStream << "<tr>\n";
	outputStream << "<td>Title</td>\n";
	outputStream << "<td>Location</td>\n";
	outputStream << "<td>Time of creation</td>\n";
	outputStream << "<td>Times accessed</td>\n";
	outputStream << "<td>Footage preview</td>\n";
	outputStream << "</tr>\n";

	for (auto const& recording : this->watchlist) {
		outputStream << "<tr>\n";
		outputStream << "<td>" << recording.getTitle() << "</td>\n";
		outputStream << "<td>" << recording.getLocation() << "</td>\n";
		outputStream << "<td>" << recording.getTimeOfCreation() << "</td>\n";
		outputStream << "<td>" << recording.getTimesAccessed() << "</td>\n";
		outputStream << "<td>" << recording.getFootagePreview() << "</td>\n";
		outputStream << "</tr>\n";
	}

	outputStream << "</table>\n";
	outputStream << "</body>\n";
	outputStream << "</html>\n";

	outputStream.close();
}

void WatchlistHTMLRepository::openMylist() {
	std::string path = "\"" + this->mylistLocation + "\"";
	ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe", path.c_str(), NULL, SW_SHOWMAXIMIZED);
}

WatchlistHTMLRepository::~WatchlistHTMLRepository() {}
