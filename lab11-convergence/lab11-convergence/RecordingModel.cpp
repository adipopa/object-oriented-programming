#include "RecordingModel.h"

RecordingModel::RecordingModel(const shared_ptr<RecordingController>& recordingController) : recordingController{ recordingController } {}

int RecordingModel::rowCount(const QModelIndex & parent) const {
	return this->recordingController->getRecordings().size();
}

int RecordingModel::columnCount(const QModelIndex & parent) const {
	return 5;
}

QVariant RecordingModel::data(const QModelIndex & index, int role) const {
	int row = index.row();
	int column = index.column();

	Recording currentRecording = this->recordingController->getRecordings()[row];
	if (role == Qt::DisplayRole) {
		switch (column) {
			case 0:
				return QString::fromStdString(currentRecording.getTitle());
			case 1:
				return QString::fromStdString(currentRecording.getLocation());
			case 2:
				return QString::fromStdString(currentRecording.getTimeOfCreation());
			case 3:
				return QString::number(currentRecording.getTimesAccessed());
			case 4:
				return QString::fromStdString(currentRecording.getFootagePreview());
			default:
				break;
		}
	}

	if (role == Qt::BackgroundColorRole) {
		if (row % 2 == 0) {
			return QColor{ "#E3E3E3" };
		}
	}

	return QVariant();
}

QVariant RecordingModel::headerData(int section, Qt::Orientation orientation, int role) const {
	if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
		switch (section) {
			case 0:
				return "Title";
			case 1:
				return "Location";
			case 2:
				return "Time of creation";
			case 3:
				return "Times accessed";
			case 4:
				return "Footage preview";
			default:
				break;
		}
	}

	return QVariant();
}

Qt::ItemFlags RecordingModel::flags(const QModelIndex & index) const {
	return QAbstractTableModel::flags(index);
}

RecordingModel::~RecordingModel() {}
