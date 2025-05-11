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

	private: float zoomScale = 1.0f;
	private: Bitmap^ originalImage; //for scrolling the canvas

	private: bool isDragging = false;
	private: System::Drawing::Point lastMousePosition;


	private: System::Windows::Forms::Panel^ canvas;

	

	public:

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

			// Enable mouse wheel zooming
			this->canvas->MouseEnter += gcnew System::EventHandler(this, &VNTS_Canvas::Canvas_MouseEnter);

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
	private: System::Windows::Forms::Button^ SaveButton;
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
			this->SaveButton = gcnew System::Windows::Forms::Button();
			this->objectsLabel = (gcnew System::Windows::Forms::Label());
			this->classCircle = (gcnew System::Windows::Forms::Button());
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
			this->SaveAndExitButton->Click += gcnew System::EventHandler(this, &VNTS_Canvas::button1_Click);
			//
			// // SaveButton
			// 
			this->SaveButton->Size = System::Drawing::Size(30, 30); // Small button
			this->SaveButton->Location = System::Drawing::Point(920, 10); // Default position
			this->SaveButton->Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right; // Adjust position on resize
			this->SaveButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SaveButton->BackColor = System::Drawing::Color::Transparent; // Transparent background
			this->SaveButton->Click += gcnew System::EventHandler(this, &VNTS_Canvas::SaveButton_Click);

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
			// 
			// classCircle
			// 
			this->classCircle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->classCircle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->classCircle->ForeColor = System::Drawing::Color::White;
			this->classCircle->Location = System::Drawing::Point(50, 100);
			this->classCircle->Name = L"classCircle";
			this->classCircle->Size = System::Drawing::Size(100, 50);
			this->classCircle->TabIndex = 3;
			this->classCircle->Text = L"Class";
			this->classCircle->UseVisualStyleBackColor = false;
			this->classCircle->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::circleButton_MouseDown);
			// 
			// canvas
			// 
			this->canvas->AutoScroll = true;
			this->canvas->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"canvas.BackgroundImage")));
			this->canvas->Location = System::Drawing::Point(200, 50);
			this->canvas->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(769, 592);
			this->canvas->TabIndex = 4;
			//scroll
			this->canvas->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::Canvas_MouseWheel);


			
			//
			//Background image (canvas)
			//
						

			System::Windows::Forms::PictureBox^ backgroundPictureBox = gcnew System::Windows::Forms::PictureBox();
			originalImage = (cli::safe_cast<Bitmap^>(resources->GetObject(L"canvas.BackgroundImage"))); // Load the original image
			backgroundPictureBox->Image = originalImage;
			backgroundPictureBox->Size = System::Drawing::Size(960, 640);
			backgroundPictureBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;

			////use mouse to travel
			backgroundPictureBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::Canvas_MouseDown);
			backgroundPictureBox->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::Canvas_MouseMove);
			backgroundPictureBox->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::Canvas_MouseUp);



			this->canvas->Controls->Add(backgroundPictureBox);
			// 
			// VNTS_Canvas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->ClientSize = System::Drawing::Size(960, 640);
			this->Controls->Add(this->canvas);
			this->Controls->Add(this->classCircle);
			this->Controls->Add(this->objectsLabel);
			this->Controls->Add(this->SaveAndExitButton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->canvasHeader);
			this->Controls->Add(this->toolboxBackground);
			this->Name = L"Visual Note Taking System";
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
		// Check if the save file exists
		if (System::IO::File::Exists("canvas_save.txt"))
		{
			System::IO::StreamReader^ reader = gcnew System::IO::StreamReader("canvas_save.txt");
			int scrollX = System::Convert::ToInt32(reader->ReadLine());
			int scrollY = System::Convert::ToInt32(reader->ReadLine());
			zoomScale = System::Convert::ToSingle(reader->ReadLine());
			reader->Close();

			// Apply the saved scroll position and zoom level
			this->canvas->AutoScrollPosition = System::Drawing::Point(scrollX, scrollY); // Remove sign inversion
			ResizeCanvasContent(System::Drawing::Point(0, 0)); // Adjust the canvas size based on the zoom level
		}
	}







	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}
	private: System::Void toolboxBackground_Click(System::Object^ sender, System::EventArgs^ e) {
	}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{


	}

		   //************************************DRAG AND DROP***************************************
				  


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


		//**********************************************************************



	   //*******************MOUSE SCROLLING*************************************
	protected: virtual void OnMouseWheel(System::Windows::Forms::MouseEventArgs^ e) override
	{
		// Define zoom limits
		const float MIN_ZOOM = 0.5f; // Minimum zoom scale (50%)
		const float MAX_ZOOM = 5.0f; // Maximum zoom scale (300%)

		// Adjust zoom scale based on scroll direction
		if (e->Delta > 0) // Scroll up to zoom in
		{
			zoomScale = Math::Min(MAX_ZOOM, zoomScale + 0.1f); // Increase zoom scale, but not above MAX_ZOOM
		}
		else if (e->Delta < 0) // Scroll down to zoom out
		{
			zoomScale = Math::Max(MIN_ZOOM, zoomScale - 0.1f); // Decrease zoom scale, but not below MIN_ZOOM
		}

		// Resize the canvas content
		ResizeCanvasContent(e->Location);
	}

	private: void ResizeCanvasContent(System::Drawing::Point mouseLocation)
	{
		// Ensure the canvas has a PictureBox
		if (this->canvas->Controls->Count > 0)
		{
			System::Windows::Forms::PictureBox^ pictureBox = dynamic_cast<System::Windows::Forms::PictureBox^>(this->canvas->Controls[0]);
			if (pictureBox != nullptr && originalImage != nullptr)
			{
				// Calculate the new size based on the zoom scale
				int newWidth = static_cast<int>(originalImage->Width * zoomScale);
				int newHeight = static_cast<int>(originalImage->Height * zoomScale);

				// Create a new scaled image
				Bitmap^ scaledImage = gcnew Bitmap(newWidth, newHeight);
				Graphics^ g = Graphics::FromImage(scaledImage);
				g->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::HighQualityBicubic;
				g->DrawImage(originalImage, 0, 0, newWidth, newHeight);
				delete g;

				// Update the PictureBox with the scaled image
				pictureBox->Image = scaledImage;
				pictureBox->Size = System::Drawing::Size(newWidth, newHeight);

				// Adjust the scroll position to keep the zoom centered around the mouse pointer
				int currentScrollX = -this->canvas->AutoScrollPosition.X;
				int currentScrollY = -this->canvas->AutoScrollPosition.Y;

				int mouseX = mouseLocation.X + currentScrollX;
				int mouseY = mouseLocation.Y + currentScrollY;

				int newScrollX = static_cast<int>(mouseX * zoomScale / (zoomScale - 0.1f) - mouseX);
				int newScrollY = static_cast<int>(mouseY * zoomScale / (zoomScale - 0.1f) - mouseY);

				this->canvas->AutoScrollPosition = System::Drawing::Point(newScrollX, newScrollY);
			}
		}
	}


	private: System::Void Canvas_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			isDragging = true;
			lastMousePosition = e->Location;
			Console::WriteLine("Mouse Down at: {0}, {1}", e->X, e->Y);
		}
	}

   private: System::Void Canvas_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
   {
	   if (isDragging)
	   {
		   Console::WriteLine("Mouse Move at: {0}, {1}", e->X, e->Y);
		   int offsetX = lastMousePosition.X - e->X;
		   int offsetY = lastMousePosition.Y - e->Y;

		   this->canvas->AutoScrollPosition = System::Drawing::Point(
			   -this->canvas->AutoScrollPosition.X + offsetX,
			   -this->canvas->AutoScrollPosition.Y + offsetY
		   );

		   lastMousePosition = e->Location;
	   }
   }

   private: System::Void Canvas_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
   {
	   if (e->Button == System::Windows::Forms::MouseButtons::Left)
	   {
		   isDragging = false;
		   Console::WriteLine("Mouse Up at: {0}, {1}", e->X, e->Y);
	   }
   }

	private: System::Void Canvas_MouseEnter(System::Object^ sender, System::EventArgs^ e)
	{
		this->canvas->Focus(); // Set focus to the canvas
	}

	private: System::Void Canvas_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		this->OnMouseWheel(e); // Call the existing OnMouseWheel method
	}

		   //**********************************************************************


	//******************************** - SAVE BUTTON - **************************************
	private: System::Void SaveButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Get the current scroll position
		int scrollX = -this->canvas->AutoScrollPosition.X;
		int scrollY = -this->canvas->AutoScrollPosition.Y;

		// Save the scroll position and zoom level to a file
		System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter("canvas_save.txt");
		writer->WriteLine(scrollX);
		writer->WriteLine(scrollY);
		writer->WriteLine(zoomScale);
		writer->Close();

		MessageBox::Show("Canvas state saved!", "Save", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}






        


};



	
	


}
