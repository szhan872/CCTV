#include <QTreeWidget>
#include <QLabel>
#include <QDebug>
#include "I8_PlaySDK.h"
#include "cctv.h"


void Http_RealData_CallBack(long hRtspHandle, unsigned long dwDataType, unsigned long dwProp, unsigned char *lpBuffer, unsigned long dwBufSize, void* lpUser) {
	//	if (dwDataType == ANTS_RTSP_DATATYPE_STREAMDATA_ANTSCOMB) {
	CCTV *client = (CCTV*)lpUser;

	AntsFrameHeader *i8Header = (AntsFrameHeader *)lpBuffer;

	I8_MP4Play_InputData(client->_port, lpBuffer, dwBufSize);
	qDebug() << client->_port << *lpBuffer;
}


CCTV::CCTV(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//tree demo
	QString apple = "apple";
	QTreeWidgetItem *item = new QTreeWidgetItem;
	item->setText(0, apple);
	ui.treeWidget->addTopLevelItem(item);
	QTreeWidgetItem *child = new QTreeWidgetItem;
	child->setText(0, u8"banana");
	item->addChild(child);

	//tool button style
	ui.four->setIcon(QIcon(":/CCTV/images/four.png"));
	ui.nine->setIcon(QIcon(":/CCTV/images/nine.png"));
	ui.six->setIcon(QIcon(":/CCTV/images/six.png"));

	four();//initialize widget

	//tool button connection
	connect(ui.four, SIGNAL(clicked()), this, SLOT(four()));
	connect(ui.nine, SIGNAL(clicked()), this, SLOT(nine()));
	connect(ui.six, SIGNAL(clicked()), this, SLOT(six()));

	connect(ui.startButton, SIGNAL(clicked()), this, SLOT(on_btn_start_clicked()));
	connect(this, SIGNAL(sig_output(QString)), this, SLOT(on_output(QString)));
	
}

CCTV::~CCTV()
{

}

void CCTV::four() {
	clearViewers();
	QWidget *w1 = new QWidget;
	QWidget *w2 = new QWidget;
	QWidget *w3 = new QWidget;
	QWidget *w4 = new QWidget;
	w1->setStyleSheet(QString::fromUtf8("border:3px solid black"));
	w2->setStyleSheet(QString::fromUtf8("border:3px solid black"));
	w3->setStyleSheet(QString::fromUtf8("border:3px solid black"));
	w4->setStyleSheet(QString::fromUtf8("border:3px solid black"));
	w1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	w2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	w3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	w4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	ui.ViewPort->addWidget(w1, 0, 0);
	ui.ViewPort->addWidget(w2, 0, 1);
	ui.ViewPort->addWidget(w3, 1, 0);
	ui.ViewPort->addWidget(w4, 1, 1);

}

void CCTV::nine() {
	clearViewers();
	QWidget *w1 = new QWidget;
	QWidget *w2 = new QWidget;
	QWidget *w3 = new QWidget;
	QWidget *w4 = new QWidget;
	QWidget *w5 = new QWidget;
	QWidget *w6 = new QWidget;
	QWidget *w7 = new QWidget;
	QWidget *w8 = new QWidget;
	QWidget *w9 = new QWidget;
	w1->setStyleSheet(QString::fromUtf8("border:3px solid black"));
	w2->setStyleSheet(QString::fromUtf8("border:3px solid black"));
	w3->setStyleSheet(QString::fromUtf8("border:3px solid black"));
	w4->setStyleSheet(QString::fromUtf8("border:3px solid black"));
	w5->setStyleSheet(QString::fromUtf8("border:3px solid black"));
	w6->setStyleSheet(QString::fromUtf8("border:3px solid black"));
	w7->setStyleSheet(QString::fromUtf8("border:3px solid black"));
	w8->setStyleSheet(QString::fromUtf8("border:3px solid black"));
	w9->setStyleSheet(QString::fromUtf8("border:3px solid black"));
	w1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	w2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	w3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	w4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	w5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	w6->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	w7->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	w8->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	w9->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	ui.ViewPort->addWidget(w1, 0, 0);
	ui.ViewPort->addWidget(w2, 0, 1);
	ui.ViewPort->addWidget(w3, 0, 2);
	ui.ViewPort->addWidget(w4, 1, 0);
	ui.ViewPort->addWidget(w5, 1, 1);
	ui.ViewPort->addWidget(w6, 1, 2);
	ui.ViewPort->addWidget(w7, 2, 0);
	ui.ViewPort->addWidget(w8, 2, 1);
	ui.ViewPort->addWidget(w9, 2, 2);
}

void CCTV::six() {
	clearViewers();
	QWidget *w1 = new QWidget;
	QWidget *w2 = new QWidget;
	QWidget *w3 = new QWidget;
	QWidget *w4 = new QWidget;
	QWidget *w5 = new QWidget;
	QWidget *w6 = new QWidget;
	w1->setStyleSheet(QString::fromUtf8("border:3px solid black"));
	w2->setStyleSheet(QString::fromUtf8("border:3px solid black"));
	w3->setStyleSheet(QString::fromUtf8("border:3px solid black"));
	w4->setStyleSheet(QString::fromUtf8("border:3px solid black"));
	w5->setStyleSheet(QString::fromUtf8("border:3px solid black"));
	w6->setStyleSheet(QString::fromUtf8("border:3px solid black"));
	w1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	w2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	w3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	w4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	w5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	w6->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	ui.ViewPort->addWidget(w1, 0, 0, 2, 2);
	ui.ViewPort->addWidget(w2, 0, 2);
	ui.ViewPort->addWidget(w3, 1, 2);
	ui.ViewPort->addWidget(w4, 2, 0);
	ui.ViewPort->addWidget(w5, 2, 1);
	ui.ViewPort->addWidget(w6, 2, 2);
}

