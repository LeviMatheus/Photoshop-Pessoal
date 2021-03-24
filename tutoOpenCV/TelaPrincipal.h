#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <windows.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vcclr.h>
#include <msclr\marshal_cppstd.h>
#include "TesteVideos.h"

namespace AulasPDI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std;
	using namespace cv;
	using std::string;
	using std::getline;
	using std::cout;
	using std::cout;
	using std::cin;
	using std::endl;

	/// <summary>
	/// Sumário para TelaPrincipal
	/// </summary>
	Mat original = imread("lena.jpg");
	Mat histograma(256, 256, CV_8U, Scalar(255));
	Mat img;
	int mouseX, mouseY;

	public ref class TelaPrincipal : public System::Windows::Forms::Form
	{
	public:
		TelaPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
			
		}
		

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~TelaPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:


	private: System::Windows::Forms::ToolStripMenuItem^  imagemmenu;
	private: TesteVideos *testeVideos;










	private: System::Windows::Forms::OpenFileDialog^ ofd1;
	private: System::Windows::Forms::ToolStripMenuItem^ resoTool;
	private: System::Windows::Forms::ToolStripMenuItem^ nomeTool;
	private: System::Windows::Forms::ToolStripMenuItem^ xYZToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ hSVToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ hSLToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ lUVToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ lABToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ yCRCBToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolMouse;
	private: System::Windows::Forms::ToolStrip^ toolBotoes;
	private: System::Windows::Forms::ToolStripButton^ btCamera;
	private: System::Windows::Forms::ToolStripButton^ btImagem;
	private: System::Windows::Forms::ToolStripButton^ btCanais;
















	protected:

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->imagemmenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->xYZToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hSVToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hSLToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lUVToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lABToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->yCRCBToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nomeTool = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->resoTool = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolMouse = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ofd1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->toolBotoes = (gcnew System::Windows::Forms::ToolStrip());
			this->btCamera = (gcnew System::Windows::Forms::ToolStripButton());
			this->btImagem = (gcnew System::Windows::Forms::ToolStripButton());
			this->btCanais = (gcnew System::Windows::Forms::ToolStripButton());
			this->menuStrip1->SuspendLayout();
			this->toolBotoes->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->imagemmenu, this->nomeTool,
					this->resoTool, this->toolMouse
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 371);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(602, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// imagemmenu
			// 
			this->imagemmenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->xYZToolStripMenuItem1,
					this->hSVToolStripMenuItem1, this->hSLToolStripMenuItem1, this->lUVToolStripMenuItem1, this->lABToolStripMenuItem1, this->yCRCBToolStripMenuItem1
			});
			this->imagemmenu->Name = L"imagemmenu";
			this->imagemmenu->Size = System::Drawing::Size(54, 20);
			this->imagemmenu->Text = L"Canais";
			// 
			// xYZToolStripMenuItem1
			// 
			this->xYZToolStripMenuItem1->Name = L"xYZToolStripMenuItem1";
			this->xYZToolStripMenuItem1->Size = System::Drawing::Size(180, 22);
			this->xYZToolStripMenuItem1->Text = L"XYZ";
			this->xYZToolStripMenuItem1->Click += gcnew System::EventHandler(this, &TelaPrincipal::xYZToolStripMenuItem1_Click);
			// 
			// hSVToolStripMenuItem1
			// 
			this->hSVToolStripMenuItem1->Name = L"hSVToolStripMenuItem1";
			this->hSVToolStripMenuItem1->Size = System::Drawing::Size(180, 22);
			this->hSVToolStripMenuItem1->Text = L"HSV";
			this->hSVToolStripMenuItem1->Click += gcnew System::EventHandler(this, &TelaPrincipal::hSVToolStripMenuItem1_Click);
			// 
			// hSLToolStripMenuItem1
			// 
			this->hSLToolStripMenuItem1->Name = L"hSLToolStripMenuItem1";
			this->hSLToolStripMenuItem1->Size = System::Drawing::Size(180, 22);
			this->hSLToolStripMenuItem1->Text = L"HLS";
			this->hSLToolStripMenuItem1->Click += gcnew System::EventHandler(this, &TelaPrincipal::hSLToolStripMenuItem1_Click);
			// 
			// lUVToolStripMenuItem1
			// 
			this->lUVToolStripMenuItem1->Name = L"lUVToolStripMenuItem1";
			this->lUVToolStripMenuItem1->Size = System::Drawing::Size(180, 22);
			this->lUVToolStripMenuItem1->Text = L"LUV";
			this->lUVToolStripMenuItem1->Click += gcnew System::EventHandler(this, &TelaPrincipal::lUVToolStripMenuItem1_Click);
			// 
			// lABToolStripMenuItem1
			// 
			this->lABToolStripMenuItem1->Name = L"lABToolStripMenuItem1";
			this->lABToolStripMenuItem1->Size = System::Drawing::Size(180, 22);
			this->lABToolStripMenuItem1->Text = L"LAB";
			this->lABToolStripMenuItem1->Click += gcnew System::EventHandler(this, &TelaPrincipal::lABToolStripMenuItem1_Click);
			// 
			// yCRCBToolStripMenuItem1
			// 
			this->yCRCBToolStripMenuItem1->Name = L"yCRCBToolStripMenuItem1";
			this->yCRCBToolStripMenuItem1->Size = System::Drawing::Size(180, 22);
			this->yCRCBToolStripMenuItem1->Text = L"YCRCB";
			this->yCRCBToolStripMenuItem1->Click += gcnew System::EventHandler(this, &TelaPrincipal::yCRCBToolStripMenuItem1_Click);
			// 
			// nomeTool
			// 
			this->nomeTool->Name = L"nomeTool";
			this->nomeTool->Size = System::Drawing::Size(115, 20);
			this->nomeTool->Text = L"Nome da imagem";
			this->nomeTool->Visible = false;
			// 
			// resoTool
			// 
			this->resoTool->Name = L"resoTool";
			this->resoTool->Size = System::Drawing::Size(139, 20);
			this->resoTool->Text = L"Resolução da imagem:";
			this->resoTool->Visible = false;
			// 
			// toolMouse
			// 
			this->toolMouse->Name = L"toolMouse";
			this->toolMouse->Size = System::Drawing::Size(55, 20);
			this->toolMouse->Text = L"Mouse";
			this->toolMouse->Visible = false;
			// 
			// ofd1
			// 
			this->ofd1->FileName = L"openFileDialog1";
			this->ofd1->Filter = L"Image Files(*.BMP;*.JPG;*.GIF;*.PNG)|*.BMP;*.JPG;*.GIF;*.PNG";
			// 
			// toolBotoes
			// 
			this->toolBotoes->GripStyle = System::Windows::Forms::ToolStripGripStyle::Hidden;
			this->toolBotoes->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->btCamera, this->btImagem,
					this->btCanais
			});
			this->toolBotoes->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::Flow;
			this->toolBotoes->Location = System::Drawing::Point(0, 0);
			this->toolBotoes->Name = L"toolBotoes";
			this->toolBotoes->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->toolBotoes->Size = System::Drawing::Size(602, 22);
			this->toolBotoes->TabIndex = 2;
			// 
			// btCamera
			// 
			this->btCamera->Name = L"btCamera";
			this->btCamera->Size = System::Drawing::Size(52, 19);
			this->btCamera->Text = L"Camera";
			this->btCamera->TextImageRelation = System::Windows::Forms::TextImageRelation::Overlay;
			this->btCamera->ToolTipText = L"Abrir Camera";
			this->btCamera->Click += gcnew System::EventHandler(this, &TelaPrincipal::btCamera_Click);
			// 
			// btImagem
			// 
			this->btImagem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btImagem->Name = L"btImagem";
			this->btImagem->Size = System::Drawing::Size(55, 19);
			this->btImagem->Text = L"Imagem";
			this->btImagem->TextImageRelation = System::Windows::Forms::TextImageRelation::Overlay;
			this->btImagem->ToolTipText = L"Abrir imagem";
			this->btImagem->Click += gcnew System::EventHandler(this, &TelaPrincipal::btImagem_Click);
			// 
			// btCanais
			// 
			this->btCanais->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btCanais->Name = L"btCanais";
			this->btCanais->Size = System::Drawing::Size(46, 19);
			this->btCanais->Text = L"Canais";
			this->btCanais->TextImageRelation = System::Windows::Forms::TextImageRelation::Overlay;
			this->btCanais->ToolTipText = L"Conversão de canais";
			// 
			// TelaPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(602, 395);
			this->Controls->Add(this->toolBotoes);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"TelaPrincipal";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MeuPS";
			this->Load += gcnew System::EventHandler(this, &TelaPrincipal::TelaPrincipal_Load);
			this->MouseHover += gcnew System::EventHandler(this, &TelaPrincipal::TelaPrincipal_MouseHover);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &TelaPrincipal::TelaPrincipal_MouseMove);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolBotoes->ResumeLayout(false);
			this->toolBotoes->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void TelaPrincipal_Load(System::Object^  sender, System::EventArgs^  e) {
		testeVideos = new TesteVideos();
		
		//Carregar icones do projeto
		btCamera->Text = "";
		btCamera->Image = Image::FromFile("icones/camera.png");
		btImagem->Text = "";
		btImagem->Image = Image::FromFile("icones/imagem.png");
		btCanais->Text = "";
		btCanais->Image = Image::FromFile("icones/canais.png");

		//Texto de boas vindas e dicas
		/*System::Windows::Forms::MessageBox::Show("Bem vindo ao meu editor ! " +
		"Para acessar histogramas e filtros de canais selecione Canais->algum dos métodos" + 
			" e veja a imagem da Lena convertida, ou abra uma imagem desejada e então converta. " +
		"Para acessar filtros de passa baixa/alta, binarização e laplace clique no icone de câmera abaixo" +
		" e captura uma imagem utilizando espaço.");*/
	}



	public: MatND geraHistograma(const Mat imagem, Mat* Histograma) {
		MatND hist;
		int channels[] = { 0, 1 };
		int histSize[1];
		float hranges[2] = { 0, 255 };
		const float* ranges[1];
		double maxVal = 0, minVal = 0;
		ranges[0] = hranges;

		histSize[0] = 256;
		calcHist(&imagem, 1, channels, Mat(), hist, 1, histSize, ranges);
		minMaxLoc(hist, &minVal, &maxVal, 0, 0);
		int hpt = static_cast<int>(0.9 * histSize[0]);
		for (int h = 0; h < histSize[0]; h++) {
			float binVal = hist.at<float>(h);
			int intensity = static_cast<int>(binVal * hpt / maxVal);
			line(*Histograma, cv::Point(h, histSize[0]),
				cv::Point(h, histSize[0] - intensity),
				Scalar::all(0));
		}
		return hist;
	}

	private: System::Void Converter() {
		Mat canais[3];
		split(img, canais);
		//imshow("Imagem", img); //imagem convertida pode ser mostrada na tela principal
		testeVideos->salvamostra(img, 0);
		//imwrite("Imagem.jpg", img);//salva a  imagem
		//abaixo atualizando fundo para a imagem convertida
		//Image^ imgGerada = Image::FromFile("Imagem.jpg");
		//TelaPrincipal::BackgroundImage = imgGerada;

		imshow("Canal 0", canais[0]);
		imwrite("Img-Canal0.png", canais[0]);
		imshow("Canal 1", canais[1]);
		imwrite("Img-Canal1.png", canais[1]);
		imshow("Canal 2", canais[2]);
		imwrite("Img-Canal2.png", canais[2]);
		for (int c = 0; c < 3; c++) {//para cada canal faca
			MatND gHist = geraHistograma(canais[c], &histograma);
			System::String^ textoForm = System::String::Concat("H-Canal ", c);
			std::string textJanela = msclr::interop::marshal_as<std::string>(textoForm);
			imshow(textJanela, histograma);
			imwrite(textJanela + ".jpg", histograma);
		}
		//salvar imagens
		System::Windows::Forms::MessageBox::Show("Imagens convertidas salvas na pasta do projeto");
	}

	private: System::Void xYZToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		cvtColor(original, img, COLOR_BGR2XYZ);
		TelaPrincipal::Converter();
	}

	private: System::Void TelaPrincipal_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		toolMouse->Visible = true;
		toolMouse->Text = "Mouse em X: " + e->Location.X.ToString() + " Y-" + e->Location.Y.ToString();
	}

	private: System::Void TelaPrincipal::TelaPrincipal_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void TelaPrincipal::abrirImagemToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (TelaPrincipal::ofd1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			char* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(TelaPrincipal::ofd1->FileName);
			TelaPrincipal::nomeTool->Visible = true;
			TelaPrincipal::nomeTool->Text = TelaPrincipal::ofd1->FileName;
			original = imread(str2);
			System::Windows::Forms::MessageBox::Show("Imagem carregada");
			Image^ imgFundo = Image::FromFile(TelaPrincipal::ofd1->FileName);
			//TelaPrincipal::BackgroundImage = Image::FromFile(TelaPrincipal::ofd1->FileName);
			TelaPrincipal::BackgroundImage = imgFundo;
			int iWidth = imgFundo->Width;
			int iHeight = imgFundo->Height;
			TelaPrincipal::resoTool->Text = "Width: " + iWidth.ToString() + " Height: " + iHeight.ToString();
			TelaPrincipal::resoTool->Visible = true;
			TelaPrincipal::Width = iWidth;
			TelaPrincipal::Height = iHeight;
		}
		else {
			System::Windows::Forms::MessageBox::Show("Operação cancelada");
		}
	}

	private: System::Void arquivoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}

	private: System::Void xYZToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		cvtColor(original, img, COLOR_BGR2XYZ);
		TelaPrincipal::Converter();
	}

	private: System::Void hSVToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		cvtColor(original, img, COLOR_BGR2HSV);
		TelaPrincipal::Converter();
	}

	private: System::Void hSLToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		cvtColor(original, img, COLOR_BGR2HLS);
		TelaPrincipal::Converter();
	}

	private: System::Void lUVToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		cvtColor(original, img, COLOR_BGR2Luv);
		TelaPrincipal::Converter();
	}

	private: System::Void lABToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		cvtColor(original, img, COLOR_BGR2Lab);
		TelaPrincipal::Converter();
	}

	private: System::Void yCRCBToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		cvtColor(original, img, COLOR_BGR2YCrCb);
		TelaPrincipal::Converter();
	}

	private: System::Void btCamera_Click(System::Object^ sender, System::EventArgs^ e) {
		testeVideos->abrirCamera();
	}

	private: System::Void btImagem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (TelaPrincipal::ofd1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			char* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(TelaPrincipal::ofd1->FileName);
			TelaPrincipal::nomeTool->Visible = true;
			TelaPrincipal::nomeTool->Text = TelaPrincipal::ofd1->FileName;
			original = imread(str2);
			System::Windows::Forms::MessageBox::Show("Imagem carregada");
			Image^ imgFundo = Image::FromFile(TelaPrincipal::ofd1->FileName);
			//TelaPrincipal::BackgroundImage = Image::FromFile(TelaPrincipal::ofd1->FileName);
			TelaPrincipal::BackgroundImage = imgFundo;
			int iWidth = imgFundo->Width;
			int iHeight = imgFundo->Height;
			TelaPrincipal::resoTool->Text = "Width: " + iWidth.ToString() + " Height: " + iHeight.ToString();
			TelaPrincipal::resoTool->Visible = true;
			TelaPrincipal::Width = iWidth;
			TelaPrincipal::Height = iHeight;
		}
		else {
			System::Windows::Forms::MessageBox::Show("Operação cancelada");
		}
	}
};
}
