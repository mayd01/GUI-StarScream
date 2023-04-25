#pragma once
#include "popup.h"
#include "popup2.h"
#include <cmath>
#include <list>
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
		System::Windows::Forms::RichTextBox^ logBox;
	public:
		MyForm(void)
		{
			
			InitializeComponent();
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			bool currentTargetHit;
			int prevTargetX = 0;
			int prevTargetY = 0;
			logText = "";
			
			//TODO: Add the constructor code here
			//
			
		}
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ Label5;

	public:

	public:
	private:
		System::String^ logText;
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

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ProgressBar^ progressBar1;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
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
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::SystemColors::Control;
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(134, 67);
			this->button1->TabIndex = 1;
			this->button1->Text = L"On/OFF";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->Location = System::Drawing::Point(11, 85);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(135, 71);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Arm StarScream";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button3->Location = System::Drawing::Point(12, 162);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(134, 71);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Intercept";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->trackBar1->LargeChange = 10;
			this->trackBar1->Location = System::Drawing::Point(17, 276);
			this->trackBar1->Maximum = 40;
			this->trackBar1->Minimum = 10;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBar1->Size = System::Drawing::Size(69, 344);
			this->trackBar1->SmallChange = 5;
			this->trackBar1->TabIndex = 4;
			this->trackBar1->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->trackBar1->UseWaitCursor = true;
			this->trackBar1->Value = 30;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(12, 248);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 25);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Fuel Amount";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(0, 766);
			this->progressBar1->Maximum = 10;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(1086, 26);
			this->progressBar1->TabIndex = 6;
			this->progressBar1->Click += gcnew System::EventHandler(this, &MyForm::progressBar1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::LightGreen;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(831, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 29);
			this->label2->TabIndex = 7;
			this->label2->Text = L"label2";
			this->label2->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::LightGreen;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(832, 69);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 26);
			this->label3->TabIndex = 8;
			this->label3->Text = L"label3";
			this->label3->Visible = false;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Red;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::Firebrick;
			this->textBox1->Location = System::Drawing::Point(836, 114);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 32);
			this->textBox1->TabIndex = 9;
			this->textBox1->Visible = false;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged_1);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::Window;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(11, 720);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 26);
			this->label4->TabIndex = 10;
			this->label4->Text = L"label4";
			this->label4->Visible = false;
			// 
			// Label5
			// 
			this->Label5->AutoSize = true;
			this->Label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label5->Location = System::Drawing::Point(909, 567);
			this->Label5->Name = L"Label5";
			this->Label5->Size = System::Drawing::Size(95, 36);
			this->Label5->TabIndex = 11;
			this->Label5->Text = L"label5";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::MenuText;
			this->ClientSize = System::Drawing::Size(1086, 792);
			this->Controls->Add(this->Label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Radar";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
			
		int prevTargetX = 0;
		int prevTargetY = 0;
		int missileX = 0;
		int missileY = 0;
		int missileSpeed = 10;
		int missileAngle = 0;
	private: Timer^ flashTimer = gcnew Timer();  // Tir for flashing inner circle
		   
		   bool flashState = false;
		System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;

		if (!radarOn) {
			return;
		}
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
		if (ArmOn) {
			if (flashState) {
				g->DrawEllipse(innerCirclePen, centerX - innerRadius, centerY - innerRadius, innerRadius * 2, innerRadius * 2);
			}
		}
		if (missileLaunched) {
			g->FillEllipse(Brushes::Blue, missileX - 5, missileY - 5, 5, 5);
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
		   scanAngle += scanAngleStep;
		   if (scanAngle >= Math::PI * 2)
		   {
			   scanAngle -= Math::PI * 2;
		   }

		   // Update the missile
		   if (missileLaunched)
		   {
			   UpdateMissile();
		   }
		   
		   // Redraw the pictureBox1
		   pictureBox1->Invalidate();
	   }
		  
	private:  System::Void flashTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
				  flashState = !flashState;
				  pictureBox1->Invalidate();
			  }
	
private:bool radarOn = false; System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (radarOn) {
		// Stop the radar
		flashTimer->Stop();
		radarOn = false;
		label2->Visible = false;
	}
	else {
		// Start the radar
		flashTimer->Interval = 100; // set the interval in milliseconds
		flashTimer->Start();
		radarOn = true;
		label2->Text = "StarScream is Active";
		label2->Visible = true;
	}
}
private:
	void StartRadar() {
		// Start the radar
		flashTimer->Interval = 100; // set the interval in milliseconds
		flashTimer->Start();
		radarOn = true;
	}

private:
	void StopRadar() {
		// Stop the radar
		flashTimer->Stop();
		radarOn = false;
	}

private: bool ArmOn = false; System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ArmOn) {
		flashTimer->Stop();
		ArmOn = false;
		label3->Text = "Interceptors are OFF";
		label3->Visible = true;
	}
	else {
		flashTimer->Interval = 100;
		flashTimer->Start();
		ArmOn = true;
		label3->Text = "Interceptors are ON";
		label3->Visible = true;
	}
}
	   private:
		   void StartArm() {
			   flashTimer->Interval = 100;
			   flashTimer->Start();
			   ArmOn = true;
		   }
		private:
			void StopArm() {
				flashTimer->Stop();
				ArmOn = false;
			}
