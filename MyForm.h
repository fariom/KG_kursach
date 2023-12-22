#pragma once
#include "Figura.h"
#include <vector>
#define MOVE 10
#define ROTATE 20
#define SCALE 0.1

Figura pyramid(1);
Figura prism(2);
Figura* current;

std::vector<point> stack;

namespace KGkursach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			current = &pyramid;
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ picture;
	private: System::Windows::Forms::Label^ LabelCurrentAxis;
	private: System::Windows::Forms::Label^ TextCurrentAxis;
	private: System::Windows::Forms::Label^ LabelAxisChoice;
	private: System::Windows::Forms::Button^ buttonX;
	private: System::Windows::Forms::Button^ buttonY;
	private: System::Windows::Forms::Button^ buttonZ;
	private: System::Windows::Forms::Label^ labelMove;




	private: System::Windows::Forms::Label^ labelRotate;


	private: System::Windows::Forms::Label^ labelScale;



	private: System::Windows::Forms::CheckBox^ checkBoxScale;
	private: System::Windows::Forms::Button^ buttonMoveUp;
	private: System::Windows::Forms::Button^ buttonMoveLeft;
	private: System::Windows::Forms::Button^ buttonMoveDown;
	private: System::Windows::Forms::Button^ buttonMoveRight;
	private: System::Windows::Forms::Button^ buttonRotateClockwise;
	private: System::Windows::Forms::Button^ buttonRotateUnclockwise;
	private: System::Windows::Forms::Button^ buttonScaleDown;
	private: System::Windows::Forms::Button^ buttonScaleUp;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->picture = (gcnew System::Windows::Forms::PictureBox());
			this->LabelCurrentAxis = (gcnew System::Windows::Forms::Label());
			this->TextCurrentAxis = (gcnew System::Windows::Forms::Label());
			this->LabelAxisChoice = (gcnew System::Windows::Forms::Label());
			this->buttonX = (gcnew System::Windows::Forms::Button());
			this->buttonY = (gcnew System::Windows::Forms::Button());
			this->buttonZ = (gcnew System::Windows::Forms::Button());
			this->labelMove = (gcnew System::Windows::Forms::Label());
			this->labelRotate = (gcnew System::Windows::Forms::Label());
			this->labelScale = (gcnew System::Windows::Forms::Label());
			this->checkBoxScale = (gcnew System::Windows::Forms::CheckBox());
			this->buttonMoveUp = (gcnew System::Windows::Forms::Button());
			this->buttonMoveLeft = (gcnew System::Windows::Forms::Button());
			this->buttonMoveDown = (gcnew System::Windows::Forms::Button());
			this->buttonMoveRight = (gcnew System::Windows::Forms::Button());
			this->buttonRotateClockwise = (gcnew System::Windows::Forms::Button());
			this->buttonRotateUnclockwise = (gcnew System::Windows::Forms::Button());
			this->buttonScaleDown = (gcnew System::Windows::Forms::Button());
			this->buttonScaleUp = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture))->BeginInit();
			this->SuspendLayout();
			// 
			// picture
			// 
			this->picture->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->picture->Location = System::Drawing::Point(12, 12);
			this->picture->Name = L"picture";
			this->picture->Size = System::Drawing::Size(600, 600);
			this->picture->TabIndex = 0;
			this->picture->TabStop = false;
			this->picture->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::picture_Paint);
			// 
			// LabelCurrentAxis
			// 
			this->LabelCurrentAxis->AutoSize = true;
			this->LabelCurrentAxis->Location = System::Drawing::Point(635, 16);
			this->LabelCurrentAxis->Name = L"LabelCurrentAxis";
			this->LabelCurrentAxis->Size = System::Drawing::Size(76, 13);
			this->LabelCurrentAxis->TabIndex = 1;
			this->LabelCurrentAxis->Text = L"Текущая ось:";
			// 
			// TextCurrentAxis
			// 
			this->TextCurrentAxis->AutoSize = true;
			this->TextCurrentAxis->Location = System::Drawing::Point(707, 16);
			this->TextCurrentAxis->Name = L"TextCurrentAxis";
			this->TextCurrentAxis->Size = System::Drawing::Size(14, 13);
			this->TextCurrentAxis->TabIndex = 3;
			this->TextCurrentAxis->Text = L"X";
			// 
			// LabelAxisChoice
			// 
			this->LabelAxisChoice->AutoSize = true;
			this->LabelAxisChoice->Location = System::Drawing::Point(635, 40);
			this->LabelAxisChoice->Name = L"LabelAxisChoice";
			this->LabelAxisChoice->Size = System::Drawing::Size(61, 13);
			this->LabelAxisChoice->TabIndex = 4;
			this->LabelAxisChoice->Text = L"Выбор оси";
			// 
			// buttonX
			// 
			this->buttonX->Location = System::Drawing::Point(656, 60);
			this->buttonX->Name = L"buttonX";
			this->buttonX->Size = System::Drawing::Size(30, 30);
			this->buttonX->TabIndex = 5;
			this->buttonX->Text = L"X";
			this->buttonX->UseVisualStyleBackColor = true;
			this->buttonX->Click += gcnew System::EventHandler(this, &MyForm::buttonX_Click);
			// 
			// buttonY
			// 
			this->buttonY->Location = System::Drawing::Point(700, 60);
			this->buttonY->Name = L"buttonY";
			this->buttonY->Size = System::Drawing::Size(30, 30);
			this->buttonY->TabIndex = 6;
			this->buttonY->Text = L"Y";
			this->buttonY->UseVisualStyleBackColor = true;
			this->buttonY->Click += gcnew System::EventHandler(this, &MyForm::buttonY_Click);
			// 
			// buttonZ
			// 
			this->buttonZ->Location = System::Drawing::Point(744, 60);
			this->buttonZ->Name = L"buttonZ";
			this->buttonZ->Size = System::Drawing::Size(30, 30);
			this->buttonZ->TabIndex = 7;
			this->buttonZ->Text = L"Z";
			this->buttonZ->UseVisualStyleBackColor = true;
			this->buttonZ->Click += gcnew System::EventHandler(this, &MyForm::buttonZ_Click);
			// 
			// labelMove
			// 
			this->labelMove->AutoSize = true;
			this->labelMove->Location = System::Drawing::Point(635, 110);
			this->labelMove->Name = L"labelMove";
			this->labelMove->Size = System::Drawing::Size(80, 13);
			this->labelMove->TabIndex = 8;
			this->labelMove->Text = L"Перемещение";
			// 
			// labelRotate
			// 
			this->labelRotate->AutoSize = true;
			this->labelRotate->Location = System::Drawing::Point(635, 313);
			this->labelRotate->Name = L"labelRotate";
			this->labelRotate->Size = System::Drawing::Size(50, 13);
			this->labelRotate->TabIndex = 14;
			this->labelRotate->Text = L"Поворот";
			// 
			// labelScale
			// 
			this->labelScale->AutoSize = true;
			this->labelScale->Location = System::Drawing::Point(635, 404);
			this->labelScale->Name = L"labelScale";
			this->labelScale->Size = System::Drawing::Size(101, 13);
			this->labelScale->TabIndex = 17;
			this->labelScale->Text = L"Масштабирование";
			// 
			// checkBoxScale
			// 
			this->checkBoxScale->AutoSize = true;
			this->checkBoxScale->Checked = true;
			this->checkBoxScale->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxScale->Location = System::Drawing::Point(638, 476);
			this->checkBoxScale->Name = L"checkBoxScale";
			this->checkBoxScale->Size = System::Drawing::Size(186, 17);
			this->checkBoxScale->TabIndex = 20;
			this->checkBoxScale->Text = L"Масштабировать по всем осям";
			this->checkBoxScale->UseVisualStyleBackColor = true;
			this->checkBoxScale->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxScale_CheckedChanged);
			// 
			// buttonMoveUp
			// 
			this->buttonMoveUp->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonMoveUp->Location = System::Drawing::Point(700, 126);
			this->buttonMoveUp->Name = L"buttonMoveUp";
			this->buttonMoveUp->Size = System::Drawing::Size(50, 50);
			this->buttonMoveUp->TabIndex = 21;
			this->buttonMoveUp->Text = L"Up";
			this->buttonMoveUp->UseVisualStyleBackColor = false;
			this->buttonMoveUp->Click += gcnew System::EventHandler(this, &MyForm::buttonMoveUp_Click);
			// 
			// buttonMoveLeft
			// 
			this->buttonMoveLeft->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonMoveLeft->Location = System::Drawing::Point(646, 182);
			this->buttonMoveLeft->Name = L"buttonMoveLeft";
			this->buttonMoveLeft->Size = System::Drawing::Size(50, 50);
			this->buttonMoveLeft->TabIndex = 22;
			this->buttonMoveLeft->Text = L"Left";
			this->buttonMoveLeft->UseVisualStyleBackColor = false;
			this->buttonMoveLeft->Click += gcnew System::EventHandler(this, &MyForm::buttonMoveLeft_Click);
			// 
			// buttonMoveDown
			// 
			this->buttonMoveDown->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonMoveDown->Location = System::Drawing::Point(700, 238);
			this->buttonMoveDown->Name = L"buttonMoveDown";
			this->buttonMoveDown->Size = System::Drawing::Size(50, 50);
			this->buttonMoveDown->TabIndex = 23;
			this->buttonMoveDown->Text = L"Down";
			this->buttonMoveDown->UseVisualStyleBackColor = false;
			this->buttonMoveDown->Click += gcnew System::EventHandler(this, &MyForm::buttonMoveDown_Click);
			// 
			// buttonMoveRight
			// 
			this->buttonMoveRight->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonMoveRight->Location = System::Drawing::Point(756, 182);
			this->buttonMoveRight->Name = L"buttonMoveRight";
			this->buttonMoveRight->Size = System::Drawing::Size(50, 50);
			this->buttonMoveRight->TabIndex = 24;
			this->buttonMoveRight->Text = L"Right";
			this->buttonMoveRight->UseVisualStyleBackColor = false;
			this->buttonMoveRight->Click += gcnew System::EventHandler(this, &MyForm::buttonMoveRight_Click);
			// 
			// buttonRotateClockwise
			// 
			this->buttonRotateClockwise->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonRotateClockwise->Location = System::Drawing::Point(638, 338);
			this->buttonRotateClockwise->Name = L"buttonRotateClockwise";
			this->buttonRotateClockwise->Size = System::Drawing::Size(80, 50);
			this->buttonRotateClockwise->TabIndex = 25;
			this->buttonRotateClockwise->Text = L"Clockwise";
			this->buttonRotateClockwise->UseVisualStyleBackColor = false;
			this->buttonRotateClockwise->Click += gcnew System::EventHandler(this, &MyForm::buttonRotateClockwise_Click);
			// 
			// buttonRotateUnclockwise
			// 
			this->buttonRotateUnclockwise->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonRotateUnclockwise->Location = System::Drawing::Point(744, 338);
			this->buttonRotateUnclockwise->Name = L"buttonRotateUnclockwise";
			this->buttonRotateUnclockwise->Size = System::Drawing::Size(80, 50);
			this->buttonRotateUnclockwise->TabIndex = 26;
			this->buttonRotateUnclockwise->Text = L"Unclockwise";
			this->buttonRotateUnclockwise->UseVisualStyleBackColor = false;
			this->buttonRotateUnclockwise->Click += gcnew System::EventHandler(this, &MyForm::buttonRotateUnclockwise_Click);
			// 
			// buttonScaleDown
			// 
			this->buttonScaleDown->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonScaleDown->Location = System::Drawing::Point(646, 420);
			this->buttonScaleDown->Name = L"buttonScaleDown";
			this->buttonScaleDown->Size = System::Drawing::Size(50, 50);
			this->buttonScaleDown->TabIndex = 27;
			this->buttonScaleDown->Text = L"Smaller";
			this->buttonScaleDown->UseVisualStyleBackColor = false;
			this->buttonScaleDown->Click += gcnew System::EventHandler(this, &MyForm::buttonScaleDown_Click);
			// 
			// buttonScaleUp
			// 
			this->buttonScaleUp->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonScaleUp->Location = System::Drawing::Point(756, 420);
			this->buttonScaleUp->Name = L"buttonScaleUp";
			this->buttonScaleUp->Size = System::Drawing::Size(50, 50);
			this->buttonScaleUp->TabIndex = 28;
			this->buttonScaleUp->Text = L"Bigger";
			this->buttonScaleUp->UseVisualStyleBackColor = false;
			this->buttonScaleUp->Click += gcnew System::EventHandler(this, &MyForm::buttonScaleUp_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(635, 505);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 13);
			this->label1->TabIndex = 29;
			this->label1->Text = L"Выбор фигуры";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(638, 530);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 50);
			this->button1->TabIndex = 30;
			this->button1->Text = L"Призма";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(738, 530);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(86, 50);
			this->button2->TabIndex = 31;
			this->button2->Text = L"Треугольная пирамида";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(753, 505);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 13);
			this->label2->TabIndex = 32;
			this->label2->Text = L"Пирамида";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(756, 126);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(50, 50);
			this->button3->TabIndex = 33;
			this->button3->Text = L"Further";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(646, 238);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(50, 50);
			this->button4->TabIndex = 34;
			this->button4->Text = L"Closer";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(836, 625);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonScaleUp);
			this->Controls->Add(this->buttonScaleDown);
			this->Controls->Add(this->buttonRotateUnclockwise);
			this->Controls->Add(this->buttonRotateClockwise);
			this->Controls->Add(this->buttonMoveRight);
			this->Controls->Add(this->buttonMoveDown);
			this->Controls->Add(this->buttonMoveLeft);
			this->Controls->Add(this->buttonMoveUp);
			this->Controls->Add(this->checkBoxScale);
			this->Controls->Add(this->labelScale);
			this->Controls->Add(this->labelRotate);
			this->Controls->Add(this->labelMove);
			this->Controls->Add(this->buttonZ);
			this->Controls->Add(this->buttonY);
			this->Controls->Add(this->buttonX);
			this->Controls->Add(this->LabelAxisChoice);
			this->Controls->Add(this->TextCurrentAxis);
			this->Controls->Add(this->LabelCurrentAxis);
			this->Controls->Add(this->picture);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregionprivate:
		bool ScaleFlag = 1;
	private: System::Void buttonX_Click(System::Object^ sender, System::EventArgs^ e) {
		TextCurrentAxis->Text = "X";
		pyramid.ChangeAxis('X');
		prism.ChangeAxis('X');
	}
	private: System::Void buttonY_Click(System::Object^ sender, System::EventArgs^ e) {
		TextCurrentAxis->Text = "Y";
		pyramid.ChangeAxis('Y');
		prism.ChangeAxis('Y');
	}
	private: System::Void buttonZ_Click(System::Object^ sender, System::EventArgs^ e) {
		TextCurrentAxis->Text = "Z";
		pyramid.ChangeAxis('Z');
		prism.ChangeAxis('Z');
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		label2->Text = "Призма";
		current = &prism;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		label2->Text = "Пирамида";
		current = &pyramid;
	}
	private: System::Void checkBoxScale_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (ScaleFlag)
			ScaleFlag = 0;
		else
			ScaleFlag = 1;
	}
		   // рисование
	private: System::Void picture_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		// Рисуем фигуру
		picture->Image = gcnew Bitmap(600, 600);
		Bitmap^ bitmap = gcnew Bitmap(picture->Image);
		picture->Image = bitmap;

		point p1, p2;
		point m1 = pyramid.getMid();
		point m2 = prism.getMid();
		Figura* temp;
		Pen^ P;
		Pen^ BlueP = System::Drawing::Pens::Blue;
		Pen^ OrangeP = System::Drawing::Pens::Orange;
		Color Blue = System::Drawing::Color::Blue;
		Color Green = System::Drawing::Color::Green;
		Color Orange = System::Drawing::Color::Orange;
		Color Red = System::Drawing::Color::Red;
		if (m1.z < m2.z) {
			temp = &prism;
			P = BlueP;
		}
		else {
			temp = &pyramid;
			P = OrangeP;
		}

		//нарисовать фигуру 1
		Face* faces = temp->getFaces();
		for (int i = 0;i < temp->getFacesCount();i++) {
			faces[i].FindFaceMid();
			faces[i].visibility(point{ 1,-1,-2 });
			if (faces[i].isVisible) {
				for (int j = 0;j < faces[i].count;j++) {
					p1 = faces[i].points[j];
					if (j + 1 == faces[i].count)
						p2 = faces[i].points[0];
					else
						p2 = faces[i].points[j + 1];
					DrawLine(int(p1.x + (p1.z / 2)), int(p1.y - (p1.z / 2)),
						int(p2.x + (p2.z / 2)), int(p2.y - (p2.z / 2)),
						bitmap, m1.z < m2.z ? Blue : Orange);
				}
				point mid = faces[i].mid;
				//bitmap->SetPixel(mid.x + mid.z / 2, mid.y - mid.z / 2, Red);
				FillFrame(faces[i].mid, bitmap,
					m1.z < m2.z ? Blue : Orange,
					m1.z < m2.z ? Green : Red, faces[i]);
			}
		}
		if (m1.z < m2.z) {
			temp = &pyramid;
		}
		else {
			temp = &prism;
		}
		// нарисовать фигуру 2
		faces = temp->getFaces();
		for (int i = 0;i < temp->getFacesCount();i++) {
			faces[i].FindFaceMid();
			faces[i].visibility(point{ 1,-1,-2 });
			if (faces[i].isVisible) {
				for (int j = 0;j < faces[i].count;j++) {
					p1 = faces[i].points[j];
					if (j + 1 == faces[i].count)
						p2 = faces[i].points[0];
					else
						p2 = faces[i].points[j + 1];
					DrawLine(int(p1.x + (p1.z / 2)), int(p1.y - (p1.z / 2)),
						int(p2.x + (p2.z / 2)), int(p2.y - (p2.z / 2)),
						bitmap, m1.z < m2.z ? Orange : Blue);
				}
				point mid = faces[i].mid;
				//bitmap->SetPixel(mid.x + mid.z / 2, mid.y - mid.z / 2, Red);
				FillFrame(faces[i].mid, bitmap,
					m1.z < m2.z ? Orange : Blue,
					m1.z < m2.z ? Red : Green, faces[i]);
			}
		}
		//нарисовать тени

		Color Black = System::Drawing::Color::Black;
		temp = &pyramid;
		faces = temp->getFaces();
		for (int i = 0;i < temp->getFacesCount();i++) {
			faces[i].FindFaceMid();
			faces[i].visibility(point{ 0,-1,0 });
			if (faces[i].isVisible) {
				for (int j = 0;j < faces[i].count;j++) {
					p1 = faces[i].points[j];
					if (j + 1 == faces[i].count)
						p2 = faces[i].points[0];
					else
						p2 = faces[i].points[j + 1];
					DrawLine(int(p1.x + (p1.z / 2)), int(500 - (p1.z / 2)),
						int(p2.x + (p2.z / 2)), int(500 - (p2.z / 2)),
						bitmap, Black);
				}
				point mid = faces[i].mid;
				mid.y = 500;
				//bitmap->SetPixel(mid.x + mid.z / 2, mid.y - mid.z / 2, Red);
				FillFrame(mid, bitmap, Black, Black, faces[i]);
			}
		}

		temp = &prism;
		faces = temp->getFaces();
		for (int i = 0;i < temp->getFacesCount();i++) {
			faces[i].FindFaceMid();
			faces[i].visibility(point{ 0,-1,0 });
			if (faces[i].isVisible) {
				for (int j = 0;j < faces[i].count;j++) {
					p1 = faces[i].points[j];
					if (j + 1 == faces[i].count)
						p2 = faces[i].points[0];
					else
						p2 = faces[i].points[j + 1];
					DrawLine(int(p1.x + (p1.z / 2)), int(500 - (p1.z / 2)),
						int(p2.x + (p2.z / 2)), int(500 - (p2.z / 2)),
						bitmap, Black);
				}
				point mid = faces[i].mid;
				mid.y = 500;
				//bitmap->SetPixel(mid.x + mid.z / 2, mid.y - mid.z / 2, Red);
				FillFrame(mid, bitmap, Black, Black, faces[i]);
			}
		}
	}
	private: void FillFrame(point p, Bitmap^ map, Color frame, Color fill, Face face) {
		point temp;
		temp = p;
		temp.x += temp.z / 2;
		temp.y -= temp.z / 2;
		if (IsInFrame(temp, map, frame, fill, face))
		stack.push_back(temp)
			;
		else
			return;
		while (stack.size() > 0) {
			temp = stack[stack.size() - 1];
			if (IsInFrame(temp, map, frame, fill, face)) {
				stack.pop_back();
				map->SetPixel(temp.x, temp.y, fill);
				stack.push_back(point{ temp.x + 1,temp.y,temp.z });
				stack.push_back(point{ temp.x - 1,temp.y,temp.z });
				stack.push_back(point{ temp.x,temp.y + 1,temp.z });
				stack.push_back(point{ temp.x,temp.y - 1,temp.z });
			}
			else {
				stack.pop_back();
			}
		}
	}
	private: bool IsInFrame(point c, Bitmap^ map, Color a, Color fill, Face face) {
		int flag = 1;
		int k = 0;
		if (c.x >= 0 && c.x < 600 && c.y >= 0 && c.y < 600) {
			Color pixelColor = map->GetPixel(c.x, c.y);
			if (pixelColor.ToArgb() == a.ToArgb() || pixelColor.ToArgb() == fill.ToArgb())
				return false;
		}
		else
			return false;
		return true;
	}
	private: void DrawLine(float x1, float y1, float x2, float y2, Bitmap^ map, Color color) {
		float x, y, dx, dy, step;
		int i;
		dx = x2 - x1;
		dy = y2 - y1;

		if (abs(dx) >= abs(dy))
			step = abs(dx);
		else
			step = abs(dy);

		dx = dx / step;
		dy = dy / step;

		x = x1;
		y = y1;

		i = 1;
		while (i <= step)
		{
			map->SetPixel(x, y, color);
			x = x + dx;
			y = y + dy;
			i = i + 1;
		}
	}
		   // перемещение
	private: System::Void buttonMoveUp_Click(System::Object^ sender, System::EventArgs^ e) {
		current->Move(0, -MOVE, 0);
		current->RenewFaces();
		this->picture->Refresh();
		this->picture->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::picture_Paint);
	}
	private: System::Void buttonMoveDown_Click(System::Object^ sender, System::EventArgs^ e) {
		current->Move(0, MOVE, 0);
		current->RenewFaces();
		this->picture->Refresh();
		this->picture->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::picture_Paint);
	}
	private: System::Void buttonMoveLeft_Click(System::Object^ sender, System::EventArgs^ e) {
		current->Move(-MOVE, 0, 0);
		current->RenewFaces();
		this->picture->Refresh();
		this->picture->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::picture_Paint);
	}
	private: System::Void buttonMoveRight_Click(System::Object^ sender, System::EventArgs^ e) {
		current->Move(MOVE, 0, 0);
		current->RenewFaces();
		this->picture->Refresh();
		this->picture->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::picture_Paint);
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		current->Move(0, 0, -MOVE);
		current->RenewFaces();
		this->picture->Refresh();
		this->picture->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::picture_Paint);
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		current->Move(0, 0, MOVE);
		current->RenewFaces();
		this->picture->Refresh();
		this->picture->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::picture_Paint);
	}
		   // вращение
	private: System::Void buttonRotateClockwise_Click(System::Object^ sender, System::EventArgs^ e) {
		current->Rotate(-ROTATE);
		current->RenewFaces();
		this->picture->Refresh();
		this->picture->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::picture_Paint);
	}
	private: System::Void buttonRotateUnclockwise_Click(System::Object^ sender, System::EventArgs^ e) {
		current->Rotate(ROTATE);
		current->RenewFaces();
		this->picture->Refresh();
		this->picture->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::picture_Paint);
	}
		   // масштабирование
	private: System::Void buttonScaleDown_Click(System::Object^ sender, System::EventArgs^ e) {
		current->Scale(ScaleFlag, -SCALE);
		current->RenewFaces();
		this->picture->Refresh();
		this->picture->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::picture_Paint);
	}
	private: System::Void buttonScaleUp_Click(System::Object^ sender, System::EventArgs^ e) {
		current->Scale(ScaleFlag, SCALE);
		current->RenewFaces();
		this->picture->Refresh();
		this->picture->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::picture_Paint);
	}
	};
}
