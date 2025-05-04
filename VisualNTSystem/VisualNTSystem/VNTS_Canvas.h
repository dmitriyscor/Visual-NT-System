#pragma once

namespace VisualNTSystem 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for VNTS_Canvas
	/// </summary>
	/// 

	//dimension of the VNTS_Canvas
	public ref class VNTS_Config
	{
	public:
		literal int WIDTH = 960;
		literal int HEIGHT = 640;

		literal int TOOLBOX_WIDTH = 200;
	};

	public ref class VNTS_Canvas : public System::Windows::Forms::Form
	{


	public:
		

		VNTS_Canvas(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VNTS_Canvas()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ canvasHeader;
	private: System::Windows::Forms::PictureBox^ toolboxBackground;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(VNTS_Canvas::typeid));
			this->canvasHeader = (gcnew System::Windows::Forms::PictureBox());
			this->toolboxBackground = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvasHeader))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->toolboxBackground))->BeginInit();
			this->SuspendLayout();
			// 
			// canvasHeader
			// 
			this->canvasHeader->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"canvasHeader.Image")));
			this->canvasHeader->Location = System::Drawing::Point(-2, -1);
			this->canvasHeader->Name = L"canvasHeader";
			this->canvasHeader->Size = System::Drawing::Size(VNTS_Config::WIDTH, 50);
			this->canvasHeader->TabIndex = 0;
			this->canvasHeader->TabStop = false;
			this->canvasHeader->Click += gcnew System::EventHandler(this, &VNTS_Canvas::pictureBox1_Click);
			// 
			// toolboxBackground
			// 
			this->toolboxBackground->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolboxBackground.Image")));
			this->toolboxBackground->Location = System::Drawing::Point(0, 0);
			this->toolboxBackground->Name = L"toolboxBackground";
			this->toolboxBackground->Size = System::Drawing::Size(VNTS_Config::TOOLBOX_WIDTH, VNTS_Config::HEIGHT);
			this->toolboxBackground->TabIndex = 0;
			this->toolboxBackground->TabStop = false;
			this->toolboxBackground->Click += gcnew System::EventHandler(this, &VNTS_Canvas::toolboxBackground_Click);
			// 
			// VNTS_Canvas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(VNTS_Config::WIDTH, VNTS_Config::HEIGHT);
			this->Controls->Add(this->canvasHeader);
			this->Controls->Add(this->toolboxBackground);
			
			this->Name = L"VNTS_Canvas";
			this->Text = L"VNTS_Canvas";
			this->Load += gcnew System::EventHandler(this, &VNTS_Canvas::VNTS_Canvas_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvasHeader))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->toolboxBackground))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void VNTS_Canvas_Load(System::Object^ sender, System::EventArgs^ e) 
	{

	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) 
	{

	}
	private: System::Void toolboxBackground_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
