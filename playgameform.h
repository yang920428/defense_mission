#pragma once
#include <math.h>
#include <stdio.h>
#include "object.h"

namespace defense_mission {

    using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// playgameform 的摘要
	/// </summary>
	public ref class playgameform : public System::Windows::Forms::Form
	{
	public:
		playgameform(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}
        // some variable
        int coin = 50;
        int system_counter = 0;
        laser_gun* laser;

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~playgameform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::PictureBox^ pictureBox1;

    protected:

	private:
        
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ button3;
    private: System::Windows::Forms::Button^ button4;
    private: System::Windows::Forms::Button^ button5;
    private: System::Windows::Forms::Button^ button6;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Timer^ timer1;
    private: System::ComponentModel::IContainer^ components;


           /// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(playgameform::typeid));
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->button5 = (gcnew System::Windows::Forms::Button());
            this->button6 = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::Gold;
            this->button1->Font = (gcnew System::Drawing::Font(L"新細明體", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button1->Location = System::Drawing::Point(782, 0);
            this->button1->Margin = System::Windows::Forms::Padding(2);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(103, 34);
            this->button1->TabIndex = 0;
            this->button1->Text = L"back";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &playgameform::button1_Click);
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(1, 77);
            this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(884, 394);
            this->pictureBox1->TabIndex = 1;
            this->pictureBox1->TabStop = false;
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(174, 12);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(62, 49);
            this->button2->TabIndex = 2;
            this->button2->Text = L"laser";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &playgameform::button2_Click);
            // 
            // button3
            // 
            this->button3->Location = System::Drawing::Point(270, 12);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(62, 49);
            this->button3->TabIndex = 3;
            this->button3->Text = L"machine";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &playgameform::button3_Click);
            // 
            // button4
            // 
            this->button4->Location = System::Drawing::Point(360, 12);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(62, 49);
            this->button4->TabIndex = 4;
            this->button4->Text = L"cannon";
            this->button4->UseVisualStyleBackColor = true;
            this->button4->Click += gcnew System::EventHandler(this, &playgameform::button4_Click);
            // 
            // button5
            // 
            this->button5->Location = System::Drawing::Point(448, 12);
            this->button5->Name = L"button5";
            this->button5->Size = System::Drawing::Size(62, 49);
            this->button5->TabIndex = 5;
            this->button5->Text = L"landmine";
            this->button5->UseVisualStyleBackColor = true;
            this->button5->Click += gcnew System::EventHandler(this, &playgameform::button5_Click);
            // 
            // button6
            // 
            this->button6->Location = System::Drawing::Point(532, 12);
            this->button6->Name = L"button6";
            this->button6->Size = System::Drawing::Size(62, 49);
            this->button6->TabIndex = 6;
            this->button6->Text = L"bomb";
            this->button6->UseVisualStyleBackColor = true;
            this->button6->Click += gcnew System::EventHandler(this, &playgameform::button6_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label1->Location = System::Drawing::Point(38, 24);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(53, 20);
            this->label1->TabIndex = 7;
            this->label1->Text = L"label1";
            // 
            // timer1
            // 
            this->timer1->Enabled = true;
            this->timer1->Tick += gcnew System::EventHandler(this, &playgameform::timer1_Tick);
            // 
            // playgameform
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::LemonChiffon;
            this->ClientSize = System::Drawing::Size(886, 522);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->button6);
            this->Controls->Add(this->button5);
            this->Controls->Add(this->button4);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->button1);
            this->Margin = System::Windows::Forms::Padding(2);
            this->Name = L"playgameform";
            this->Text = L"gaming";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        void plot_HMI() {
            Graphics^ e1 = this->CreateGraphics();
            e1->Clear(Color::WhiteSmoke);
            Pen^ pen_b = gcnew Pen(Color::Blue, 2);
            Pen^ pen_y = gcnew Pen(Color::Yellow, 2);
            Pen^ pen_r = gcnew Pen(Color::Red, 2);
            Pen^ pen_p = gcnew Pen(Color::Purple, 2);

            // plot laser
            e1->DrawEllipse(pen_b, 174.0, 77.0, laser->radius, laser->radius);
            e1->DrawLine(pen_b, 174, 77, 214, 77);
        }

        void text_displayer() {
            this->label1->Text = (Convert::ToString(coin));
        }

        void initialize() {
            laser->radius = 20;
        }

#pragma endregion
    private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
        // main
        if (system_counter == 0) {
            initialize();
        }

        plot_HMI();
        text_displayer();
        system_counter++;
    }
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { // back
        this->Close();
	}
    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { // laser gun

    }
    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { // machine gun

    }
    private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) { // cannon

    }
    private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) { // landmine

    }
    private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) { // bomb

    }
};
}
