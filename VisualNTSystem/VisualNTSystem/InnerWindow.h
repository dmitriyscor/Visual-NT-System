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
			this->SuspendLayout();
			// 
			// InnerWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"InnerWindow";
			this->Text = L"InnerWindow";
			this->Load += gcnew System::EventHandler(this, &InnerWindow::InnerWindow_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void InnerWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
