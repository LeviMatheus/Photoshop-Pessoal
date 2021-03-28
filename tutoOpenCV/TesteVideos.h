#pragma once
#include <string>
#include <opencv2/opencv.hpp>

public class TesteVideos
{
public: int abrirCamera();
//public: cv::MouseCallback onMouse(int event, int x, int y, int flags, void* userdata);
public: void salvamostra(cv::Mat img, int op);
public: void SalvarImg(cv::Mat img);
public: void MostrarImg(cv::Mat img);
public: void LerImg();
public: void TracksEFiltros(cv::String winName, int tipo);
public: void passaAlta(int tipo);
public: void MatToImg(cv::Mat img);
public: cv::Mat modificando;
};

