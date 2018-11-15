#include "dialog.h"
#include "ui_dialog.h"


void Dialog::numberofframes()
{
	QString klatki = QString("Frame #%1").arg(QString::number(counter));
	ui->frame_counter->setText(klatki);
}

void Dialog::kamerka()
{

	capWebcam.read(image);
	cvtColor(image, image, CV_BGR2RGB);
	counter++;
	numberofframes();
	QImage qimg((uchar*)image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);

	ui->display_screen->setPixmap(QPixmap::fromImage(qimg));

	QString klatki = QString("Frames: %1").arg(QString::number(counter));




}


/*
void Dialog::processFrameAndUpdateGUI()
{

	cvtColor(image, image2, CV_BGR2GRAY);
	cvtColor(image, e, CV_BGR2RGB);
	equalizeHist(image2, image2);
	
	d1.detectMultiScale(image2, znaki, 1.02, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(40, 40));
	//cvtColor(frameROI, frameROI, CV_BGR2GRAY);
	
	QString napis= QString("Frame #%1").arg(QString::number(counter));
	
	
	for (size_t i = 0; i < znaki.size(); i++)
	{
		Point pt1(znaki[i].x + znaki[i].width, znaki[i].y + znaki[i].height);
		Point pt2(znaki[i].x, znaki[i].y);
		

		
		frameROI = e(znaki[i]);
		cvtColor(frameROI, frameROI, CV_BGR2RGB);
		//frameROI.copyTo(sign);

		int result = svm_predict(frameROI);

		if ((result < 6) || (result > 6))
		{

			QImage qimg((uchar*)frameROI.data, frameROI.cols, frameROI.rows, frameROI.step, QImage::Format_RGB888);


			QTableWidgetItem *svmr = new QTableWidgetItem;
			QTableWidgetItem *numer_klatki = new QTableWidgetItem;
			QTableWidgetItem *item = new QTableWidgetItem;
			item->setData(Qt::DecorationRole, QPixmap::fromImage(qimg).scaled(100, 100));
			numer_klatki->setData(0, QString(napis));
			ui->tableWidget->setRowCount(znaki.size());
			ui->tableWidget->setColumnCount(3);
			ui->tableWidget->setItem(i, 0, numer_klatki);


			switch (result)
			{
			case 1:
				svmr->setData(Qt::DecorationRole, QPixmap("c-2.jpg").scaled(100, 100));
				break;
			case 2:
				svmr->setData(Qt::DecorationRole, QPixmap("c-4.jpg").scaled(100, 100));
				break;
			case 3:
				svmr->setData(Qt::DecorationRole, QPixmap("c-5.jpg").scaled(100, 100));
				break;
			case 4:
				svmr->setData(Qt::DecorationRole, QPixmap("c-1.jpg").scaled(100, 100));
				break;
			case 5:
				svmr->setData(Qt::DecorationRole, QPixmap("c-3.jpg").scaled(100, 100));
				break;
			case 7:
				svmr->setData(Qt::DecorationRole, QPixmap("c-12.jpg").scaled(100, 100));
				break;
			
			default:
				break;
			}
			svmr->setData(0, QString::number(result));
			svmr->setTextAlignment(Qt::AlignCenter);
			ui->tableWidget->setItem(i, 2, svmr);

			ui->tableWidget->setItem(i, 1, item);
			ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
			ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
			//waitKey(1000);

		}
		//waitKey(1000);
		
		//namedWindow("", 0);
		//imshow("", image2(znaki[i]));
	}
	
	
	



}*/


int Dialog::svm_predict(Mat &image)
{
	Size size(50, 50);//the dst image size,e.g.100x100
	Mat SUV_image;//dst image

	cv::resize(image, SUV_image, size);//resize image
	cvtColor(SUV_image, SUV_image, CV_BGR2GRAY);
	GaussianBlur(SUV_image, SUV_image, Size(3, 3), 0, 0);
	namedWindow("", CV_WINDOW_AUTOSIZE);
	imshow("", SUV_image);
	int img_area = 50 * 50;

	Mat test_image(1, img_area, CV_32FC1);        //Creates a 1 x 30000 matrix to house the test image. 


	int jj = 0;
	for (int i = 0; i < SUV_image.rows; i++)
	{
		for (int j = 0; j < SUV_image.cols; j++)
		{
			test_image.at<float>(0, jj) = SUV_image.at<uchar>(i, j);    //Fills the training_mat
			jj++;
		}
	}


	int result = svm.predict(test_image);

	return result;
}

