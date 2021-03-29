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
	Mat histImagem(256, 256, CV_8U, Scalar(255));
	//Mat modificando;
	Mat backupImage;
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



	private: TesteVideos *testeVideos;










	private: System::Windows::Forms::OpenFileDialog^ ofd1;
	private: System::Windows::Forms::ToolStripMenuItem^ resoTool;
	private: System::Windows::Forms::ToolStripMenuItem^ nomeTool;






	private: System::Windows::Forms::ToolStripMenuItem^ toolMouse;
	private: System::Windows::Forms::ToolStrip^ toolBotoes;
	private: System::Windows::Forms::ToolStripButton^ btCamera;
	private: System::Windows::Forms::ToolStripButton^ btImagem;
	private: System::Windows::Forms::ToolStripDropDownButton^ btCanais;
	private: System::Windows::Forms::ToolStripMenuItem^ xYZToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ hSVToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ hSLToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ lUVToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ lABToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ yCRCBToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ grayscaleToolStripMenuItem;





	private: System::Windows::Forms::ToolStripDropDownButton^ btFBlur;
	private: System::Windows::Forms::ToolStripMenuItem^ btFB1;
	private: System::Windows::Forms::ToolStripMenuItem^ btFB2;
	private: System::Windows::Forms::ToolStripMenuItem^ btFB3;
	private: System::Windows::Forms::ToolStripMenuItem^ btFB4;
	private: System::Windows::Forms::ToolStripButton^ btHistograma;
	private: System::Windows::Forms::ToolStripButton^ btReabrir;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^ btRestaurar;
	private: System::Windows::Forms::ToolStripDropDownButton^ btPassaAlta;
	private: System::Windows::Forms::ToolStripMenuItem^ btLaplace;
	public: System::Windows::Forms::ListBox^ listHistórico;
	private:

	private: System::Windows::Forms::ToolStripButton^ btHistorico;
	private: System::Windows::Forms::ToolStripDropDownButton^ btAlgebricas;
	private: System::Windows::Forms::ToolStripMenuItem^ btAdicao;
	private: System::Windows::Forms::ToolStripMenuItem^ btSubtracao;
	private: System::Windows::Forms::ToolStripMenuItem^ btMultiplicacao;
	private: System::Windows::Forms::ToolStripMenuItem^ btDivisao;
	private: System::Windows::Forms::OpenFileDialog^ ofd2;






























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
			this->nomeTool = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->resoTool = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolMouse = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ofd1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->toolBotoes = (gcnew System::Windows::Forms::ToolStrip());
			this->btCamera = (gcnew System::Windows::Forms::ToolStripButton());
			this->btImagem = (gcnew System::Windows::Forms::ToolStripButton());
			this->btCanais = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->xYZToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hSVToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hSLToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lUVToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lABToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->yCRCBToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->grayscaleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btFBlur = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->btFB1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btFB2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btFB3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btFB4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btPassaAlta = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->btLaplace = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btHistograma = (gcnew System::Windows::Forms::ToolStripButton());
			this->btAlgebricas = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->btAdicao = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btSubtracao = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btMultiplicacao = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btDivisao = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->btReabrir = (gcnew System::Windows::Forms::ToolStripButton());
			this->btRestaurar = (gcnew System::Windows::Forms::ToolStripButton());
			this->btHistorico = (gcnew System::Windows::Forms::ToolStripButton());
			this->listHistórico = (gcnew System::Windows::Forms::ListBox());
			this->ofd2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1->SuspendLayout();
			this->toolBotoes->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->nomeTool, this->resoTool,
					this->toolMouse
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 537);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(784, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
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
			this->toolBotoes->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {
				this->btCamera, this->btImagem,
					this->btCanais, this->btFBlur, this->btPassaAlta, this->btHistograma, this->btAlgebricas, this->toolStripSeparator1, this->btReabrir,
					this->btRestaurar, this->btHistorico
			});
			this->toolBotoes->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::Flow;
			this->toolBotoes->Location = System::Drawing::Point(0, 0);
			this->toolBotoes->Name = L"toolBotoes";
			this->toolBotoes->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->toolBotoes->Size = System::Drawing::Size(784, 23);
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
			this->btCanais->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->xYZToolStripMenuItem,
					this->hSVToolStripMenuItem, this->hSLToolStripMenuItem, this->lUVToolStripMenuItem, this->lABToolStripMenuItem, this->yCRCBToolStripMenuItem,
					this->grayscaleToolStripMenuItem
			});
			this->btCanais->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btCanais->Name = L"btCanais";
			this->btCanais->Size = System::Drawing::Size(55, 19);
			this->btCanais->Text = L"Canais";
			this->btCanais->TextImageRelation = System::Windows::Forms::TextImageRelation::Overlay;
			this->btCanais->ToolTipText = L"Conversão de canais";
			// 
			// xYZToolStripMenuItem
			// 
			this->xYZToolStripMenuItem->Name = L"xYZToolStripMenuItem";
			this->xYZToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->xYZToolStripMenuItem->Text = L"XYZ";
			this->xYZToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaPrincipal::xYZToolStripMenuItem_Click_1);
			// 
			// hSVToolStripMenuItem
			// 
			this->hSVToolStripMenuItem->Name = L"hSVToolStripMenuItem";
			this->hSVToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->hSVToolStripMenuItem->Text = L"HSV";
			this->hSVToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaPrincipal::hSVToolStripMenuItem_Click);
			// 
			// hSLToolStripMenuItem
			// 
			this->hSLToolStripMenuItem->Name = L"hSLToolStripMenuItem";
			this->hSLToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->hSLToolStripMenuItem->Text = L"HSL";
			this->hSLToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaPrincipal::hSLToolStripMenuItem_Click);
			// 
			// lUVToolStripMenuItem
			// 
			this->lUVToolStripMenuItem->Name = L"lUVToolStripMenuItem";
			this->lUVToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->lUVToolStripMenuItem->Text = L"LUV";
			this->lUVToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaPrincipal::lUVToolStripMenuItem_Click);
			// 
			// lABToolStripMenuItem
			// 
			this->lABToolStripMenuItem->Name = L"lABToolStripMenuItem";
			this->lABToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->lABToolStripMenuItem->Text = L"LAB";
			this->lABToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaPrincipal::lABToolStripMenuItem_Click);
			// 
			// yCRCBToolStripMenuItem
			// 
			this->yCRCBToolStripMenuItem->Name = L"yCRCBToolStripMenuItem";
			this->yCRCBToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->yCRCBToolStripMenuItem->Text = L"YCRCB";
			this->yCRCBToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaPrincipal::yCRCBToolStripMenuItem_Click);
			// 
			// grayscaleToolStripMenuItem
			// 
			this->grayscaleToolStripMenuItem->Name = L"grayscaleToolStripMenuItem";
			this->grayscaleToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->grayscaleToolStripMenuItem->Text = L"Grayscale";
			this->grayscaleToolStripMenuItem->Click += gcnew System::EventHandler(this, &TelaPrincipal::grayscaleToolStripMenuItem_Click);
			// 
			// btFBlur
			// 
			this->btFBlur->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->btFB1, this->btFB2,
					this->btFB3, this->btFB4
			});
			this->btFBlur->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btFBlur->Name = L"btFBlur";
			this->btFBlur->Size = System::Drawing::Size(78, 19);
			this->btFBlur->Text = L"Suavização";
			this->btFBlur->TextImageRelation = System::Windows::Forms::TextImageRelation::Overlay;
			this->btFBlur->ToolTipText = L"Filtros de Blur";
			// 
			// btFB1
			// 
			this->btFB1->Name = L"btFB1";
			this->btFB1->Size = System::Drawing::Size(121, 22);
			this->btFB1->Text = L"Blur";
			this->btFB1->Click += gcnew System::EventHandler(this, &TelaPrincipal::btFB1_Click);
			// 
			// btFB2
			// 
			this->btFB2->Name = L"btFB2";
			this->btFB2->Size = System::Drawing::Size(121, 22);
			this->btFB2->Text = L"Gaussian";
			this->btFB2->Click += gcnew System::EventHandler(this, &TelaPrincipal::btFB2_Click);
			// 
			// btFB3
			// 
			this->btFB3->Name = L"btFB3";
			this->btFB3->Size = System::Drawing::Size(121, 22);
			this->btFB3->Text = L"Median";
			this->btFB3->Click += gcnew System::EventHandler(this, &TelaPrincipal::btFB3_Click);
			// 
			// btFB4
			// 
			this->btFB4->Name = L"btFB4";
			this->btFB4->Size = System::Drawing::Size(121, 22);
			this->btFB4->Text = L"Bilateral";
			this->btFB4->Click += gcnew System::EventHandler(this, &TelaPrincipal::btFB4_Click);
			// 
			// btPassaAlta
			// 
			this->btPassaAlta->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->btLaplace });
			this->btPassaAlta->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btPassaAlta->Name = L"btPassaAlta";
			this->btPassaAlta->Size = System::Drawing::Size(71, 19);
			this->btPassaAlta->Text = L"Passa alta";
			this->btPassaAlta->TextImageRelation = System::Windows::Forms::TextImageRelation::Overlay;
			this->btPassaAlta->ToolTipText = L"Aplicar filtros de passa alta";
			// 
			// btLaplace
			// 
			this->btLaplace->Name = L"btLaplace";
			this->btLaplace->Size = System::Drawing::Size(114, 22);
			this->btLaplace->Text = L"Laplace";
			this->btLaplace->Click += gcnew System::EventHandler(this, &TelaPrincipal::btLaplace_Click);
			// 
			// btHistograma
			// 
			this->btHistograma->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btHistograma->Name = L"btHistograma";
			this->btHistograma->Size = System::Drawing::Size(73, 19);
			this->btHistograma->Text = L"Histograma";
			this->btHistograma->TextImageRelation = System::Windows::Forms::TextImageRelation::Overlay;
			this->btHistograma->ToolTipText = L"Mostrar histograma da imagem";
			this->btHistograma->Click += gcnew System::EventHandler(this, &TelaPrincipal::btHistograma_Click);
			// 
			// btAlgebricas
			// 
			this->btAlgebricas->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->btAdicao,
					this->btSubtracao, this->btMultiplicacao, this->btDivisao
			});
			this->btAlgebricas->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btAlgebricas->Name = L"btAlgebricas";
			this->btAlgebricas->Size = System::Drawing::Size(75, 19);
			this->btAlgebricas->Text = L"Algébricas";
			this->btAlgebricas->TextImageRelation = System::Windows::Forms::TextImageRelation::Overlay;
			this->btAlgebricas->ToolTipText = L"Operações algébricas com imagens";
			// 
			// btAdicao
			// 
			this->btAdicao->Name = L"btAdicao";
			this->btAdicao->Size = System::Drawing::Size(180, 22);
			this->btAdicao->Text = L"Adição";
			this->btAdicao->Click += gcnew System::EventHandler(this, &TelaPrincipal::btAdicao_Click);
			// 
			// btSubtracao
			// 
			this->btSubtracao->Name = L"btSubtracao";
			this->btSubtracao->Size = System::Drawing::Size(180, 22);
			this->btSubtracao->Text = L"Subtração";
			this->btSubtracao->Click += gcnew System::EventHandler(this, &TelaPrincipal::btSubtracao_Click);
			// 
			// btMultiplicacao
			// 
			this->btMultiplicacao->Name = L"btMultiplicacao";
			this->btMultiplicacao->Size = System::Drawing::Size(180, 22);
			this->btMultiplicacao->Text = L"Multiplicação";
			// 
			// btDivisao
			// 
			this->btDivisao->Name = L"btDivisao";
			this->btDivisao->Size = System::Drawing::Size(180, 22);
			this->btDivisao->Text = L"Divisão";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 23);
			// 
			// btReabrir
			// 
			this->btReabrir->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btReabrir->Name = L"btReabrir";
			this->btReabrir->Size = System::Drawing::Size(79, 19);
			this->btReabrir->Text = L"Reabir Janela";
			this->btReabrir->TextImageRelation = System::Windows::Forms::TextImageRelation::Overlay;
			this->btReabrir->ToolTipText = L"Reabir janela imagem fechada";
			this->btReabrir->Click += gcnew System::EventHandler(this, &TelaPrincipal::btReabrir_Click);
			// 
			// btRestaurar
			// 
			this->btRestaurar->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btRestaurar->Name = L"btRestaurar";
			this->btRestaurar->Size = System::Drawing::Size(107, 19);
			this->btRestaurar->Text = L"Restaurar imagem";
			this->btRestaurar->TextImageRelation = System::Windows::Forms::TextImageRelation::Overlay;
			this->btRestaurar->ToolTipText = L"Restaurar imagem a original";
			this->btRestaurar->Click += gcnew System::EventHandler(this, &TelaPrincipal::btRestaurar_Click);
			// 
			// btHistorico
			// 
			this->btHistorico->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btHistorico->Name = L"btHistorico";
			this->btHistorico->Size = System::Drawing::Size(59, 19);
			this->btHistorico->Text = L"Histórico";
			this->btHistorico->TextImageRelation = System::Windows::Forms::TextImageRelation::Overlay;
			this->btHistorico->ToolTipText = L"Clique para ver o histórico de ações";
			this->btHistorico->Click += gcnew System::EventHandler(this, &TelaPrincipal::btHistorico_Click);
			// 
			// listHistórico
			// 
			this->listHistórico->Dock = System::Windows::Forms::DockStyle::Right;
			this->listHistórico->FormattingEnabled = true;
			this->listHistórico->HorizontalScrollbar = true;
			this->listHistórico->Location = System::Drawing::Point(404, 23);
			this->listHistórico->Name = L"listHistórico";
			this->listHistórico->ScrollAlwaysVisible = true;
			this->listHistórico->Size = System::Drawing::Size(380, 514);
			this->listHistórico->TabIndex = 3;
			this->listHistórico->Visible = false;
			// 
			// ofd2
			// 
			this->ofd2->FileName = L"openFileDialog2";
			this->ofd2->Filter = L"Image Files(*.BMP;*.JPG;*.GIF;*.PNG)|*.BMP;*.JPG;*.GIF;*.PNG";
			// 
			// TelaPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->listHistórico);
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
		testeVideos->modificando = original;//linkando a imagem para não perder referencia

		/* colocando a lena de fundo */
		Image^ imgFundo = Image::FromFile("lena.jpg");
		TelaPrincipal::BackgroundImage = imgFundo;
		testeVideos->salvamostra(testeVideos->modificando, 0);
		/*imshow("Imagem", testeVideos->modificando); estava com essas duas linhas de códigos antes na inicializacao
		imwrite("Imagem.jpg", original);*///lena deve existir na pasta do projeto se n vai dar erro
		
		//Carregar icones do projeto
		btCamera->Text = "";
		btCamera->Image = Image::FromFile("icones/camera.png");
		btImagem->Text = "";
		btImagem->Image = Image::FromFile("icones/imagem.png");
		btCanais->Text = "";
		btCanais->Image = Image::FromFile("icones/canais.png");
		btFBlur->Text = "";
		btFBlur->Image = Image::FromFile("icones/blur.png");
		btHistograma->Text = "";
		btHistograma->Image = Image::FromFile("icones/histogram.png");
		btReabrir->Text = "";
		btReabrir->Image = Image::FromFile("icones/window.png");
		btRestaurar->Text = "";
		btRestaurar->Image = Image::FromFile("icones/restaurar.png");
		btHistorico->Text = "";
		btHistorico->Image = Image::FromFile("icones/history.png");
		btAlgebricas->Text = "";
		btAlgebricas->Image = Image::FromFile("icones/mathematic.png");

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
		split(testeVideos->modificando, canais);
		//imshow("Imagem", img); //imagem convertida pode ser mostrada na tela principal
		testeVideos->salvamostra(testeVideos->modificando, 0);//salvar e mostrar imagem
		//imwrite("Imagem.jpg", img);//salva a  imagem
		//abaixo atualizando fundo para a imagem convertida
		/*Image^ imgGerada = Image::FromFile("Imagem.jpg");
		TelaPrincipal::BackgroundImage = imgGerada;*/
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

	private: System::Void mostrarHistograma(cv::Mat imagem) {//gera histograma da imagem de parametro
		MatND imgHist = geraHistograma(imagem, &histImagem);
		imshow("Histograma imagem", histImagem);
		imwrite("Histograma-imagem.jpg", histImagem);
	}

	private: System::Void TelaPrincipal_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		toolMouse->Visible = true;
		toolMouse->Text = "Mouse em X: " + e->Location.X.ToString() + " Y-" + e->Location.Y.ToString();
	}

	private: System::Void TelaPrincipal::TelaPrincipal_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void btCamera_Click(System::Object^ sender, System::EventArgs^ e) {
		testeVideos->abrirCamera();
		testeVideos->MostrarImg(testeVideos->modificando);
		listHistórico->Items->Add("Abriu a camera");
	}

	private: System::Void filenameToMat(System::String ^ nome, Mat dst) {
		dst = imread((char*)(void*)Marshal::StringToHGlobalAnsi(nome));
	}

	private: System::Void btImagem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (TelaPrincipal::ofd1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			original = imread((char*)(void*)Marshal::StringToHGlobalAnsi(TelaPrincipal::ofd1->FileName));
			testeVideos->modificando = original;
			TelaPrincipal::nomeTool->Visible = true;
			TelaPrincipal::nomeTool->Text = TelaPrincipal::ofd1->FileName;
			//original = imread(str2);
			//img = imread(str2);//ler imagem selecionada
			//System::Windows::Forms::MessageBox::Show("Imagem carregada");
			Image^ imgFundo = Image::FromFile(TelaPrincipal::ofd1->FileName);
			testeVideos->salvamostra(testeVideos->modificando, 0);//salvando na pasta do projeto a imagem como imagem.jpg
			//TelaPrincipal::BackgroundImage = Image::FromFile(TelaPrincipal::ofd1->FileName);
			TelaPrincipal::BackgroundImage = imgFundo;
			//int iWidth = imgFundo->Width;
			//int iHeight = imgFundo->Height;
			TelaPrincipal::resoTool->Text = "Width: " + imgFundo->Width.ToString() + " Height: " + imgFundo->Height.ToString();
			TelaPrincipal::resoTool->Visible = true;
			//TelaPrincipal::Width = imgFundo->Width; ajustar ao tamanho da imagem
			//TelaPrincipal::Height = imgFundo->Height;
			listHistórico->Items->Add("Abriu imagem: " + ofd1->FileName);
		}
		else {
			System::Windows::Forms::MessageBox::Show("Operação cancelada");
		}
	}

	private: System::Void xYZToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
		testeVideos->LerImg();
		cvtColor(testeVideos->modificando, testeVideos->modificando, COLOR_BGR2XYZ);
		TelaPrincipal::Converter();
		listHistórico->Items->Add("Converteu para XYZ");
	}

	private: System::Void hSVToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		testeVideos->LerImg();
		cvtColor(testeVideos->modificando, testeVideos->modificando, COLOR_BGR2HSV);
		TelaPrincipal::Converter();
		listHistórico->Items->Add("Converteu para HSV");
	}

	private: System::Void hSLToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		testeVideos->LerImg();
		cvtColor(testeVideos->modificando, testeVideos->modificando, COLOR_BGR2HLS);
		TelaPrincipal::Converter();
		listHistórico->Items->Add("Converteu para HSL");
	}

	private: System::Void lUVToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		testeVideos->LerImg();
		cvtColor(testeVideos->modificando, testeVideos->modificando, COLOR_BGR2Luv);
		TelaPrincipal::Converter();
		listHistórico->Items->Add("Converteu para LUV");
	}

	private: System::Void lABToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		testeVideos->LerImg();
		cvtColor(testeVideos->modificando, testeVideos->modificando, COLOR_BGR2Lab);
		TelaPrincipal::Converter();
		listHistórico->Items->Add("Converteu para LAB");
	}

	private: System::Void yCRCBToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		testeVideos->LerImg();
		cvtColor(testeVideos->modificando, testeVideos->modificando, COLOR_BGR2YCrCb);
		TelaPrincipal::Converter();
		listHistórico->Items->Add("Converteu para YCRCB");
	}

	private: System::Void grayscaleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		testeVideos->LerImg();
		cvtColor(testeVideos->modificando, testeVideos->modificando, COLOR_BGR2GRAY);
		listHistórico->Items->Add("Converteu para Grayscale");

		Mat canais[1];
		split(testeVideos->modificando, canais);
		testeVideos->salvamostra(testeVideos->modificando, 0);//salvar e mostrar imagem
		Image^ imgGerada = Image::FromFile("Imagem.jpg");
		TelaPrincipal::BackgroundImage = imgGerada;
		imshow("Canal 0", canais[0]);
		imwrite("Img-Canal0.png", canais[0]);

		for (int c = 0; c < 1; c++) {//para cada canal faca
			MatND gHist = geraHistograma(canais[c], &histograma);
			System::String^ textoForm = System::String::Concat("H-Canal ", c);
			std::string textJanela = msclr::interop::marshal_as<std::string>(textoForm);
			imshow(textJanela, histograma);
			imwrite(textJanela + ".jpg", histograma);
		}
		//salvar imagens
		System::Windows::Forms::MessageBox::Show("Imagens convertidas salvas na pasta do projeto");
	}

	private: System::Void btFB1_Click(System::Object^ sender, System::EventArgs^ e) {
		//habilitar filtros blur na imagem
		//testeVideos->modificando = testeVideos->modificando;
		//imshow("Imagem", testeVideos->modificando);
		testeVideos->TracksEFiltros("Imagem", 0);
		listHistórico->Items->Add("Aplicou blur");
		//imshow("Imagem", testeVideos->modificando);
		//modificando = testeVideos->modificando;
	}

	private: System::Void btFB2_Click(System::Object^ sender, System::EventArgs^ e) {
		//habilitar filtros blur na imagem
		//testeVideos->modificando = testeVideos->modificando;
		//imshow("Imagem", testeVideos->modificando);
		testeVideos->TracksEFiltros("Imagem", 1);
		listHistórico->Items->Add("Aplicou Gaussian blur");
	}

	private: System::Void btFB3_Click(System::Object^ sender, System::EventArgs^ e) {
		//habilitar filtros blur na imagem
		//testeVideos->modificando = testeVideos->modificando;
		//imshow("Imagem", testeVideos->modificando);
		testeVideos->TracksEFiltros("Imagem", 2);
		listHistórico->Items->Add("Aplicou Median");
	}

	private: System::Void btFB4_Click(System::Object^ sender, System::EventArgs^ e) {
		//habilitar filtros blur na imagem
		//testeVideos->modificando = testeVideos->modificando;
		//imshow("Imagem", testeVideos->modificando);
		testeVideos->TracksEFiltros("Imagem", 3);
		listHistórico->Items->Add("Aplicou Bilateral filter");
	}

	private: System::Void btHistograma_Click(System::Object^ sender, System::EventArgs^ e) {
		testeVideos->LerImg();
		mostrarHistograma(testeVideos->modificando);
		listHistórico->Items->Add("Vizualizou o histograma da imagem");
	}

	private: System::Void btReabrir_Click(System::Object^ sender, System::EventArgs^ e) {
		testeVideos->LerImg();
		//imshow("Imagem", testeVideos->modificando);
		testeVideos->salvamostra(testeVideos->modificando,0);
		listHistórico->Items->Add("Reabriu a janela");
	}

	private: System::Void btRestaurar_Click(System::Object^ sender, System::EventArgs^ e) {
		testeVideos->modificando = original;
		testeVideos->SalvarImg(testeVideos->modificando);
		listHistórico->Items->Add("Restaurou a imagem para a original");
	}

	private: System::Void btLaplace_Click(System::Object^ sender, System::EventArgs^ e) {
		testeVideos->passaAlta(1);
		listHistórico->Items->Add("Aplicou Laplace");
	}

	private: System::Void btHistorico_Click(System::Object^ sender, System::EventArgs^ e) {
		listHistórico->Visible = !listHistórico->Visible;
		listHistórico->Items->Add("Vizualizou o histórico");
	}

	private: System::Void btAdicao_Click(System::Object^ sender, System::EventArgs^ e) {
		if (TelaPrincipal::ofd2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			try {
				testeVideos->algebrica = imread((char*)(void*)Marshal::StringToHGlobalAnsi(TelaPrincipal::ofd2->FileName));
				//salvar na pasta do projeto
				imwrite("Adicao.jpg", testeVideos->algebrica);
				//Image^ imgAdicao = Image::FromFile(TelaPrincipal::ofd2->FileName);
				listHistórico->Items->Add("Abriu imagem de adicao: " + ofd2->FileName);
				Mat resultante;
				testeVideos->LerImg();
				addWeighted(testeVideos->modificando, 0.5, testeVideos->algebrica, 0.5, 0, resultante);
				//imshow("Soma", resultante);
				testeVideos->modificando = resultante;
				testeVideos->salvamostra(testeVideos->modificando, 0);
			}
			catch (std::exception& ex) {
				string excp = ex.what();
				System::String^ texto = gcnew System::String(excp.c_str());
				System::Windows::Forms::MessageBox::Show("As imagens devem ter a mesma dimensão para serem somadas");
			}
		}
		else {
			System::Windows::Forms::MessageBox::Show("Operação cancelada");
		}
	}

	private: System::Void btSubtracao_Click(System::Object^ sender, System::EventArgs^ e) {
		if (TelaPrincipal::ofd2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			try {
				testeVideos->algebrica = imread((char*)(void*)Marshal::StringToHGlobalAnsi(TelaPrincipal::ofd2->FileName));
				//salvar na pasta do projeto
				imwrite("Subtracao.jpg", testeVideos->algebrica);
				//Image^ imgAdicao = Image::FromFile(TelaPrincipal::ofd2->FileName);
				listHistórico->Items->Add("Abriu imagem de subtracao: " + ofd2->FileName);
				Mat resultante;
				testeVideos->LerImg();
				subtract(testeVideos->modificando, testeVideos->algebrica, resultante);
				testeVideos->modificando = resultante;
				//addWeighted(testeVideos->modificando, 0.5, testeVideos->algebrica, 0.5, 0, resultante);
				//imshow("Subtracao", resultante);
				testeVideos->salvamostra(testeVideos->modificando, 0);
			}
			catch (std::exception& ex) {
				string excp = ex.what();
				System::String^ texto = gcnew System::String(excp.c_str());
				System::Windows::Forms::MessageBox::Show("As imagens devem ter a mesma dimensão para serem somadas");
			}
		}
		else {
			System::Windows::Forms::MessageBox::Show("Operação cancelada");
		}
	}
};
}
