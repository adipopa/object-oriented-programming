#include "lab11convergence.h"
#include "RecordingModel.h"
#include <QtWidgets/QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTableView>
#include <QHeaderView>
#include <QPushButton>
#include <QLineEdit>

int main(int argc, char *argv[]) {
	QApplication application(argc, argv);

	std::shared_ptr<RecordingRepository> recordingRepository = std::make_shared<RecordingRepository>();
	std::shared_ptr<WatchlistRepository> watchlistRepository = std::make_shared<WatchlistRepository>();
	std::shared_ptr<RecordingValidator> recordingValidator = std::make_shared<RecordingValidator>(recordingRepository, watchlistRepository);
	std::shared_ptr<RecordingController> recordingController = std::make_shared<RecordingController>(
		recordingValidator, recordingRepository, watchlistRepository, "high-security"
	);

	recordingController->setFileLocation(".\\TestInput.txt");

	RecordingModel* recordingModel = new RecordingModel{ recordingController };

	QWidget* window = new QWidget;

	QHBoxLayout* layout = new QHBoxLayout;

	QVBoxLayout* leftSide = new QVBoxLayout;

	QLabel* recordingsLabel = new QLabel("Recordings");

	QTableView* recordingsTableView = new QTableView;
	recordingsTableView->setModel(recordingModel);
	recordingsTableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	recordingsTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	QHBoxLayout* titleEditBox = new QHBoxLayout;

	QLabel* titleLabel = new QLabel("Title: ");
	QLineEdit* titleLineEdit = new QLineEdit;
	titleLineEdit->setFixedWidth(300);

	titleEditBox->addWidget(titleLabel);
	titleEditBox->addWidget(titleLineEdit);

	QHBoxLayout* locationEditBox = new QHBoxLayout;

	QLabel* locationLabel = new QLabel("Location: ");
	QLineEdit* locationLineEdit = new QLineEdit;
	locationLineEdit->setFixedWidth(300);

	locationEditBox->addWidget(locationLabel);
	locationEditBox->addWidget(locationLineEdit);

	QHBoxLayout* timeOfCreationEditBox = new QHBoxLayout;

	QLabel* timeOfCreationLabel = new QLabel("Time of creation: ");
	QLineEdit* timeOfCreationLineEdit = new QLineEdit;
	timeOfCreationLineEdit->setFixedWidth(300);

	timeOfCreationEditBox->addWidget(timeOfCreationLabel);
	timeOfCreationEditBox->addWidget(timeOfCreationLineEdit);

	QHBoxLayout* timesAccessedEditBox = new QHBoxLayout;

	QLabel* timesAccessedLabel = new QLabel("Times accessed: ");
	QLineEdit* timesAccessedLineEdit = new QLineEdit;
	timesAccessedLineEdit->setFixedWidth(300);

	timesAccessedEditBox->addWidget(timesAccessedLabel);
	timesAccessedEditBox->addWidget(timesAccessedLineEdit);

	QHBoxLayout* footagePreviewEditBox = new QHBoxLayout;

	QLabel* footagePreviewLabel = new QLabel("Footage preview: ");
	QLineEdit* footagePreviewLineEdit = new QLineEdit;
	footagePreviewLineEdit->setFixedWidth(300);

	footagePreviewEditBox->addWidget(footagePreviewLabel);
	footagePreviewEditBox->addWidget(footagePreviewLineEdit);

	QHBoxLayout* managementButtonsBox = new QHBoxLayout;

	QPushButton* addRecordingButton = new QPushButton("Add");
	QPushButton* deleteRecordingButton = new QPushButton("Delete");
	QPushButton* updateRecordingButton = new QPushButton("Update");

	managementButtonsBox->addWidget(addRecordingButton);
	managementButtonsBox->addWidget(deleteRecordingButton);
	managementButtonsBox->addWidget(updateRecordingButton);

	QPushButton* filterRecordingsButton = new QPushButton("Filter");

	leftSide->addWidget(recordingsLabel);
	leftSide->addWidget(recordingsTableView);
	leftSide->addLayout(titleEditBox);
	leftSide->addLayout(locationEditBox);
	leftSide->addLayout(timeOfCreationEditBox);
	leftSide->addLayout(timesAccessedEditBox);
	leftSide->addLayout(footagePreviewEditBox);
	leftSide->addLayout(managementButtonsBox);
	leftSide->addWidget(filterRecordingsButton);

	QPushButton* saveRecordingButton = new QPushButton(">");

	QVBoxLayout* rightSide = new QVBoxLayout;

	QLabel* watchlistLabel = new QLabel("Watchlist");

	QTableView* watchlistTableView = new QTableView;
	watchlistTableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	watchlistTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	rightSide->addWidget(watchlistLabel);
	rightSide->addWidget(watchlistTableView);

	layout->addLayout(leftSide);
	layout->addWidget(saveRecordingButton);
	layout->addLayout(rightSide);

	window->setLayout(layout);
	window->setWindowTitle("High-sec clearance - Argo");
	window->setMinimumSize(924, 800);

	window->show();

	return application.exec();
}
