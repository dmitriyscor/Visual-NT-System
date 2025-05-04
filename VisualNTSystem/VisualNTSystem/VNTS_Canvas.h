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
	/// 
	public ref class VNTS_Canvas : public System::Windows::Forms::Form
	{
	public:

		// Dimension of the VNTS_Canvas
		literal int WIDTH = 960;
		literal int HEIGHT = 640;
		literal int TOOLBOX_WIDTH = 200;

		VNTS_Canvas(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			this->AllowDrop = true;
			this->DragEnter += gcnew DragEventHandler(this, &VNTS_Canvas::VNTS_Canvas_DragEnter);
			this->DragDrop += gcnew DragEventHandler(this, &VNTS_Canvas::VNTS_Canvas_DragDrop);

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
	private: System::Windows::Forms::Button^ SaveAndExitButton;
	private: System::Windows::Forms::Label^ objectsLabel;

	//dynamic stuff
	private: System::Windows::Forms::Button^ classCircle;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

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
			this->SaveAndExitButton = (gcnew System::Windows::Forms::Button());
			this->objectsLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvasHeader))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->toolboxBackground))->BeginInit();
			this->SuspendLayout();
			// 
			// canvasHeader
			// 
			this->canvasHeader->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"canvasHeader.Image")));
			this->canvasHeader->Location = System::Drawing::Point(-2, -1);
			this->canvasHeader->Name = L"canvasHeader";
			this->canvasHeader->Size = System::Drawing::Size(WIDTH, 50);
			this->canvasHeader->TabIndex = 0;
			this->canvasHeader->TabStop = false;
			this->canvasHeader->Click += gcnew System::EventHandler(this, &VNTS_Canvas::pictureBox1_Click);
			// 
			// toolboxBackground
			// 
			this->toolboxBackground->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolboxBackground.Image")));
			this->toolboxBackground->Location = System::Drawing::Point(0, 0);
			this->toolboxBackground->Name = L"toolboxBackground";
			this->toolboxBackground->Size = System::Drawing::Size(TOOLBOX_WIDTH, HEIGHT);
			this->toolboxBackground->TabIndex = 0;
			this->toolboxBackground->TabStop = false;
			this->toolboxBackground->Click += gcnew System::EventHandler(this, &VNTS_Canvas::toolboxBackground_Click);
			// 
			// SaveAndExitButton
			// 
			this->SaveAndExitButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->SaveAndExitButton->FlatAppearance->BorderSize = 0;
			this->SaveAndExitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SaveAndExitButton->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SaveAndExitButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(246)));
			this->SaveAndExitButton->Location = System::Drawing::Point(0, 572);
			this->SaveAndExitButton->Name = L"SaveAndExitButton";
			this->SaveAndExitButton->Padding = System::Windows::Forms::Padding(1);
			this->SaveAndExitButton->Size = System::Drawing::Size(200, 68);
			this->SaveAndExitButton->TabIndex = 1;
			this->SaveAndExitButton->Text = L"Save And Exit";
			this->SaveAndExitButton->UseVisualStyleBackColor = false;
			this->SaveAndExitButton->Click += gcnew System::EventHandler(this, &VNTS_Canvas::button1_Click);
			// 
			// objectsLabel
			// 
			this->objectsLabel->AutoSize = true;
			this->objectsLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->objectsLabel->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F));
			this->objectsLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)));
			this->objectsLabel->Location = System::Drawing::Point(51, 9);
			this->objectsLabel->Name = L"objectsLabel";
			this->objectsLabel->Size = System::Drawing::Size(81, 26);
			this->objectsLabel->TabIndex = 2;
			this->objectsLabel->Text = L"Objects";
			// circleButton
			this->classCircle = (gcnew System::Windows::Forms::Button());
			this->classCircle->BackColor = System::Drawing::Color::FromArgb(28, 44, 54);
			this->classCircle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->classCircle->ForeColor = System::Drawing::Color::White;
			this->classCircle->Location = System::Drawing::Point(50, 100); // Position inside the toolbox
			this->classCircle->Name = L"circleButton";
			this->classCircle->Size = System::Drawing::Size(100, 50);
			this->classCircle->TabIndex = 3;
			this->classCircle->Text = L"Class";
			this->classCircle->UseVisualStyleBackColor = false;
			this->classCircle->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::circleButton_MouseDown);

			// Add the button to the form
			this->Controls->Add(this->classCircle);
			// 
			// VNTS_Canvas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(WIDTH, HEIGHT);
			this->Controls->Add(this->objectsLabel);
			this->Controls->Add(this->SaveAndExitButton);
			this->Controls->Add(this->canvasHeader);
			this->Controls->Add(this->toolboxBackground);
			this->Name = L"VNTS_Canvas";
			this->Text = L"VNTS_Canvas";
			this->Load += gcnew System::EventHandler(this, &VNTS_Canvas::VNTS_Canvas_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvasHeader))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->toolboxBackground))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

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
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}


		   // Event handler for starting the drag operation
private: System::Void circleButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	this->classCircle->DoDragDrop("Class", DragDropEffects::Copy);
}

	   // Event handler for allowing drag-and-drop
private: System::Void VNTS_Canvas_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e)
{
	if (e->Data->GetDataPresent(DataFormats::Text) && e->Data->GetData(DataFormats::Text)->ToString() == "Class")
	{
		e->Effect = DragDropEffects::Copy;
	}
	else
	{
		e->Effect = DragDropEffects::None;
	}
}

	   // Event handler for handling the drop and drawing a circle
private: System::Void VNTS_Canvas_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e)
{
	Point dropLocation = this->PointToClient(Point(e->X, e->Y));
	Graphics^ g = this->CreateGraphics();
	g->FillEllipse(Brushes::DarkRed, dropLocation.X - 25, dropLocation.Y - 25, 100, 100); // Draw a circle with radius 50
	delete g;
}
};



	
	


}