private:
	Color flashColor = Color::Black;
	
 private:  
	 int interceptorsRemaining = 10;
		bool missileLaunched = false; double M_PI = 3.29;  System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			if (!ArmOn) {
				MessageBox::Show("Must Arm StarScream");
				
	 }
			if (missileLaunched) {
				
		 return;
	 }

	 missileLaunched = true;
	 missileX = pictureBox1->Width / 2;
	 missileY = pictureBox1->Height / 2;
	 int targetX = prevTargetX;
	 int targetY = prevTargetY;
	 missileAngle = atan2(targetY - missileY, targetX - missileX) * 180 / M_PI;
	 interceptorsRemaining--;
	 progressBar1->Value = interceptorsRemaining;
	 label4->Text = "Interceptors Remaining" + " " + interceptorsRemaining.ToString();
	 label4->Visible = true;
	 if (interceptorsRemaining == 0) {
		 MessageBox::Show("You are out of interceptors Good Luck!");

	 }
	 
	 
 }

	   double Distance(int x1, int y1, int x2, int y2)
	   {
		   int dx = x2 - x1;
		   int dy = y2 - y1;
		   return Math::Sqrt(dx * dx + dy * dy);
	   }
	   int turnCount = 0;
	   bool targetHit = false;
	   bool currentTargetHit;
	   void UpdateMissile()
	   {
		   
		   // Calculate the distance to the target
		   double distance = Distance(missileX, missileY, targetX, targetY);

		   // Adjust the missile's angle and speed
		   double dx = targetX - missileX;
		   double dy = targetY - missileY;
		   missileAngle = (int)(Math::Atan2(dy, dx) * 180 / Math::PI);
		   missileSpeed = (int)(distance / 5);

		   // Move the missile
		   missileX += (int)(missileSpeed * Math::Cos(missileAngle * Math::PI / 180));
		   missileY += (int)(missileSpeed * Math::Sin(missileAngle * Math::PI / 180));

		   if (missileLaunched) {
			   if (currentTargetHit) {
				   turnCount = 0;
				   currentTargetHit = false;
			   }
			   else {
				   turnCount++;
			   }
		   }
		   
		   // Check if missile has hit the target
		   if (Distance(missileX, missileY, targetX, targetY) < 10)
		   {
			   missileLaunched = false;
			   currentTargetHit = true;
			   Project2::popup^ popup = gcnew Project2::popup();
			   popup->Show();
			   
			   GenerateTarget();
		   }

		   // Check if missile has run out of fuel
		   if (turnCount >= fuelLevel && !currentTargetHit) {
			   missileLaunched = false;
			   
			   Project2::popup2^ popup2 = gcnew Project2::popup2();
			   popup2->Show();
			   GenerateTarget();
			   turnCount = 0;
		   }
	   }

	   private:
		   void GenerateTarget()
		   {
			   // Generate a new target at a random location
			   Random^ rand = gcnew Random();
			   targetX = rand->Next(pictureBox1->Width - 20) + 10;
			   targetY = rand->Next(pictureBox1->Height - 20) + 10;

			   currentTargetHit = false;
			   // Update the previous target location
			   prevTargetX = targetX;
			   prevTargetY = targetY;
			   System::Threading::Thread::Sleep(500);

			   // Redraw the pictureBox1
			   pictureBox1->Invalidate();

		   }

	   private: System::Void flashTimer_Tick_Target(System::Object^ sender, System::EventArgs^ e) {
		   flashState = !flashState;
		   pictureBox1->Invalidate();
	   }
			  int fuelLevel;
private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
	int newFuelLevel = trackBar1->Value;

	fuelLevel = newFuelLevel;
}
private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {
}
	   private:
		   double prevScanAngle; // variable to store the previous scan angle
		   int updateCounter = 0; // variable to count the number of updates
		   int targetX, targetY; // variables to store the target coordinates
		   double targetDirection; // variable to store the target direction
		   double targetVelocity = 2.0; // variable to store the target velocity
		   bool targetInitialized = false; // variable to check if the target is initialized
		   bool targetDestroyed = false; // variable to check if the target is destroyed

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

			   // Keep the target within the circle by reflecting it off the edges
			   if (Math::Sqrt(Math::Pow(targetX - centerX, 2) + Math::Pow(targetY - centerY, 2)) > radius) {
				   double angle = Math::Atan2(targetY - centerY, targetX - centerX);
				   targetX = centerX + radius * Math::Cos(angle);
				   targetY = centerY + radius * Math::Sin(angle);
				   targetDirection = rand->Next(360);
			   }

			   // Draw the target only if it is within the radar circle and not destroyed
			   if (!targetDestroyed && Math::Sqrt(Math::Pow(targetX - centerX, 2) + Math::Pow(targetY - centerY, 2)) <= radius) {
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
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
};

}