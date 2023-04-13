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
			
			int prevTargetX = 0;
			int prevTargetY = 0;
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
			this->pictureBox1->Size = System::Drawing::Size(1086, 792);
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
			this->ClientSize = System::Drawing::Size(1086, 792);
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
		int prevTargetX = 0;
		int prevTargetY = 0;
	private: Timer^ flashTimer = gcnew Timer();  // Tir for flashing inner circle
		   
		   bool flashState = false;
		System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;

		// Clear the pictureBox1
		g->Clear(Color::White);
		
		// Calculate the center point and radius of the circle
		int centerX = pictureBox1->Width / 2;
		int centerY = pictureBox1->Height / 2;
		int radius = Math::Min(centerX, centerY) - 10;
		int innerRadius = radius - 150;
		int tooclose = radius - 100;
		int secondRadius = radius - 50;
		// Draw the circle
		Pen^ circlePen = gcnew Pen(Color::Gray, 2);
		Pen^ innerCirclePen = gcnew Pen(Color::Red, .5);
		Pen^ firstCirclePen = gcnew Pen(Color::Gray, .5);
		Pen^ innermostCirclePen = gcnew Pen(Color::Gray, .5);
		Pen^ vlinePen = gcnew Pen(Color::Gray, 2);
		Pen^ hlinePen = gcnew Pen(Color::Gray, 2);
		Brush^ circleBrush = gcnew SolidBrush(Color::Black);
		int innerCircleX = centerX - radius;
		int innerCircleY = centerY - radius;
		int innerCircleDiameter = radius * 2;
		g->FillEllipse(circleBrush, innerCircleX, innerCircleY, innerCircleDiameter, innerCircleDiameter);
		delete circleBrush;
		g->DrawLine(vlinePen, centerX, centerY - radius, centerX, centerY + radius);
		g->DrawEllipse(circlePen, centerX - radius, centerY - radius, radius * 2, radius * 2);
		g->DrawLine(hlinePen, centerX - radius, centerY, centerX + radius, centerY);
		g->DrawEllipse(innermostCirclePen, centerX - tooclose, centerY - tooclose, tooclose * 2, tooclose * 2);
		g->DrawEllipse(firstCirclePen, centerX - secondRadius, centerY - secondRadius, secondRadius * 2, secondRadius * 2);
		if (flashState) {
			g->DrawEllipse(innerCirclePen, centerX - innerRadius, centerY - innerRadius, innerRadius * 2, innerRadius * 2);
		}
		flashState = !flashState;
		delete circlePen;
		delete innerCirclePen;
		delete vlinePen;
		delete hlinePen;
		
		// Draw the rotating line
		Pen^ linePen = gcnew Pen(Color::Lime, 3);
		int lineX = centerX + (int)(radius * Math::Sin(scanAngle));
		int lineY = centerY - (int)(radius * Math::Cos(scanAngle));
		g->DrawLine(linePen, centerX, centerY, lineX, lineY);
		delete linePen;

		// Generate random targets
		UpdateTargets(centerX, centerY, radius, g);
		
		// Add light trail behind the rotating line
		Color lightColor = Color::LightGreen;
		int lightTrailLength = 50;  // number of frames the light trail should last
		double lightTrailOpacity = 1.0;  // opacity of the light trail
		int trailStartX = centerX + (int)(radius * Math::Sin(scanAngle - scanAngleStep * lightTrailLength));
		int trailStartY = centerY - (int)(radius * Math::Cos(scanAngle - scanAngleStep * lightTrailLength));
		int trailEndX = centerX + (int)(radius * Math::Sin(scanAngle));
		int trailEndY = centerY - (int)(radius * Math::Cos(scanAngle));
		for (int i = 0; i < lightTrailLength; i++)
		{
			double trailOpacity = lightTrailOpacity - lightTrailOpacity * (double)i / lightTrailLength;
			Color trailColor = Color::FromArgb((int)(255 * trailOpacity), lightColor);
			Pen^ trailPen = gcnew Pen(trailColor, 3);
			int trailX1 = centerX + (int)(radius * Math::Sin(scanAngle - scanAngleStep * (lightTrailLength - i)));
			int trailY1 = centerY - (int)(radius * Math::Cos(scanAngle - scanAngleStep * (lightTrailLength - i)));
			int trailX2 = centerX + (int)(radius * Math::Sin(scanAngle - scanAngleStep * (lightTrailLength - i - 1)));
			int trailY2 = centerY - (int)(radius * Math::Cos(scanAngle - scanAngleStep * (lightTrailLength - i - 1)));
			g->DrawLine(trailPen, trailX1, trailY1, trailX2, trailY2);
			delete trailPen;
		}

		// Increment the scan angle
		scanAngle += scanAngleStep;
		if (scanAngle >= 2 * Math::PI)
		{
			scanAngle = 0;
		}

	}
private:
	double prevScanAngle; // variable to store the previous scan angle
	int updateCounter = 0; // variable to count the number of updates
	int targetX, targetY; // variables to store the target coordinates
	double targetDirection; // variable to store the target direction
	double targetVelocity = 2.0; // variable to store the target velocity
	bool targetInitialized = false; // variable to check if the target is initialized

	void UpdateTargets(int centerX, int centerY, int radius, Graphics^ g) {
		Random^ rand = gcnew Random();
		Brush^ targetBrush = gcnew SolidBrush(Color::Red);

		// Initialize the target with random coordinates
		if (!targetInitialized) {
			do {
				targetX = centerX + rand->Next(-radius, radius);
				targetY = centerY + rand->Next(-radius, radius);
			} while (Math::Sqrt(Math::Pow(targetX - centerX, 2) + Math::Pow(targetY - centerY, 2)) > radius);

			targetDirection = rand->Next(360);
			targetInitialized = true;
		}

		// Update the target coordinates based on its velocity and direction
		targetX += targetVelocity * Math::Cos(targetDirection * Math::PI / 180);
		targetY += targetVelocity * Math::Sin(targetDirection * Math::PI / 180);

		// Draw the target only if it is within the radar circle
		if (Math::Sqrt(Math::Pow(targetX - centerX, 2) + Math::Pow(targetY - centerY, 2)) <= radius) {
			g->FillEllipse(targetBrush, targetX - 5, targetY - 5, 10, 10);
		}

		// Only update the target every second
		if (updateCounter % 60 == 0) {
			// Generate new random target direction
			targetDirection = rand->Next(360);
		}

		delete targetBrush;

		// Increment the update counter
		updateCounter++;
	}


	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
		   private:
			   double scanAngle = 0;
			   double scanAngleStep = Math::PI / 75;  // 1 degree step
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
		  
	private:  System::Void flashTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
				  flashState = !flashState;
				  pictureBox1->Invalidate();
			  }
	
};

}