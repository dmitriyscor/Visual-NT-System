#pragma once

#include <msclr/marshal_cppstd.h>

#include <string>
#include <map>
#include "CircleClass.h" // Include the CircleClass header



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

	private: float zoomScale = 1.0f;
	private: Bitmap^ originalImage; //for scrolling the canvas

	private: bool isDragging = false;
	private: System::Drawing::Point lastMousePosition;




	private: System::Windows::Forms::TextBox^ CanvasName;


	//obkects: classes and structures
	private:
		std::multimap<std::string, CircleClass>* circles_multimap;
	private: System::Windows::Forms::Panel^ canvas;

	private: Bitmap^ canvasBackground;

	public:

		

		literal int TOOLBOX_WIDTH = 200;

		VNTS_Canvas(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			this->AllowDrop = true;
			
			this->canvas->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::Canvas_MouseDown);
			this->canvas->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::Canvas_MouseMove);
			this->canvas->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::Canvas_MouseUp);

			this->canvas->Paint += gcnew PaintEventHandler(this, &VNTS_Canvas::Canvas_Paint);

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
			delete this->circles_multimap;
		}

	private: System::Windows::Forms::PictureBox^ canvasHeader;
	private: System::Windows::Forms::PictureBox^ toolboxBackground;
	private: System::Windows::Forms::Button^ SaveAndExitButton;
	private: System::Windows::Forms::Button^ SaveButton;
	private: System::Windows::Forms::Label^ objects;

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
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->objects = (gcnew System::Windows::Forms::Label());
			this->classCircle = (gcnew System::Windows::Forms::Button());
			this->CanvasName = (gcnew System::Windows::Forms::TextBox());
			this->canvas = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvasHeader))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->toolboxBackground))->BeginInit();
			this->SuspendLayout();
			// 
			// canvasHeader
			// 
			this->canvasHeader->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"canvasHeader.Image")));
			this->canvasHeader->Location = System::Drawing::Point(-2, -1);
			this->canvasHeader->Name = L"canvasHeader";
			this->canvasHeader->Size = System::Drawing::Size(960, 50);
			this->canvasHeader->TabIndex = 0;
			this->canvasHeader->TabStop = false;
			this->canvasHeader->Click += gcnew System::EventHandler(this, &VNTS_Canvas::pictureBox1_Click);
			// 
			// toolboxBackground
			// 
			this->toolboxBackground->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolboxBackground.Image")));
			this->toolboxBackground->Location = System::Drawing::Point(0, 0);
			this->toolboxBackground->Name = L"toolboxBackground";
			this->toolboxBackground->Size = System::Drawing::Size(200, 640);
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
			this->SaveAndExitButton->Size = System::Drawing::Size(200, 70);
			this->SaveAndExitButton->TabIndex = 1;
			this->SaveAndExitButton->Text = L"Save And Exit";
			this->SaveAndExitButton->UseVisualStyleBackColor = false;
			this->SaveAndExitButton->Click += gcnew System::EventHandler(this, &VNTS_Canvas::SaveAndExit);
			// 
			// SaveButton
			// 
			this->SaveButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->SaveButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->SaveButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SaveButton.BackgroundImage")));
			this->SaveButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SaveButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->SaveButton->Location = System::Drawing::Point(920, 10);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(30, 30);
			this->SaveButton->TabIndex = 5;
			this->SaveButton->UseVisualStyleBackColor = false;
			this->SaveButton->Click += gcnew System::EventHandler(this, &VNTS_Canvas::SaveButton_Click);
			// 
			// objects
			// 
			this->objects->AutoSize = true;
			this->objects->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->objects->Font = (gcnew System::Drawing::Font(L"Candara", 15.75F));
			this->objects->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)));
			this->objects->Location = System::Drawing::Point(59, 9);
			this->objects->Name = L"objects";
			this->objects->Size = System::Drawing::Size(81, 26);
			this->objects->TabIndex = 3;
			this->objects->Text = L"Objects";
			// 
			// classCircle
			// 
			this->classCircle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->classCircle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->classCircle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->classCircle->ForeColor = System::Drawing::Color::White;
			this->classCircle->Location = System::Drawing::Point(12, 74);
			this->classCircle->Name = L"classCircle";
			this->classCircle->Size = System::Drawing::Size(171, 50);
			this->classCircle->TabIndex = 3;
			this->classCircle->Text = L"Class";
			this->classCircle->UseVisualStyleBackColor = false;
			// 
			// CanvasName
			// 
			this->CanvasName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(46)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->CanvasName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->CanvasName->Font = (gcnew System::Drawing::Font(L"Candara Light", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CanvasName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)));
			this->CanvasName->Location = System::Drawing::Point(233, 4);
			this->CanvasName->Name = L"CanvasName";
			this->CanvasName->Size = System::Drawing::Size(648, 33);
			this->CanvasName->TabIndex = 6;
			this->CanvasName->Text = L"New Canvas";
			// 
			// canvas
			// 
			this->canvas->AutoScroll = true;
			//this->canvas->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"canvas.BackgroundImage")));
			this->canvas->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->canvas->Location = System::Drawing::Point(200, 50);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(769, 592);
			this->canvas->TabIndex = 4;
			// 
			// VNTS_Canvas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->ClientSize = System::Drawing::Size(960, 640);
			this->Controls->Add(this->CanvasName);
			this->Controls->Add(this->canvas);
			this->Controls->Add(this->classCircle);
			this->Controls->Add(this->objects);
			this->Controls->Add(this->SaveAndExitButton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->canvasHeader);
			this->Controls->Add(this->toolboxBackground);
			this->Name = L"VNTS_Canvas";
			this->Text = L"Visual Note Taking System";
			this->Load += gcnew System::EventHandler(this, &VNTS_Canvas::VNTS_Canvas_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvasHeader))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->toolboxBackground))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//******************************** - Load Function - **************************************

    private: System::Void VNTS_Canvas_Load(System::Object^ sender, System::EventArgs^ e)
    {
        // Create a ComponentResourceManager to access resources
        System::ComponentModel::ComponentResourceManager^ resources = gcnew System::ComponentModel::ComponentResourceManager(VNTS_Canvas::typeid);

        // Set the virtual canvas size
        this->canvas->AutoScrollMinSize = System::Drawing::Size(4096, 4096);
        this->canvasBackground = (cli::safe_cast<System::Drawing::Bitmap^>(resources->GetObject(L"canvas.BackgroundImage")));

        if (System::IO::File::Exists("canvas_save.txt"))
        {
            System::IO::StreamReader^ reader = gcnew System::IO::StreamReader("canvas_save.txt");
            int scrollX = System::Convert::ToInt32(reader->ReadLine());
            int scrollY = System::Convert::ToInt32(reader->ReadLine());
            zoomScale = System::Convert::ToSingle(reader->ReadLine());
            std::string canvasName = msclr::interop::marshal_as<std::string>(reader->ReadLine());
            this->CanvasName->Text = gcnew System::String(canvasName.c_str());
            reader->Close();

            // Apply the saved scroll position and zoom level
            this->canvas->AutoScrollPosition = System::Drawing::Point(scrollX, scrollY);
        }
        else
        {
            // Center the view on the canvas
            int centerX = (4096 - this->canvas->ClientSize.Width) / 2;
            int centerY = (4096 - this->canvas->ClientSize.Height) / 2;
            this->canvas->AutoScrollPosition = System::Drawing::Point(centerX, centerY);
            Console::WriteLine("Save file not found. Centering canvas.");
        }
    }








	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}
	private: System::Void toolboxBackground_Click(System::Object^ sender, System::EventArgs^ e) 
	{

	}


	
	private: System::Void Canvas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		if (canvasBackground != nullptr)
		{
			// Get the current scroll position
			int scrollX = -this->canvas->AutoScrollPosition.X;
			int scrollY = -this->canvas->AutoScrollPosition.Y;

			// Draw the background image, offset by the scroll position
			e->Graphics->DrawImage(canvasBackground, -scrollX, -scrollY, canvasBackground->Width, canvasBackground->Height);
		}
	}
		  









	   

	//---------------------MOVE----------------------------


	private: System::Void Canvas_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			isDragging = true;
			lastMousePosition = e->Location;
			this->canvas->Cursor = Cursors::Hand; // Optional: change cursor for feedback
		}
	}

	private: System::Void Canvas_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (isDragging)
		{
			// Calculate the difference
			int dx = e->X - lastMousePosition.X;
			int dy = e->Y - lastMousePosition.Y;

			// Update the scroll position
			int newScrollX = -this->canvas->AutoScrollPosition.X - dx;
			int newScrollY = -this->canvas->AutoScrollPosition.Y - dy;
			this->canvas->AutoScrollPosition = System::Drawing::Point(newScrollX, newScrollY);

			// Update last position
			lastMousePosition = e->Location;
		}
	}

	private: System::Void Canvas_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			isDragging = false;
			this->canvas->Cursor = Cursors::Default; // Optional: reset cursor
		}
	}


			   //**********************************************************************























	//******************************** - SAVE BUTTON - **************************************
	private: System::Void SaveButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Get the current scroll position
		int scrollX = -this->canvas->AutoScrollPosition.X;
		int scrollY = -this->canvas->AutoScrollPosition.Y;

		// Convert System::String^ to std::string
		std::string canvasName = msclr::interop::marshal_as<std::string>(this->CanvasName->Text);

		// Save the scroll position, zoom level, and canvas name to a file
		System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter("canvas_save.txt");
		writer->WriteLine(scrollX);
		writer->WriteLine(scrollY);
		writer->WriteLine(zoomScale);
		writer->WriteLine(gcnew System::String(canvasName.c_str())); // Save the canvas name
		writer->Close();

		MessageBox::Show("Canvas state saved!", "Save", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	private: System::Void SaveAndExit(System::Object^ sender, System::EventArgs^ e)
	{
		SaveButton_Click(sender, e);
		Application::Exit();
	}



	};


}