//clear all the viewers in gridlayout
void CCTV::clearViewers() {
	int n = ui.ViewPort->count();
	for (int i = 1; i <= n; i++) {
		QWidget *p = ui.ViewPort->itemAt(n - i)->widget();
		ui.ViewPort->removeWidget(p);
		delete p;
	}
}

void CCTV::mousePressEvent(QMouseEvent *e) {
	if (ui.ViewPort->geometry().contains(mapFromGlobal(QCursor::pos()))) {
		for (int i = 0; i < ui.ViewPort->count(); i++) {
			if (ui.ViewPort->itemAt(i)->geometry().contains(mapFromGlobal(QCursor::pos()))) {
				//viewer found!
				ui.ViewPort->itemAt(i)->widget()->setStyleSheet(QString::fromUtf8("border:3px solid red"));
				CCTV::temp = ui.ViewPort->itemAt(i)->widget();
				CCTV::selected = true;
				break;
			}
		}
	}
}

void CCTV::mouseReleaseEvent(QMouseEvent *e) {
	if (!CCTV::selected) return; 
	for (int i = 0; i < ui.ViewPort->count(); i++) {
		if (ui.ViewPort->itemAt(i)->geometry().contains(mapFromGlobal(QCursor::pos()))) {
			//viewer found!
			//swaping
			QWidget *temp2 = ui.ViewPort->itemAt(i)->widget();
			if (ui.ViewPort->indexOf(temp) == ui.ViewPort->indexOf(temp2)) {
				CCTV::selected = false;
				temp->setStyleSheet(QString::fromUtf8("border:3px solid black"));
				return;
			}
			swap(ui.ViewPort, temp, temp2);
			return;
		}
	}
}

void CCTV::swap(QGridLayout *layout, QWidget *w1, QWidget *w2) {
	int row1, col1, rowSpan1, colSpan1;
	int row2, col2, rowSpan2, colSpan2;

	int index1 = layout->indexOf(w1);
	layout->getItemPosition(index1, &row1, &col1, &rowSpan1, &colSpan1);
	auto layoutItem1 = layout->takeAt(index1);

	int index2 = layout->indexOf(w2);
	layout->getItemPosition(index2, &row2, &col2, &rowSpan2, &colSpan2);
	auto layoutItem2 = layout->takeAt(index2);

	layout->addItem(layoutItem1, row2, col2, rowSpan2, colSpan2);
	layout->addItem(layoutItem2, row1, col1, rowSpan1, colSpan1);

	CCTV::selected = false;//swap finished
}

void CCTV::on_btn_start_clicked() {
	QString addr = "rtsp://10.0.0.5:554/living_comb01_sub.264";
	_handle = Ants_RTSPClient_Open_V2(addr.toUtf8().data(),
		ANTS_RTPTransProto_TCP,
		(0x1 << 3 | 0x1 << 4 | 0x1 << 7),
		Http_RealData_CallBack,
		"admin",
		"123456",
		this);
	if (0 >= _handle) //若打开失败
		return;

	int buf_size = 2 * 1024 * 1024;
	Ants_RTSPClient_Control(_handle, ANTS_RTSP_CONTROL_CMD_RCVBUFFSIZE, 789, (void*)(&buf_size), sizeof(buf_size), NULL, 0);
	Ants_RTSPClient_Control(_handle, ANTS_RTSP_CONTROL_CMD_START, 789, NULL, 0, NULL, 0);

	int headLen = I8_MP4Play_GetFileHeadLength();  //包头长度
	_port = I8_MP4Play_GetFreePort();  //获取空的端口
	char headBuffer[28];
	memset(headBuffer, 0, headLen);
	headBuffer[2] = 0x01;
	headBuffer[3] = 0xAA;
	headBuffer[4] = 0x03;
	headBuffer[8] = 0x19;

	I8_MP4Play_SetStreamOpenMode(_port, I8_STREAME_REALTIME);	//设置播放流模式  
																//I8_STREAME_REALTIME	0x2		!实时解码，适合板卡生成的实时数据流，默认值

	I8_MP4Play_ResetSourceBuffer(_port);
	I8_MP4Play_OpenStream(_port, (PBYTE)headBuffer, headLen, 1024 * 1024); 		//开启播放流,回放缓冲区1M

	I8_MP4Play_Play(_port, (HWND)ui.ViewPort->itemAt(0)->widget()->winId());
}


void CCTV::output(QString context) {
	emit sig_output(context);
}

void CCTV::on_output(QString context) {
	//QString plainText = ui.output->toPlainText();
	//if (plainText.count("\r\n") >= 200) {
	//	plainText = plainText.right(plainText.indexOf("\r\n") + 1);
	//}

	//ui.output->setPlainText(plainText + context + "\r\n");

	//ui.output->moveCursor(QTextCursor::End);

	//QTextCursor cursor(ui.output->textCursor());
	//cursor.movePosition(QTextCursor::End);
	//cursor.insertText(context + "\r\n");
	//ui.output->moveCursor(QTextCursor::End);
}


void Hello() {

}