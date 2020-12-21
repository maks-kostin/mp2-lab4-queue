#pragma once

#include "../mp2-lab4-queue/tqueue.h"

namespace simulation {

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

		int MaxSize;
		int Size;
		double p;
		double q;
		int PopCount;
		int PushCount;

		TQueue<int>* pQueue;
		int CenterX, CenterY, Width, Height;
		Graphics^ gr;
		Random^ rnd1;
		Pen^ BlackPen;
		Pen^ WhitePen;
		Pen^ GreenPen;
		Pen^ YellowPen;
		Pen^ RedPen;
		 
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			gr = CreateGraphics();
			rnd1 = gcnew Random();
			BlackPen = gcnew Pen(Color::Black);
			BlackPen->Width = 10.0F;
			WhitePen = gcnew Pen(SystemColors::Control);
			WhitePen->Width = 11.0F;
			CenterX = 180;
			CenterY = 320;
			Width = Height = 200;
			PopCount = PushCount = 0;
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
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(205, 39);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(151, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"150";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(205, 80);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(151, 20);
			this->textBox2->TabIndex = 1;
			this->textBox2->Text = L"40";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(205, 124);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(151, 20);
			this->textBox3->TabIndex = 2;
			this->textBox3->Text = L"0,6";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(205, 167);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(151, 20);
			this->textBox4->TabIndex = 3;
			this->textBox4->Text = L"0,4";
			// 
			// textBox5
			// 
			this->textBox5->Enabled = false;
			this->textBox5->Location = System::Drawing::Point(205, 210);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(151, 20);
			this->textBox5->TabIndex = 4;
			this->textBox5->Text = L"0";
			// 
			// textBox6
			// 
			this->textBox6->Enabled = false;
			this->textBox6->Location = System::Drawing::Point(205, 250);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(151, 20);
			this->textBox6->TabIndex = 5;
			this->textBox6->Text = L"0";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(390, 106);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 38);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(390, 167);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(97, 38);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Stop";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::Button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(28, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(171, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Максимальный размер очереди";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(28, 83);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(149, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Искходный размер очереди";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(28, 127);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(135, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Вероятность добавления";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(28, 170);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(134, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Вероятность извлечения";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(28, 213);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(117, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Добавлено в очередь";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(28, 253);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(121, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Извлечено из очереди";
			// 
			// timer1
			// 
			this->timer1->Interval = 70;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::Timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(580, 600);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"Queue simulation";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		MaxSize = Convert::ToInt32(textBox1->Text);
		Size = Convert::ToInt32(textBox2->Text);
		p = Convert::ToDouble(textBox3->Text);
		q = Convert::ToDouble(textBox4->Text);

		pQueue = new TQueue<int>(MaxSize);
		for (int i = 0; i < Size; i++)
		{
			pQueue[0].push(i);
		}
		

		DrawQueue();
		timer1->Enabled = true;
	}

			 void DrawQueue()
			 {
				 
				 int start = 360 * pQueue->GetHead() / pQueue->GetMaxSize();
				 int finish = 360 * pQueue->GetSize() / pQueue->GetMaxSize();
				 gr->DrawArc(BlackPen, CenterX, CenterY, Width, Height, start, finish);
				 /*double third = pQueue->GetSize() / pQueue->GetMaxSize();
				 if (third <= 1/3)
					 gr->DrawArc(GreenPen, CenterX, CenterY, Width, Height, start, finish);
				 if (third <= 2/3 && third > 1/3)
					 gr->DrawArc(YellowPen, CenterX, CenterY, Width, Height, start, finish);
				 if (third <= 1 && third > 2/3)
					 gr->DrawArc(RedPen, CenterX, CenterY, Width, Height, start, finish);*/
			 }

			 void Clean()
			 {
				 int start = 0;
				 int finish = 360;
				 gr->DrawArc(WhitePen, CenterX, CenterY, Width, Height, start, finish);
			 }
private: System::Void Timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

	Clean();
	if (rnd1->NextDouble() < p) 
	{
		if (!pQueue[0].full())
		{
			pQueue[0].push(1);
			PushCount++;
		}
	}
	if (rnd1->NextDouble() < q)
	{
		if (!pQueue[0].empty())
		{
			pQueue[0].pop();
			PopCount++;
		}

	}
	DrawQueue();
	textBox5->Text = Convert::ToString(PushCount);
	textBox6->Text = Convert::ToString(PopCount);
}
private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
	timer1->Enabled = false;
}
};
}