void Dialog::processFrameAndUpdateGUI()
{
	float erosion_size = 0.5;
	Mat element = getStructuringElement(MORPH_RECT,
		Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		Point(erosion_size, erosion_size));
	cvtColor(image, image2, CV_BGR2GRAY);
	cvtColor(image, e, CV_BGR2RGB);
	equalizeHist(image2, image2);

	d1.detectMultiScale(image2, znaki1, 1.1, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(40, 40));
	d2.detectMultiScale(image2, znaki2, 1.1, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(40, 40));
	//d3.detectMultiScale(image2, znaki3, 1.02, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(40, 40));
	d4.detectMultiScale(image2, znaki4, 1.1, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(40, 40));
	//d5.detectMultiScale(image2, znaki5, 1.02, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(40, 40));
	//d6.detectMultiScale(image2, znaki, 1.02, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(40, 40));
	QString napis = QString("Frame #%1").arg(QString::number(counter));
	//cvtColor(frameROI, frameROI, CV_BGR2GRAY);
	int x = 0;
	ostringstream convert;
	
	ui->tableWidget->setRowCount(10);
	ui->tableWidget->setColumnCount(3);
	
	
	
	for (size_t i = 0; i < znaki1.size(); i++)
	{
		Point pt1(znaki1[i].x + znaki1[i].width, znaki1[i].y + znaki1[i].height);
		Point pt2(znaki1[i].x, znaki1[i].y);
		frameROI1 = e(znaki1[i]);

		//cvtColor(frameROI1, frameROI1, CV_BGR2RGB);
		convert <<"pliki/"<< counter << ".jpg";
		imwrite(convert.str().c_str(), frameROI1);

		//equalizeHist(frameROI1, frameROI1);
		medianBlur(frameROI1, frameROI1, 3);
		threshold(frameROI1, frameROI1, 120, 120, THRESH_BINARY);
		erode(frameROI1, frameROI1, element);

		int result1 = svm_predict(frameROI1);
			QImage qimg((uchar*)frameROI1.data, frameROI1.cols, frameROI1.rows, frameROI1.step, QImage::Format_RGB888);


			QTableWidgetItem *svmr = new QTableWidgetItem;
			QTableWidgetItem *numer_klatki = new QTableWidgetItem;
			QTableWidgetItem *item = new QTableWidgetItem;
			item->setData(Qt::DecorationRole, QPixmap::fromImage(qimg).scaled(100, 100));
			numer_klatki->setData(0, QString(napis));

			ui->tableWidget->setItem(x, 0, numer_klatki);


			switch (result1)
			{
			case 1:
				svmr->setData(Qt::DecorationRole, QPixmap("obrazy/x5.jpg").scaled(100, 100));
				QSound::play("dzwieki/5.wav");
				break;
			case 2:
				svmr->setData(Qt::DecorationRole, QPixmap("obrazy/x10.jpg").scaled(100, 100));
				QSound::play("dzwieki/10.wav");
				break;
			case 3:
				svmr->setData(Qt::DecorationRole, QPixmap("obrazy/x20.jpg").scaled(100, 100));
				QSound::play("dzwieki/20.wav");
				break;
			case 4:
				svmr->setData(Qt::DecorationRole, QPixmap("obrazy/x30.jpg").scaled(100, 100));
				QSound::play("dzwieki/30.wav");
				break;
			case 5:
				svmr->setData(Qt::DecorationRole, QPixmap("obrazy/x40.jpg").scaled(100, 100));
				QSound::play("dzwieki/40.wav");
				break;
			case 6:
				svmr->setData(Qt::DecorationRole, QPixmap("obrazy/x50.jpg").scaled(100, 100));
				QSound::play("dzwieki/50.wav");
				break;
			case 7:
				svmr->setData(Qt::DecorationRole, QPixmap("obrazy/x60.jpg").scaled(100, 100));
				QSound::play("dzwieki/60.wav");
				break;
			case 8:
				svmr->setData(Qt::DecorationRole, QPixmap("obrazy/x70.jpg").scaled(100, 100));
				QSound::play("dzwieki/70.wav");
				break;
			case 9:
				svmr->setData(Qt::DecorationRole, QPixmap("obrazy/x80.jpg").scaled(100, 100));
				QSound::play("dzwieki/80.wav");
				break;
			case -1:
				svmr->setData(Qt::DecorationRole, QPixmap("obrazy/x90.jpg").scaled(100, 100));
				QSound::play("dzwieki/90.wav");
				break;
			case -2:
				svmr->setData(Qt::DecorationRole, QPixmap("obrazy/x100.jpg").scaled(100, 100));
				QSound::play("dzwieki/100.wav");
				break;
			case -3:
				svmr->setData(Qt::DecorationRole, QPixmap("obrazy/x110.jpg").scaled(100, 100));
				QSound::play("dzwieki/110.wav");
				break;
			case -4:
				svmr->setData(Qt::DecorationRole, QPixmap("obrazy/x120.jpg").scaled(100, 100));
				QSound::play("dzwieki/120.wav");
				break;

			default:
				break;
			}

			svmr->setTextAlignment(Qt::AlignCenter);
			ui->tableWidget->setItem(x, 2, svmr);

			ui->tableWidget->setItem(x, 1, item);
			ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
			ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
			x++;
			waitKey(3000);
			
	}

	for (size_t i = 0; i < znaki2.size(); i++)
	{
		Point pt1(znaki2[i].x + znaki2[i].width, znaki2[i].y + znaki2[i].height);
		Point pt2(znaki2[i].x, znaki2[i].y);
		frameROI2 = e(znaki2[i]);
		cvtColor(frameROI2, frameROI2, CV_BGR2RGB);
		int result2 = svm_predict(frameROI2);



		QImage qimg((uchar*)frameROI2.data, frameROI2.cols, frameROI2.rows, frameROI2.step, QImage::Format_RGB888);


		QTableWidgetItem *svmr = new QTableWidgetItem;
		QTableWidgetItem *numer_klatki = new QTableWidgetItem;
		QTableWidgetItem *item = new QTableWidgetItem;
		item->setData(Qt::DecorationRole, QPixmap::fromImage(qimg).scaled(100, 100));
		numer_klatki->setData(0, QString(napis));

		ui->tableWidget->setItem(x, 0, numer_klatki);


		switch (result2)
		{

		case -5:
			svmr->setData(Qt::DecorationRole, QPixmap("obrazy/strefa.jpg").scaled(100, 100));
			QSound::play("dzwieki/strefa.wav");
			break;
		default:
			break;
		}


		svmr->setTextAlignment(Qt::AlignCenter);
		ui->tableWidget->setItem(x, 2, svmr);

		ui->tableWidget->setItem(x, 1, item);
		ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
		ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
		x++;
		waitKey(3000);
	}


		for (size_t i = 0; i < znaki4.size(); i++)
		{
			Point pt1(znaki4[i].x + znaki4[i].width, znaki4[i].y + znaki4[i].height);
			Point pt2(znaki4[i].x, znaki4[i].y);
			frameROI4 = e(znaki4[i]);
			cvtColor(frameROI4, frameROI4, CV_BGR2RGB);
			int result4 = svm_predict(frameROI4);

			

				QImage qimg((uchar*)frameROI4.data, frameROI4.cols, frameROI4.rows, frameROI4.step, QImage::Format_RGB888);


				QTableWidgetItem *svmr = new QTableWidgetItem;
				QTableWidgetItem *numer_klatki = new QTableWidgetItem;
				QTableWidgetItem *item = new QTableWidgetItem;
				item->setData(Qt::DecorationRole, QPixmap::fromImage(qimg).scaled(100, 100));
				numer_klatki->setData(0, QString(napis));

				ui->tableWidget->setItem(x, 0, numer_klatki);


				switch (result4)
				{

				case -5:
					svmr->setData(Qt::DecorationRole, QPixmap("obrazy/d6.jpg").scaled(100, 100));
					QSound::play("dzwieki/d6.wav");
					break;
				default:
					break;
				}
				

				svmr->setTextAlignment(Qt::AlignCenter);
				ui->tableWidget->setItem(x, 2, svmr);

				ui->tableWidget->setItem(x, 1, item);
				ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
				ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
				x++;
				waitKey(3000);
			}

	}
	

