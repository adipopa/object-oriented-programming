#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "RecordingController.h"
#include <QAbstractTableModel>
#include <qcolor.h>
#include <string>

using namespace std;

class RecordingModel : public QAbstractTableModel {

private:
	shared_ptr<RecordingController> recordingController;

public:
	RecordingModel(const shared_ptr<RecordingController>& recordingController);
	
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;
	
	Qt::ItemFlags flags(const QModelIndex &index) const override;
	
	~RecordingModel();
};

