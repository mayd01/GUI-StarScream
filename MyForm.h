#pragma once

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Diagnostics::EventLog^ eventLog1;
	public:
	protected:

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->eventLog1 = (gcnew System::Diagnostics::EventLog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eventLog1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->AccessibleName = L"pictureBox1";
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(951, 797);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// eventLog1
			// 
			this->eventLog1->SynchronizingObject = this;
			this->eventLog1->EntryWritten += gcnew System::Diagnostics::EntryWrittenEventHandler(this, &MyForm::eventLog1_EntryWritten);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(951, 797);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Radar";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eventLog1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;

		// Clear the pictureBox1
		g->Clear(Color::Black);

		// Calculate the center point and radius of the circle
		int centerX = pictureBox1->Width / 2;
		int centerY = pictureBox1->Height / 2;
		int radius = Math::Min(centerX, centerY) - 10;

		// Draw the circle
		Pen^ circlePen = gcnew Pen(Color::Green, 2);
		g->DrawEllipse(circlePen, centerX - radius, centerY - radius, radius * 2, radius * 2);
		delete circlePen;

		// Draw the rotating line
		Pen^ linePen = gcnew Pen(Color::Lime, 3);
		int lineX = centerX + (int)(radius * Math::Sin(scanAngle));
		int lineY = centerY - (int)(radius * Math::Cos(scanAngle));
		g->DrawLine(linePen, centerX, centerY, lineX, lineY);
		delete linePen;

		// Generate random targets
		UpdateTargets(centerX, centerY, radius, g);

		// Increment the scan angle
		scanAngle += scanAngleStep;
		if (scanAngle >= 2 * Math::PI)
		{
			scanAngle = 0;
		}

	}

	private:
		void UpdateTargets(int centerX, int centerY, int radius, Graphics^ g) {
			Random^ rand = gcnew Random();
			int numTargets = rand->Next(5);  // generate up to 5 targets
			Brush^ targetBrush = gcnew SolidBrush(Color::Red);
			for (int i = 0; i < numTargets; i++)
			{
				// Generate random target coordinates within the radar circle
				int targetX = centerX + (int)(rand->NextDouble() * radius * Math::Sin(2 * Math::PI * rand->NextDouble()));
				int targetY = centerY - (int)(rand->NextDouble() * radius * Math::Cos(2 * Math::PI * rand->NextDouble()));
				int targetSize = 5;  // size of the target in pixels

				// Determine target speed and direction
				double targetSpeed = rand->NextDouble() * 2 + 1;  // speed between 1 and 3 pixels per frame
				double targetAngle = 2 * Math::PI * rand->NextDouble();  // angle between 0 and 2*pi radians

				// Update target position based on speed and direction
				targetX += (int)(targetSpeed * Math::Sin(targetAngle));
				targetY -= (int)(targetSpeed * Math::Cos(targetAngle));

				// Draw the target as a small circle or dot
				g->FillEllipse(targetBrush, targetX - targetSize / 2, targetY - targetSize / 2, targetSize, targetSize);
			}
			delete targetBrush;
		}

	
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
		   private:
			   double scanAngle = 0;
			   double scanAngleStep = Math::PI / 180;  // 1 degree step
	private: System::Void eventLog1_EntryWritten(System::Object^ sender, System::Diagnostics::EntryWrittenEventArgs^ e) {
	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::Timer^ timer = gcnew System::Windows::Forms::Timer();
	timer->Interval = 50;  // 50 milliseconds per frame
	timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
	timer->Start();
}
	   private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		   // Trigger a redraw of the pictureBox1 control to update the radar sweep
		   pictureBox1->Invalidate();
	   }
};

}