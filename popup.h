#pragma once

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for popup
	/// </summary>
	public ref class popup : public System::Windows::Forms::Form
	{
	public:
		popup(void)
		{
			InitializeComponent();
			Timer^ timer = gcnew Timer();
			timer->Interval = 3000; // 3 seconds
			timer->Tick += gcnew EventHandler(this, &popup::OnTimerTick);
			timer->Start();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~popup()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->ForeColor = System::Drawing::Color::LavenderBlush;
			this->label1->Location = System::Drawing::Point(113, 117);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(206, 40);
			this->label1->TabIndex = 0;
			this->label1->Text = L"      Target Has Been Hit.\r\nNo Longer Found On Radar";
			// 
			// popup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(435, 248);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::Color::Black;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"popup";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"StarScream ";
			this->Load += gcnew System::EventHandler(this, &popup::popup_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void popup_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void OnTimerTick(Object^ sender, EventArgs^ e) {
		// Close the form when the timer ticks
		this->Close();
	}
	};
}
