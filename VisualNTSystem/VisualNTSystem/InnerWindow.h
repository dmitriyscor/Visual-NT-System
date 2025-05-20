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
	public:
		InnerWindow(System::String^ windowTitle)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			InitializeComponent();
			this->Text = windowTitle;

			// Add a non-editable label for the title
			Label^ titleLabel = gcnew Label();
			titleLabel->Text = windowTitle;
			titleLabel->Font = gcnew System::Drawing::Font(L"Candara Light", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 0);
			titleLabel->ForeColor = System::Drawing::Color::FromArgb(28, 44, 54);
			titleLabel->Location = System::Drawing::Point(20, 10);
			titleLabel->AutoSize = true;
			this->Controls->Add(titleLabel);

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
	private: System::Windows::Forms::PictureBox^ toolboxBackground;
	private: System::Windows::Forms::Label^ objects;
	private: System::Windows::Forms::PictureBox^ canvasHeader;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InnerWindow::typeid));
			this->toolboxBackground = (gcnew System::Windows::Forms::PictureBox());
			this->objects = (gcnew System::Windows::Forms::Label());
			this->canvasHeader = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->toolboxBackground))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvasHeader))->BeginInit();
			this->SuspendLayout();
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
			this->canvasHeader->TabIndex = 4;
			this->canvasHeader->TabStop = false;
			// 
			// InnerWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(960, 640);
			this->Controls->Add(this->objects);
			this->Controls->Add(this->canvasHeader);
			this->Controls->Add(this->toolboxBackground);
			this->Name = L"InnerWindow";
			this->Text = L"InnerWindow";
			this->Load += gcnew System::EventHandler(this, &InnerWindow::InnerWindow_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->toolboxBackground))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->canvasHeader))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void InnerWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
