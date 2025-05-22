#pragma once

namespace VisualNTSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for InnerWindow
	/// </summary>
	public ref class InnerWindow : public System::Windows::Forms::Form
	{
	private:
		System::Windows::Forms::Panel^ canvas;
		float zoomScale = 1.0f;
		Bitmap^ originalImage; //for scrolling the canvas
		bool isDragging = false;
		System::Drawing::Point lastMousePosition;
		System::Windows::Forms::TextBox^ CanvasName;
		Bitmap^ canvasBackground;

	private:
		System::Collections::Generic::List<System::Windows::Forms::Button^>^ noteButtons;
		System::Windows::Forms::TextBox^ renameTextBox;
		System::Windows::Forms::TextBox^ valueTextBox;
		System::Windows::Forms::Button^ lastClickedButton;
		System::Windows::Forms::Timer^ clickTimer;
		int clickDelayMs = 200;
		bool awaitingSecondClick = false;
		System::Collections::Generic::Dictionary<System::Windows::Forms::Button^, System::String^>^ noteValues;


	public:
		InnerWindow() : InnerWindow("InnerWindow") {}

		InnerWindow(System::String^ windowTitle)
		{
			InitializeComponent(windowTitle);
			//
			//TODO: Add the constructor code here
			//
			

			this->AllowDrop = true;


			//move
			this->canvas->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &InnerWindow::Canvas_MouseDown);
			this->canvas->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &InnerWindow::Canvas_MouseMove);
			this->canvas->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &InnerWindow::Canvas_MouseUp);

			this->canvas->Paint += gcnew PaintEventHandler(this, &InnerWindow::Canvas_Paint);


			noteButtons = gcnew System::Collections::Generic::List<System::Windows::Forms::Button^>();
			noteValues = gcnew System::Collections::Generic::Dictionary<System::Windows::Forms::Button^, System::String^>();
			clickTimer = gcnew System::Windows::Forms::Timer();
			clickTimer->Interval = clickDelayMs;
			clickTimer->Tick += gcnew System::EventHandler(this, &InnerWindow::ClickTimer_Tick);



		}
	
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InnerWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ titleLabel;
	private: System::Windows::Forms::PictureBox^ toolboxBackground;
	private: System::Windows::Forms::Label^ objects;
	private: System::Windows::Forms::PictureBox^ canvasHeader;
	private: System::Windows::Forms::Button^ SaveButton;
	private: System::Windows::Forms::Button^ SaveAndExitButton;
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
		void InitializeComponent(System::String^ windowTitle)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InnerWindow::typeid));
			this->titleLabel = gcnew System::Windows::Forms::Label();
			this->toolboxBackground = (gcnew System::Windows::Forms::PictureBox());
			this->objects = (gcnew System::Windows::Forms::Label());
			this->canvasHeader = (gcnew System::Windows::Forms::PictureBox());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->SaveAndExitButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->toolboxBackground))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvasHeader))->BeginInit();
			this->SuspendLayout();
			//
			// label (canvas->class name)
			//
			this->Text = windowTitle;
			titleLabel->Text = windowTitle;
			titleLabel->Font = gcnew System::Drawing::Font(L"Candara Light", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 0);
			titleLabel->ForeColor = System::Drawing::Color::FromArgb(28, 44, 54);
			titleLabel->TabIndex = 0;
			titleLabel->Location = System::Drawing::Point(200, 6);
			titleLabel->AutoSize = true;
			// 
			// toolboxBackground
			// 
			this->toolboxBackground->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolboxBackground.Image")));
			this->toolboxBackground->Location = System::Drawing::Point(-1, 1);
			this->toolboxBackground->Name = L"toolboxBackground";
			this->toolboxBackground->Size = System::Drawing::Size(200, 640);
			this->toolboxBackground->TabIndex = 1;
			this->toolboxBackground->TabStop = false;
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
			this->objects->TabIndex = 5;
			this->objects->Text = L"Objects";
			// 
			// canvasHeader
			// 
			this->canvasHeader->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"canvasHeader.Image")));
			this->canvasHeader->Location = System::Drawing::Point(-1, 1);
			this->canvasHeader->Name = L"canvasHeader";
			this->canvasHeader->Size = System::Drawing::Size(960, 50);
			this->canvasHeader->TabIndex = 1;
			this->canvasHeader->TabStop = false;
			//
			// Note Button 
			//
			System::Windows::Forms::Button^ noteButton = gcnew System::Windows::Forms::Button();
			noteButton->Text = L"Note";
			noteButton->Location = System::Drawing::Point(20, 50);
			noteButton->Size = System::Drawing::Size(160, 40);
			noteButton->BackColor = System::Drawing::Color::FromArgb(60, 120, 200);
			noteButton->ForeColor = System::Drawing::Color::White;
			noteButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			noteButton->Click += gcnew System::EventHandler(this, &InnerWindow::NoteButton_Click);
			this->Controls->Add(noteButton);
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
			this->SaveButton->Location = System::Drawing::Point(918, 12);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(30, 30);
			this->SaveButton->TabIndex = 6;
			this->SaveButton->UseVisualStyleBackColor = false;
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
			this->SaveAndExitButton->Location = System::Drawing::Point(-1, 571);
			this->SaveAndExitButton->Name = L"SaveAndExitButton";
			this->SaveAndExitButton->Padding = System::Windows::Forms::Padding(1);
			this->SaveAndExitButton->Size = System::Drawing::Size(200, 70);
			this->SaveAndExitButton->TabIndex = 11;
			this->SaveAndExitButton->Text = L"Save And Go Back";
			this->SaveAndExitButton->UseVisualStyleBackColor = false;
			this->SaveButton->Click += gcnew System::EventHandler(this, &InnerWindow::SaveButton_Click);

			// 
			// canvas
			// 
			this->canvas = gcnew System::Windows::Forms::Panel();
			this->canvas->AutoScroll = true;
			this->canvas->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"canvas.BackgroundImage")));
			this->canvas->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->canvas->Location = System::Drawing::Point(200, 50);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(769, 592);
			this->canvas->TabIndex = 4;

			this->canvas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &InnerWindow::Canvas_Paint);
			this->canvas->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &InnerWindow::Canvas_MouseDown);
			this->canvas->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &InnerWindow::Canvas_MouseMove);
			this->canvas->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &InnerWindow::Canvas_MouseUp);
			this->canvas->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &InnerWindow::Canvas_MouseWheel);

			// 
			// InnerWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(960, 640);
			this->Controls->Add(titleLabel);
			this->Controls->Add(this->SaveAndExitButton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->objects);
			this->Controls->Add(this->canvasHeader);
			this->Controls->Add(this->toolboxBackground);
			this->Controls->Add(this->canvas);
			this->Name = L"InnerWindow";
			this->Text = L"InnerWindow";
			this->Load += gcnew System::EventHandler(this, &InnerWindow::InnerWindow_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->toolboxBackground))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvasHeader))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

	private: System::Void InnerWindow_Load(System::Object^ sender, System::EventArgs^ e)
	{
		// Set up the canvas (size, background, etc.)
		this->canvas->AutoScrollMinSize = System::Drawing::Size(4096, 4096);

		// Optionally load a background image
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InnerWindow::typeid));
		this->canvasBackground = (cli::safe_cast<System::Drawing::Bitmap^>(resources->GetObject(L"canvas.BackgroundImage")));



		// Get the class name from the window title (or pass it as a parameter)
		System::String^ className = this->Text; // Or use a dedicated field

		// Build the filename for this class's data
		System::String^ classFile = className + ".txt";

		if (System::IO::File::Exists(classFile))
		{
			System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(classFile);

			// Example: read variable count
			int variableCount = System::Convert::ToInt32(reader->ReadLine());

			for (int i = 0; i < variableCount; ++i)
			{
				System::String^ varName = reader->ReadLine();
				System::String^ varValue = reader->ReadLine();

				// TODO: Create controls to display/edit these variables
				// For example, add a label and a textbox for each variable
				System::Windows::Forms::Label^ lbl = gcnew System::Windows::Forms::Label();
				lbl->Text = varName;
				lbl->Location = System::Drawing::Point(20, 40 + i * 30);
				lbl->AutoSize = true;

				System::Windows::Forms::TextBox^ txt = gcnew System::Windows::Forms::TextBox();
				txt->Text = varValue;
				txt->Location = System::Drawing::Point(120, 40 + i * 30);
				txt->Width = 200;

				this->canvas->Controls->Add(lbl);
				this->canvas->Controls->Add(txt);
			}

			reader->Close();
		}
		else
		{
			// No data file for this class yet; optionally show a message or leave blank
			Console::WriteLine("No variable data found for this class.");
		}
	}


	 //************************************** - Create Canvas - *********************************************
	private: System::Void Canvas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		if (canvasBackground != nullptr)
		{
			int scrollX = -this->canvas->AutoScrollPosition.X;
			int scrollY = -this->canvas->AutoScrollPosition.Y;

			

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

	//***********************************************************************************
	//---------------------MOVE---------------------------- #1
	//*********************************************************************************** 

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
		

		if (zoomScale != oldZoom)
		{
			// Optionally, adjust scroll position to keep mouse position stable
			this->canvas->Invalidate(); // Redraw canvas
		}
	}
	//***********************************************************************************



	bool isNoteDragging = false;
	System::Drawing::Point noteDragOffset;
	System::Windows::Forms::Button^ draggingNote = nullptr;



	private: System::Void NoteButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::Windows::Forms::Button^ note = gcnew System::Windows::Forms::Button();
		note->Text = L"New Note";
		note->Size = System::Drawing::Size(120, 40);
		note->Location = System::Drawing::Point(250, 100 + noteButtons->Count * 50);
		note->BackColor = System::Drawing::Color::FromArgb(60, 120, 200);
		note->ForeColor = System::Drawing::Color::White;
		note->FlatStyle = System::Windows::Forms::FlatStyle::Flat;

		note->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &InnerWindow::Note_MouseDown);
		note->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &InnerWindow::Note_MouseMove);
		note->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &InnerWindow::Note_MouseUp);
		note->Click += gcnew System::EventHandler(this, &InnerWindow::Note_Click);

		this->canvas->Controls->Add(note);
		noteButtons->Add(note);
		noteValues[note] = "";
	}


	private: System::Void Note_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			isNoteDragging = true;
			draggingNote = safe_cast<System::Windows::Forms::Button^>(sender);
			noteDragOffset = e->Location;
			draggingNote->Cursor = Cursors::Hand;
		}
	}

	private: System::Void Note_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (isNoteDragging && draggingNote != nullptr)
		{
			System::Drawing::Point newLocation = draggingNote->Location;
			newLocation.X += e->X - noteDragOffset.X;
			newLocation.Y += e->Y - noteDragOffset.Y;
			draggingNote->Location = newLocation;
		}
	}

	private: System::Void Note_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (e->Button == System::Windows::Forms::MouseButtons::Left && draggingNote != nullptr)
		{
			isNoteDragging = false;
			draggingNote->Cursor = Cursors::Default;
			draggingNote = nullptr;
		}
	}

	private: System::Void Note_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::Windows::Forms::Button^ btn = safe_cast<System::Windows::Forms::Button^>(sender);

		if (awaitingSecondClick && lastClickedButton == btn)
		{
			// Double click: edit value
			awaitingSecondClick = false;
			clickTimer->Stop();
			lastClickedButton = nullptr;
			ShowValueTextBox(btn);
		}
		else
		{
			// First click: start timer and wait for possible double-click
			awaitingSecondClick = true;
			lastClickedButton = btn;
			clickTimer->Stop();
			clickTimer->Start();
		}
	}

	private: System::Void ClickTimer_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		clickTimer->Stop();
		if (awaitingSecondClick && lastClickedButton != nullptr)
		{
			// Timer expired, treat as single double-click (rename)
			ShowRenameTextBox(lastClickedButton);
		}
		awaitingSecondClick = false;
		lastClickedButton = nullptr;
	}

	private: void ShowRenameTextBox(System::Windows::Forms::Button^ btn)
	{
		if (renameTextBox == nullptr)
		{
			renameTextBox = gcnew System::Windows::Forms::TextBox();
			renameTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			renameTextBox->Font = btn->Font;
			renameTextBox->Leave += gcnew System::EventHandler(this, &InnerWindow::RenameTextBox_Leave);
			renameTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &InnerWindow::RenameTextBox_KeyDown);
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

private: void ShowValueTextBox(System::Windows::Forms::Button^ btn)
{
	if (valueTextBox == nullptr)
	{
		valueTextBox = gcnew System::Windows::Forms::TextBox();
		valueTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		valueTextBox->Font = btn->Font;
		valueTextBox->Leave += gcnew System::EventHandler(this, &InnerWindow::ValueTextBox_Leave);
		valueTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &InnerWindow::ValueTextBox_KeyDown);
		this->canvas->Controls->Add(valueTextBox);
	}
	valueTextBox->Location = System::Drawing::Point(btn->Location.X, btn->Location.Y + btn->Height);
	valueTextBox->Size = btn->Size;
	valueTextBox->Text = noteValues[btn];
	valueTextBox->Tag = btn;
	valueTextBox->Visible = true;
	valueTextBox->BringToFront();
	valueTextBox->Focus();
	valueTextBox->SelectAll();
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

	private: System::Void ValueTextBox_Leave(System::Object^ sender, System::EventArgs^ e)
	{
		if (valueTextBox->Tag != nullptr)
		{
			System::Windows::Forms::Button^ btn = safe_cast<System::Windows::Forms::Button^>(valueTextBox->Tag);
			noteValues[btn] = valueTextBox->Text;
		}
		valueTextBox->Visible = false;
		valueTextBox->Tag = nullptr;
	}

	private: System::Void ValueTextBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		if (e->KeyCode == System::Windows::Forms::Keys::Enter)
		{
			ValueTextBox_Leave(sender, e);
			e->SuppressKeyPress = true;
		}
		else if (e->KeyCode == System::Windows::Forms::Keys::Escape)
		{
			valueTextBox->Visible = false;
			valueTextBox->Tag = nullptr;
			e->SuppressKeyPress = true;
		}
	}







	//******************************************SAVE FUNCTION*******************************
	private: System::Void SaveButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		int scrollX = -this->canvas->AutoScrollPosition.X;
		int scrollY = -this->canvas->AutoScrollPosition.Y;
		System::String^ canvasName = this->Text;

		System::String^ classFile = canvasName + ".txt";
		System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(classFile);

		writer->WriteLine(scrollX);
		writer->WriteLine(scrollY);
		writer->WriteLine(zoomScale);
		writer->WriteLine(canvasName);

		for each (System::Windows::Forms::Button ^ btn in noteButtons)
		{
			writer->WriteLine(btn->Text);
			writer->WriteLine("{");
			writer->WriteLine("x=" + btn->Location.X.ToString());
			writer->WriteLine("y=" + btn->Location.Y.ToString());
			writer->WriteLine("value=" + noteValues[btn]);
			writer->WriteLine("}");
		}
		writer->WriteLine("end");
		writer->Close();

		MessageBox::Show("Inner window saved!", "Save", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}








	};


}
