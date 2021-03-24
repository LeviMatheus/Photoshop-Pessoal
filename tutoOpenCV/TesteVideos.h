#pragma once
#include <string>
#include <opencv2/opencv.hpp>

public class TesteVideos
{
public: int abrirCamera();
//public: cv::MouseCallback onMouse(int event, int x, int y, int flags, void* userdata);
public: void salvamostra(cv::Mat img, int op);
public: void TracksEFiltros(cv::String winName);
};

