#ifndef CCTV_H
#define CCTV_H

#include <QtWidgets/QMainWindow>
#include "ui_cctv.h"
#include "rtspclient_api.h"

class CCTV : public QMainWindow
{
	Q_OBJECT

		signals :
	void sig_output(QString context);
public:
	CCTV(QWidget *parent = 0);
	~CCTV();

	bool selected = false;
	QWidget *temp;

	void output(QString context);
	int _port;

private:
	Ui::CCTVClass ui;
	int _handle;
	void clearViewers();
	void swap(QGridLayout *layout, QWidget *w1, QWidget *w2);
	

protected:
	//void enterEvent(QMouseEvent *e);
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);


private slots:
	void four();
	void nine();
	void six();

	void on_btn_start_clicked();
	void on_output(QString context);

};

#endif // CCTV_H
