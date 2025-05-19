#pragma once

#include <msclr/marshal_cppstd.h>

#include <string>

#include <vector>
#include <utility> // for std::pair

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

	private: System::Collections::Generic::List<System::Windows::Forms::Button^>^ classButtons;



	public:

		// Dimension of the VNTS_Canvas
		literal int WIDTH = 960;
		literal int HEIGHT = 640;

	private: float zoomScale = 1.0f;
	private: Bitmap^ originalImage; //for scrolling the canvas

	private: bool isDragging = false;
	private: System::Drawing::Point lastMousePosition;




	private: System::Windows::Forms::TextBox^ CanvasName;


	


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
			classButtons = gcnew System::Collections::Generic::List<System::Windows::Forms::Button^>();

			
			//move
			this->canvas->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::Canvas_MouseDown);
			this->canvas->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::Canvas_MouseMove);
			this->canvas->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::Canvas_MouseUp);

			this->canvas->Paint += gcnew PaintEventHandler(this, &VNTS_Canvas::Canvas_Paint);

			//scroll
			this->canvas->MouseWheel += gcnew MouseEventHandler(this, &VNTS_Canvas::Canvas_MouseWheel);
			this->canvas->Focus();


			this->classCircle->Click += gcnew System::EventHandler(this, &VNTS_Canvas::ClassCircle_Click);

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
	private: System::Windows::Forms::Label^ objects;

    //NEW_NEW_NEW_NEW_NEW_NEW_NEW_NEW_NEW_NEW_NEW_NEW_NEW_NEW_NEW
	private: System::Windows::Forms::Button^ moveableButton;
	private: System::Windows::Forms::TextBox^ renameTextBox;

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
			// moveableButton
			// 
			this->moveableButton = (gcnew System::Windows::Forms::Button());
			this->moveableButton->Location = System::Drawing::Point(250, 100); // Initial position
			this->moveableButton->Size = System::Drawing::Size(120, 40);       // Size
			this->moveableButton->Text = L"Move Me";
			this->moveableButton->BackColor = System::Drawing::Color::FromArgb(60, 120, 200);
			this->moveableButton->ForeColor = System::Drawing::Color::White;
			this->moveableButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;

			// Attach mouse events to moveableButton
			this->moveableButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::MoveableButton_MouseDown);
			this->moveableButton->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::MoveableButton_MouseMove);
			this->moveableButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::MoveableButton_MouseUp);
			this->moveableButton->Click += gcnew System::EventHandler(this, &VNTS_Canvas::MoveableButton_Click);

			// Add to form controls
			//this->canvas->Controls->Add(this->moveableButton);



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

	//***********************************************************************************
	//******************************** - Load Function - **************************************  #1
	//*********************************************************************************** 
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

			// Remove old buttons if any
			for each(System::Windows::Forms::Button ^ btn in classButtons)
				this->canvas->Controls->Remove(btn);
			classButtons->Clear();

			// Read buttons
			while (!reader->EndOfStream)
			{
				System::String^ name = reader->ReadLine();
				if (name == "END_BUTTONS") break;
				int x = System::Convert::ToInt32(reader->ReadLine());
				int y = System::Convert::ToInt32(reader->ReadLine());

				System::Windows::Forms::Button^ btn = gcnew System::Windows::Forms::Button();
				btn->Text = name;
				btn->Size = System::Drawing::Size(120, 40);
				btn->Location = System::Drawing::Point(x, y);
				btn->BackColor = System::Drawing::Color::FromArgb(60, 120, 200);
				btn->ForeColor = System::Drawing::Color::White;
				btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				btn->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::MoveableButton_MouseDown);
				btn->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::MoveableButton_MouseMove);
				btn->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::MoveableButton_MouseUp);
				btn->Click += gcnew System::EventHandler(this, &VNTS_Canvas::MoveableButton_Click);

				this->canvas->Controls->Add(btn);
				classButtons->Add(btn);
			}


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

	//*************************************************************************************  #1
	 
	//*********************************************************************************** 
	//******************************** - SAVE BUTTON - ************************************** #2
	//*********************************************************************************** 
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

		// Save all class buttons
		for each (System::Windows::Forms::Button ^ btn in classButtons)
		{
			writer->WriteLine(btn->Text);
			writer->WriteLine(btn->Location.X);
			writer->WriteLine(btn->Location.Y);
		}
		writer->WriteLine("END_BUTTONS"); // Mark end of buttons

		writer->Close();

		MessageBox::Show("Canvas state saved!", "Save", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	private: System::Void SaveAndExit(System::Object^ sender, System::EventArgs^ e)
	{
		SaveButton_Click(sender, e);
		Application::Exit();
	}

	 //*********************************************************************************** #2

	//************************************** - Create Canvas - *********************************************
	private: System::Void Canvas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		if (canvasBackground != nullptr)
		{
			int scrollX = -this->canvas->AutoScrollPosition.X;
			int scrollY = -this->canvas->AutoScrollPosition.Y;

			// Apply zoom
			e->Graphics->ScaleTransform(zoomScale, zoomScale);

			// Draw the background image at the correct position and scale
			e->Graphics->DrawImage(
				canvasBackground,
				static_cast<float>(-scrollX) / zoomScale,
				static_cast<float>(-scrollY) / zoomScale,
				static_cast<float>(canvasBackground->Width),
				static_cast<float>(canvasBackground->Height)
			);
		}
	}
	 //*********************************************************************************** 


	//************************************** - MOVEABLE BUTTON - *********************************************

	private:
		bool isButtonDragging = false;
		bool wasButtonDragged = false;
		System::Drawing::Point buttonDragOffset;
		System::Drawing::Point buttonOriginalLocation;

	private: System::Void MoveableButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			isButtonDragging = true;
			wasButtonDragged = false; // Reset drag flag
			buttonDragOffset = e->Location;
			buttonOriginalLocation = safe_cast<System::Windows::Forms::Button^>(sender)->Location; // Store original location
			moveableButton = safe_cast<System::Windows::Forms::Button^>(sender);
			moveableButton->Cursor = Cursors::Hand;
		}
	}

	private: System::Void MoveableButton_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (isButtonDragging && moveableButton != nullptr)
		{
			System::Drawing::Point newLocation = moveableButton->Location;
			newLocation.X += e->X - buttonDragOffset.X;
			newLocation.Y += e->Y - buttonDragOffset.Y;

			int minX = 0;
			int minY = 0;
			int maxX = this->canvas->ClientSize.Width - moveableButton->Width;
			int maxY = this->canvas->ClientSize.Height - moveableButton->Height;

			newLocation.X = Math::Max(minX, Math::Min(newLocation.X, maxX));
			newLocation.Y = Math::Max(minY, Math::Min(newLocation.Y, maxY));

			System::Drawing::Rectangle newRect(newLocation, moveableButton->Size);
			if (!IsButtonColliding(newRect, moveableButton))
			{
				moveableButton->Location = newLocation;
				// If the button has moved more than a few pixels, consider it a drag
				if (Math::Abs(newLocation.X - buttonOriginalLocation.X) > 3 ||
					Math::Abs(newLocation.Y - buttonOriginalLocation.Y) > 3)
				{
					wasButtonDragged = true;
				}
			}
		}
	}

	private: System::Void MoveableButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (e->Button == System::Windows::Forms::MouseButtons::Left && moveableButton != nullptr)
		{
			isButtonDragging = false;
			moveableButton->Cursor = Cursors::Default;
			moveableButton = nullptr;
		}
	}

	private: System::Void MoveableButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (wasButtonDragged)
			return; // Don't rename if it was a drag

		System::Windows::Forms::Button^ btn = safe_cast<System::Windows::Forms::Button^>(sender);
		if (renameTextBox == nullptr)
		{
			renameTextBox = gcnew System::Windows::Forms::TextBox();
			renameTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			renameTextBox->Font = btn->Font;
			renameTextBox->Leave += gcnew System::EventHandler(this, &VNTS_Canvas::RenameTextBox_Leave);
			renameTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &VNTS_Canvas::RenameTextBox_KeyDown);
			this->canvas->Controls->Add(renameTextBox);
		}
		renameTextBox->Location = btn->Location;
		renameTextBox->Size = btn->Size;
		renameTextBox->Text = btn->Text;
		renameTextBox->Tag = btn;
		renameTextBox->Visible = true;
		renameTextBox->BringToFront();
		renameTextBox->Focus();
		renameTextBox->SelectAll();
	}


	bool VNTS_Canvas::IsButtonColliding(System::Drawing::Rectangle rect, System::Windows::Forms::Button^ ignoreBtn)
	{
		for each (System::Windows::Forms::Button ^ btn in classButtons)
		{
			if (btn == ignoreBtn) continue;
			if (rect.IntersectsWith(System::Drawing::Rectangle(btn->Location, btn->Size)))
				return true;
		}
		return false;
	}

	private: System::Void RenameTextBox_Leave(System::Object^ sender, System::EventArgs^ e)
	{
		if (renameTextBox->Tag != nullptr)
		{
			System::Windows::Forms::Button^ btn = safe_cast<System::Windows::Forms::Button^>(renameTextBox->Tag);
			btn->Text = renameTextBox->Text;
		}
		renameTextBox->Visible = false;
		renameTextBox->Tag = nullptr;
	}

	private: System::Void RenameTextBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		if (e->KeyCode == System::Windows::Forms::Keys::Enter)
		{
			RenameTextBox_Leave(sender, e);
			e->SuppressKeyPress = true;
		}
		else if (e->KeyCode == System::Windows::Forms::Keys::Escape)
		{
			renameTextBox->Visible = false;
			renameTextBox->Tag = nullptr;
			e->SuppressKeyPress = true;
		}
	}



	private: System::Void ClassCircle_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::Drawing::Size btnSize(120, 40);
		int startX = 50, startY = 50;
		int step = 30;
		System::Drawing::Point pos;
		bool found = false;

		// Try to find a free spot
		for (int i = 0; i < 100 && !found; ++i)
		{
			pos = System::Drawing::Point(startX + step * i, startY + step * i);
			System::Drawing::Rectangle rect(pos, btnSize);
			if (!IsButtonColliding(rect, nullptr))
				found = true;
		}
		if (!found)
		{
			MessageBox::Show("No free space to place a new class button.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		System::Windows::Forms::Button^ newButton = gcnew System::Windows::Forms::Button();
		newButton->Text = L"New Class";
		newButton->Size = btnSize;
		newButton->Location = pos;
		newButton->BackColor = System::Drawing::Color::FromArgb(60, 120, 200);
		newButton->ForeColor = System::Drawing::Color::White;
		newButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;

		// Add move/rename handlers
		newButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::MoveableButton_MouseDown);
		newButton->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::MoveableButton_MouseMove);
		newButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VNTS_Canvas::MoveableButton_MouseUp);
		newButton->Click += gcnew System::EventHandler(this, &VNTS_Canvas::MoveableButton_Click);

		this->canvas->Controls->Add(newButton);
		classButtons->Add(newButton);
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
			int dx = e->X - lastMousePosition.X;
			int dy = e->Y - lastMousePosition.Y;

			// Pan by adjusting the scroll position (which now acts as pan offset)
			int newScrollX = -this->canvas->AutoScrollPosition.X - dx;
			int newScrollY = -this->canvas->AutoScrollPosition.Y - dy;
			this->canvas->AutoScrollPosition = System::Drawing::Point(newScrollX, newScrollY);

			lastMousePosition = e->Location;
			this->canvas->Invalidate();
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



	//******************************** - SCROLLING - **************************************
	private: System::Void Canvas_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		float oldZoom = zoomScale;
		//if (e->Delta > 0 && zoomScale < 2.0f)
			//zoomScale += 0.1f;
		//else if (e->Delta < 0 && zoomScale > 1.0f)
			//zoomScale -= 0.1f;

		if (zoomScale != oldZoom)
		{
			// Optionally, adjust scroll position to keep mouse position stable
			this->canvas->Invalidate(); // Redraw canvas
		}
	}
	//***********************************************************************************


















	


	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}
	private: System::Void toolboxBackground_Click(System::Object^ sender, System::EventArgs^ e)
	{

	}



	};


}



