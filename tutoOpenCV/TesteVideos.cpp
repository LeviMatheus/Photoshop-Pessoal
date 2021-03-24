#include "TesteVideos.h"
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <stdio.h>

using namespace cv;
using namespace std;

#define COLOR_ROWS 80
#define COLOR_COLS 250

bool clicou;
Mat colorArray;
Mat printTela;
int b, g, r;
int tamBloco = 1;
Mat src, dst, imgBinarizada, imgLaplace;
bool primeiroLoop = true;


void LaplaceEBinarizacao(Mat modificado) {
    cvtColor(modificado, imgBinarizada, COLOR_BGR2GRAY);//Deixando em preto e branco
    imshow("Binarizada", imgBinarizada);
    Laplacian(imgBinarizada, imgLaplace, imgBinarizada.depth(), 3, 1, 0, BORDER_REPLICATE);
    Mat abs_img;
    convertScaleAbs(imgLaplace, abs_img);
    imshow("Laplace", abs_img);
}

void aplicarBlur(int, void*) {
    blur(src, dst, Size(3 + tamBloco, 3 + tamBloco), Point(-1, -1));
    imshow("Imagem", dst);
    LaplaceEBinarizacao(dst);
}

void aplicarGaussianBlur(int, void*) {
    GaussianBlur(src, dst, Size(3 + tamBloco * 2, 3 + tamBloco * 2), 0, 0);
    imshow("Imagem", dst);
    LaplaceEBinarizacao(dst);
}

void aplicarMedianBlur(int, void*) {
    medianBlur(src, dst, 1 + tamBloco * 2);
    imshow("Imagem", dst);
    LaplaceEBinarizacao(dst);
}

void aplicarBilateralFilter(int, void*) {
    try {
        bilateralFilter(src, dst, tamBloco, tamBloco * 2, tamBloco / 2);
        LaplaceEBinarizacao(dst);
    }
    catch (std::exception& ex) {
        string excp = ex.what();
        System::String^ texto = gcnew System::String(excp.c_str());
        System::Windows::Forms::MessageBox::Show("Ocorreu um erro: " + texto);
    }
    
    imshow("Imagem", dst);
}

void onMouse(int event, int x, int y, int flags, void* userdata) {
    if (event == EVENT_LBUTTONDOWN) {
        //System::Windows::Forms::MessageBox::Show("Clique uma vez para habilitar o colorpicker");
        Vec3b cores = (Vec3b)printTela.at<cv::Vec3b>(y, x);
        //System::Windows::Forms::MessageBox::Show("B: " + ((int)cores[0]).ToString() + ", G: " + (int)cores[1] + ", R: " + (int)cores[2]);
        b = (int)cores[0];
        g = (int)cores[1];
        r = (int)cores[2];
        std::string rgbText = "[" + std::to_string(r) + ", " + std::to_string(g)
            + ", " + std::to_string(b) + "]";

        float luminance = 1 - (0.299 * r + 0.587 * g + 0.114 * b) / 255;
        cv::Scalar textColor;

        if (luminance < 0.5)
            textColor = cv::Scalar(0, 0, 0);
        else
            textColor = cv::Scalar(255, 255, 255);

        cv::Mat colorArray;
        colorArray = cv::Mat(COLOR_ROWS, COLOR_COLS, CV_8UC3, cv::Scalar(b, g, r));
        cv::putText(colorArray, rgbText, cv::Point2d(20, COLOR_ROWS - 20),
            cv::FONT_HERSHEY_SIMPLEX, 0.8, textColor);
        cv::imshow("RGB-Cores", colorArray);
    }
}

void TesteVideos::TracksEFiltros(cv::String winName) {
    createTrackbar("Blur", winName, &tamBloco, 50, aplicarBlur);
    createTrackbar("Gaussian", winName, &tamBloco, 50, aplicarGaussianBlur);
    createTrackbar("Median", winName, &tamBloco, 1, aplicarMedianBlur);
    createTrackbar("Bilateral", winName, &tamBloco, 50, aplicarBilateralFilter);
}

int TesteVideos::abrirCamera()
{
    System::Windows::Forms::MessageBox::Show("Aperte espaço para capturar a imagem");
    Mat frame;
    //--- inicializar a captura
    VideoCapture cap;
    // abre a camera usando a api padrao
    // cap.open(0);
    int deviceID = 0;             // 0 = dispositivo de camera padrao
    int apiID = cv::CAP_ANY;      // 0 = detecta API padrao
    // abre a camera com a api padrao
    cap.open(deviceID, apiID);
    // ver se deu certo
    if (!cap.isOpened()) {
        cerr << "Vish deu erro ao abrir a camera \n";
        return -1;
    }
    else {
        for (;;)
        {
            // espera pelo frame da camera e guarda no buffer
            cap.read(frame);
            // se der certo blz
            if (frame.empty()) {
                cerr << "Erro o frame ficou doido, deve estar usando UDP kkk \n";
                break;
            }
            // mostra a camera e espera por teclas
            imshow("Live", frame);

            if (waitKey(5) == 32) {//trava a imagem com SPACE tipo um screenshot
                cv::destroyWindow("Live");
                //imshow("captura", frame);
                //imwrite("captura", frame);
                salvamostra(frame, 1);
                //criar trackbar e habilitar os filtros
                src = imread("Imagem.jpg");
                TracksEFiltros("Imagem");
                //System::Windows::Forms::MessageBox::Show("Tela capturada");
                //colorArray = Mat(COLOR_ROWS, COLOR_COLS, CV_8UC3, cv::Scalar(0, 0, 0));
                //namedWindow("Color");
                //imshow("Color", colorArray);
                break;
            }
            //setMouseCallback("captura", onMouse, 0);
        }
    }

    return 0;
}

void TesteVideos::salvamostra(cv::Mat img, int op)
{
    /*if (op == 0) {//mostrar e salvar comum (operacao 0)
        imshow("Imagem", img);
        imwrite("Imagem.jpg", img);
    }
    else {//mostrar,salvar e passar como parametro para o callback
        printTela = img;
        imshow("Imagem", img);
        imwrite("Imagem.jpg", img);
        setMouseCallback("Imagem", onMouse, &img);
    }*/
    System::Windows::Forms::MessageBox::Show("Clique em um local da imagem para mostrar a cor");
    printTela = img;
    imshow("Imagem", img);
    imwrite("Imagem.jpg", img);
    setMouseCallback("Imagem", onMouse, &img);
}


