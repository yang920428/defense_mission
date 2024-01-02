#pragma once
#include <math.h>
#include <stdio.h>
#include <vector>
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
            this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &playgameform::playgameform_MouseClick);
        }
        // some variable
        int coin = 1000;
        int system_counter = 0;
        weapon* wea = new weapon[25]();
        laser_gun* laser = new laser_gun[5]();
        machine_gun* machine = new machine_gun[5]();
        cannon* Cannon = new cannon[5]();
        landmine* Landmine = new landmine[5]();
        bomb* Bomb = new bomb[5]();
        bool* map = new bool[25]();
        bool* map_click_status = new bool[25]();
        float mouseX;
        float mouseY;
    private: System::Windows::Forms::Button^ button7;
    public:
    private: System::Windows::Forms::Button^ button8;
    private: System::Windows::Forms::Button^ button9;
    private: System::Windows::Forms::Button^ button10;
    private: System::Windows::Forms::Button^ button11;
    private: System::Windows::Forms::Button^ button12;
    private: System::Windows::Forms::Button^ button13;
    private: System::Windows::Forms::Button^ button14;
    private: System::Windows::Forms::Button^ button15;
    private: System::Windows::Forms::Button^ button16;
    private: System::Windows::Forms::Button^ button17;
    private: System::Windows::Forms::Button^ button18;
    private: System::Windows::Forms::Button^ button19;
    private: System::Windows::Forms::Button^ button20;
    private: System::Windows::Forms::Button^ button21;
    private: System::Windows::Forms::Button^ button22;
    private: System::Windows::Forms::Button^ button23;
    private: System::Windows::Forms::Button^ button24;
    private: System::Windows::Forms::Button^ button25;
    private: System::Windows::Forms::Button^ button26;
    private: System::Windows::Forms::Button^ button27;
    private: System::Windows::Forms::Button^ button28;
    private: System::Windows::Forms::Button^ button29;
    private: System::Windows::Forms::Button^ button30;
    private: System::Windows::Forms::Button^ button31;

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
    private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
        // 初始地圖標線
        Graphics^ g = e->Graphics;
        Pen^ pen_yg = gcnew Pen(Color::YellowGreen, 5);
        g->DrawLine(pen_yg, 160, 0, 160, 394);
        g->DrawLine(pen_yg, 800, 0, 800, 394);
        // 在 pictureBox1 上方繪製 laser gun
        if (map[0] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_b = gcnew Pen(Color::Blue, 2);
            g->DrawEllipse(pen_b, 174.0, 34.0, 20, 20);
            g->DrawLine(pen_b, 184, 44, 204, 44);
        }
        if (map[1] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_b = gcnew Pen(Color::Blue, 2);
            g->DrawEllipse(pen_b, 174.0, 115.0, 20, 20);
            g->DrawLine(pen_b, 184, 125, 204, 125);
        }
        if (map[2] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_b = gcnew Pen(Color::Blue, 2);
            g->DrawEllipse(pen_b, 174.0, 190.0, 20, 20);
            g->DrawLine(pen_b, 184, 200, 204, 200);
        }
        if (map[3] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_b = gcnew Pen(Color::Blue, 2);
            g->DrawEllipse(pen_b, 174.0, 260.0, 20, 20);
            g->DrawLine(pen_b, 184, 270, 204, 270);
        }
        if (map[4] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_b = gcnew Pen(Color::Blue, 2);
            g->DrawEllipse(pen_b, 174.0, 333.0, 20, 20);
            g->DrawLine(pen_b, 184, 343, 204, 343);
        }
        // 在 pictureBox1 上方繪製 machine gun
        if (map[5] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_r = gcnew Pen(Color::Red, 2);
            g->DrawEllipse(pen_r, 270.0, 34.0, 20, 20);
            g->DrawLine(pen_r, 280, 44, 300, 44);
        }
        if (map[6] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_r = gcnew Pen(Color::Red, 2);
            g->DrawEllipse(pen_r, 270.0, 115.0, 20, 20);
            g->DrawLine(pen_r, 280, 125, 300, 125);
        }
        if (map[7] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_r = gcnew Pen(Color::Red, 2);
            g->DrawEllipse(pen_r, 270.0, 190.0, 20, 20);
            g->DrawLine(pen_r, 280, 200, 300, 200);
        }
        if (map[8] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_r = gcnew Pen(Color::Red, 2);
            g->DrawEllipse(pen_r, 270.0, 260.0, 20, 20);
            g->DrawLine(pen_r, 280, 270, 300, 270);
        }
        if (map[9] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_r = gcnew Pen(Color::Red, 2);
            g->DrawEllipse(pen_r, 270.0, 333.0, 20, 20);
            g->DrawLine(pen_r, 280, 343, 300, 343);
        }
        // 在 pictureBox1 上方繪製 cannon
        if (map[10] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_p = gcnew Pen(Color::Purple, 2);
            g->DrawEllipse(pen_p, 350.0, 34.0, 20, 20);
            g->DrawLine(pen_p, 360, 44, 380, 44);
        }
        if (map[11] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_p = gcnew Pen(Color::Purple, 2);
            g->DrawEllipse(pen_p, 350.0, 115.0, 20, 20);
            g->DrawLine(pen_p, 360, 125, 380, 125);
        }
        if (map[12] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_p = gcnew Pen(Color::Purple, 2);
            g->DrawEllipse(pen_p, 350.0, 190.0, 20, 20);
            g->DrawLine(pen_p, 360, 200, 380, 200);
        }
        if (map[13] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_p = gcnew Pen(Color::Purple, 2);
            g->DrawEllipse(pen_p, 350.0, 260.0, 20, 20);
            g->DrawLine(pen_p, 360, 270, 380, 270);
        }
        if (map[14] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_p = gcnew Pen(Color::Purple, 2);
            g->DrawEllipse(pen_p, 350.0, 333.0, 20, 20);
            g->DrawLine(pen_p, 360, 343, 380, 343);
        }
        // 在 pictureBox1 上方繪製 landmine
        if (map[15] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_k = gcnew Pen(Color::Black, 15);
            g->DrawEllipse(pen_k, 448.0, 34.0, 15, 15);
        }
        if (map[16] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_k = gcnew Pen(Color::Black, 15);
            g->DrawEllipse(pen_k, 448.0, 115.0, 15, 15);
        }
        if (map[17] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_k = gcnew Pen(Color::Black, 15);
            g->DrawEllipse(pen_k, 448.0, 190.0, 15, 15);
        }
        if (map[18] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_k = gcnew Pen(Color::Black, 15);
            g->DrawEllipse(pen_k, 448.0, 260.0, 15, 15);
        }
        if (map[19] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_k = gcnew Pen(Color::Black, 15);
            g->DrawEllipse(pen_k, 448.0, 333.0, 15, 15);
        }
        // 在 pictureBox1 上方繪製 bomb
        if (map[20] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_y = gcnew Pen(Color::Yellow, 20);
            g->DrawEllipse(pen_y, 532.0, 34.0, 20, 20);
        }
        if (map[21] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_y = gcnew Pen(Color::Yellow, 20);
            g->DrawEllipse(pen_y, 532.0, 115.0, 20, 20);
        }
        if (map[22] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_y = gcnew Pen(Color::Yellow, 20);
            g->DrawEllipse(pen_y, 532.0, 190.0, 20, 20);
        }
        if (map[23] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_y = gcnew Pen(Color::Yellow, 20);
            g->DrawEllipse(pen_y, 532.0, 260.0, 20, 20);
        }
        if (map[24] == true) {
            Graphics^ g = e->Graphics;
            Pen^ pen_y = gcnew Pen(Color::Yellow, 20);
            g->DrawEllipse(pen_y, 532.0, 333.0, 20, 20);
        }
    }
    private: System::Void playgameform_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
        // 在滑鼠點擊事件中取得座標
        mouseX = static_cast<float>(e->X);
        mouseY = static_cast<float>(e->Y);
    }

           // 在需要的地方呼叫 Invalidate() 來觸發 pictureBox1_Paint 事件



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
               this->button7 = (gcnew System::Windows::Forms::Button());
               this->button8 = (gcnew System::Windows::Forms::Button());
               this->button9 = (gcnew System::Windows::Forms::Button());
               this->button10 = (gcnew System::Windows::Forms::Button());
               this->button11 = (gcnew System::Windows::Forms::Button());
               this->button12 = (gcnew System::Windows::Forms::Button());
               this->button13 = (gcnew System::Windows::Forms::Button());
               this->button14 = (gcnew System::Windows::Forms::Button());
               this->button15 = (gcnew System::Windows::Forms::Button());
               this->button16 = (gcnew System::Windows::Forms::Button());
               this->button17 = (gcnew System::Windows::Forms::Button());
               this->button18 = (gcnew System::Windows::Forms::Button());
               this->button19 = (gcnew System::Windows::Forms::Button());
               this->button20 = (gcnew System::Windows::Forms::Button());
               this->button21 = (gcnew System::Windows::Forms::Button());
               this->button22 = (gcnew System::Windows::Forms::Button());
               this->button23 = (gcnew System::Windows::Forms::Button());
               this->button24 = (gcnew System::Windows::Forms::Button());
               this->button25 = (gcnew System::Windows::Forms::Button());
               this->button26 = (gcnew System::Windows::Forms::Button());
               this->button27 = (gcnew System::Windows::Forms::Button());
               this->button28 = (gcnew System::Windows::Forms::Button());
               this->button29 = (gcnew System::Windows::Forms::Button());
               this->button30 = (gcnew System::Windows::Forms::Button());
               this->button31 = (gcnew System::Windows::Forms::Button());
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
               this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &playgameform::pictureBox1_Paint);
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
               // button7
               // 
               this->button7->BackColor = System::Drawing::Color::YellowGreen;
               this->button7->Location = System::Drawing::Point(174, 94);
               this->button7->Name = L"button7";
               this->button7->Size = System::Drawing::Size(62, 53);
               this->button7->TabIndex = 8;
               this->button7->Text = L"button7";
               this->button7->UseVisualStyleBackColor = false;
               this->button7->Visible = false;
               this->button7->Click += gcnew System::EventHandler(this, &playgameform::button7_Click);
               // 
               // button8
               // 
               this->button8->BackColor = System::Drawing::Color::YellowGreen;
               this->button8->Location = System::Drawing::Point(174, 173);
               this->button8->Name = L"button8";
               this->button8->Size = System::Drawing::Size(62, 53);
               this->button8->TabIndex = 9;
               this->button8->Text = L"button8";
               this->button8->UseVisualStyleBackColor = false;
               this->button8->Visible = false;
               this->button8->Click += gcnew System::EventHandler(this, &playgameform::button8_Click);
               // 
               // button9
               // 
               this->button9->BackColor = System::Drawing::Color::YellowGreen;
               this->button9->Location = System::Drawing::Point(174, 248);
               this->button9->Name = L"button9";
               this->button9->Size = System::Drawing::Size(62, 53);
               this->button9->TabIndex = 10;
               this->button9->Text = L"button9";
               this->button9->UseVisualStyleBackColor = false;
               this->button9->Visible = false;
               this->button9->Click += gcnew System::EventHandler(this, &playgameform::button9_Click);
               // 
               // button10
               // 
               this->button10->BackColor = System::Drawing::Color::YellowGreen;
               this->button10->Location = System::Drawing::Point(174, 319);
               this->button10->Name = L"button10";
               this->button10->Size = System::Drawing::Size(62, 53);
               this->button10->TabIndex = 11;
               this->button10->Text = L"button10";
               this->button10->UseVisualStyleBackColor = false;
               this->button10->Visible = false;
               this->button10->Click += gcnew System::EventHandler(this, &playgameform::button10_Click);
               // 
               // button11
               // 
               this->button11->BackColor = System::Drawing::Color::YellowGreen;
               this->button11->Location = System::Drawing::Point(174, 392);
               this->button11->Name = L"button11";
               this->button11->Size = System::Drawing::Size(62, 53);
               this->button11->TabIndex = 12;
               this->button11->Text = L"button11";
               this->button11->UseVisualStyleBackColor = false;
               this->button11->Visible = false;
               this->button11->Click += gcnew System::EventHandler(this, &playgameform::button11_Click);
               // 
               // button12
               // 
               this->button12->BackColor = System::Drawing::Color::YellowGreen;
               this->button12->Location = System::Drawing::Point(270, 94);
               this->button12->Name = L"button12";
               this->button12->Size = System::Drawing::Size(62, 53);
               this->button12->TabIndex = 13;
               this->button12->Text = L"button12";
               this->button12->UseVisualStyleBackColor = false;
               this->button12->Visible = false;
               this->button12->Click += gcnew System::EventHandler(this, &playgameform::button12_Click);
               // 
               // button13
               // 
               this->button13->BackColor = System::Drawing::Color::YellowGreen;
               this->button13->Location = System::Drawing::Point(270, 173);
               this->button13->Name = L"button13";
               this->button13->Size = System::Drawing::Size(62, 53);
               this->button13->TabIndex = 14;
               this->button13->Text = L"button13";
               this->button13->UseVisualStyleBackColor = false;
               this->button13->Visible = false;
               this->button13->Click += gcnew System::EventHandler(this, &playgameform::button13_Click);
               // 
               // button14
               // 
               this->button14->BackColor = System::Drawing::Color::YellowGreen;
               this->button14->Location = System::Drawing::Point(270, 248);
               this->button14->Name = L"button14";
               this->button14->Size = System::Drawing::Size(62, 53);
               this->button14->TabIndex = 15;
               this->button14->Text = L"button14";
               this->button14->UseVisualStyleBackColor = false;
               this->button14->Visible = false;
               this->button14->Click += gcnew System::EventHandler(this, &playgameform::button14_Click);
               // 
               // button15
               // 
               this->button15->BackColor = System::Drawing::Color::YellowGreen;
               this->button15->Location = System::Drawing::Point(270, 319);
               this->button15->Name = L"button15";
               this->button15->Size = System::Drawing::Size(62, 53);
               this->button15->TabIndex = 16;
               this->button15->Text = L"button15";
               this->button15->UseVisualStyleBackColor = false;
               this->button15->Visible = false;
               this->button15->Click += gcnew System::EventHandler(this, &playgameform::button15_Click);
               // 
               // button16
               // 
               this->button16->BackColor = System::Drawing::Color::YellowGreen;
               this->button16->Location = System::Drawing::Point(270, 392);
               this->button16->Name = L"button16";
               this->button16->Size = System::Drawing::Size(62, 53);
               this->button16->TabIndex = 17;
               this->button16->Text = L"button16";
               this->button16->UseVisualStyleBackColor = false;
               this->button16->Visible = false;
               this->button16->Click += gcnew System::EventHandler(this, &playgameform::button16_Click);
               // 
               // button17
               // 
               this->button17->BackColor = System::Drawing::Color::YellowGreen;
               this->button17->Location = System::Drawing::Point(360, 94);
               this->button17->Name = L"button17";
               this->button17->Size = System::Drawing::Size(62, 53);
               this->button17->TabIndex = 18;
               this->button17->Text = L"button17";
               this->button17->UseVisualStyleBackColor = false;
               this->button17->Visible = false;
               this->button17->Click += gcnew System::EventHandler(this, &playgameform::button17_Click);
               // 
               // button18
               // 
               this->button18->BackColor = System::Drawing::Color::YellowGreen;
               this->button18->Location = System::Drawing::Point(360, 173);
               this->button18->Name = L"button18";
               this->button18->Size = System::Drawing::Size(62, 53);
               this->button18->TabIndex = 19;
               this->button18->Text = L"button18";
               this->button18->UseVisualStyleBackColor = false;
               this->button18->Visible = false;
               this->button18->Click += gcnew System::EventHandler(this, &playgameform::button18_Click);
               // 
               // button19
               // 
               this->button19->BackColor = System::Drawing::Color::YellowGreen;
               this->button19->Location = System::Drawing::Point(360, 248);
               this->button19->Name = L"button19";
               this->button19->Size = System::Drawing::Size(62, 53);
               this->button19->TabIndex = 20;
               this->button19->Text = L"button19";
               this->button19->UseVisualStyleBackColor = false;
               this->button19->Visible = false;
               this->button19->Click += gcnew System::EventHandler(this, &playgameform::button19_Click);
               // 
               // button20
               // 
               this->button20->BackColor = System::Drawing::Color::YellowGreen;
               this->button20->Location = System::Drawing::Point(360, 319);
               this->button20->Name = L"button20";
               this->button20->Size = System::Drawing::Size(62, 53);
               this->button20->TabIndex = 21;
               this->button20->Text = L"button20";
               this->button20->UseVisualStyleBackColor = false;
               this->button20->Visible = false;
               this->button20->Click += gcnew System::EventHandler(this, &playgameform::button20_Click);
               // 
               // button21
               // 
               this->button21->BackColor = System::Drawing::Color::YellowGreen;
               this->button21->Location = System::Drawing::Point(360, 392);
               this->button21->Name = L"button21";
               this->button21->Size = System::Drawing::Size(62, 53);
               this->button21->TabIndex = 22;
               this->button21->Text = L"button21";
               this->button21->UseVisualStyleBackColor = false;
               this->button21->Visible = false;
               this->button21->Click += gcnew System::EventHandler(this, &playgameform::button21_Click);
               // 
               // button22
               // 
               this->button22->BackColor = System::Drawing::Color::YellowGreen;
               this->button22->Location = System::Drawing::Point(448, 94);
               this->button22->Name = L"button22";
               this->button22->Size = System::Drawing::Size(62, 53);
               this->button22->TabIndex = 23;
               this->button22->Text = L"button22";
               this->button22->UseVisualStyleBackColor = false;
               this->button22->Visible = false;
               this->button22->Click += gcnew System::EventHandler(this, &playgameform::button22_Click);
               // 
               // button23
               // 
               this->button23->BackColor = System::Drawing::Color::YellowGreen;
               this->button23->Location = System::Drawing::Point(448, 173);
               this->button23->Name = L"button23";
               this->button23->Size = System::Drawing::Size(62, 53);
               this->button23->TabIndex = 24;
               this->button23->Text = L"button23";
               this->button23->UseVisualStyleBackColor = false;
               this->button23->Visible = false;
               this->button23->Click += gcnew System::EventHandler(this, &playgameform::button23_Click);
               // 
               // button24
               // 
               this->button24->BackColor = System::Drawing::Color::YellowGreen;
               this->button24->Location = System::Drawing::Point(448, 248);
               this->button24->Name = L"button24";
               this->button24->Size = System::Drawing::Size(62, 53);
               this->button24->TabIndex = 25;
               this->button24->Text = L"button24";
               this->button24->UseVisualStyleBackColor = false;
               this->button24->Visible = false;
               this->button24->Click += gcnew System::EventHandler(this, &playgameform::button24_Click);
               // 
               // button25
               // 
               this->button25->BackColor = System::Drawing::Color::YellowGreen;
               this->button25->Location = System::Drawing::Point(448, 319);
               this->button25->Name = L"button25";
               this->button25->Size = System::Drawing::Size(62, 53);
               this->button25->TabIndex = 26;
               this->button25->Text = L"button25";
               this->button25->UseVisualStyleBackColor = false;
               this->button25->Visible = false;
               this->button25->Click += gcnew System::EventHandler(this, &playgameform::button25_Click);
               // 
               // button26
               // 
               this->button26->BackColor = System::Drawing::Color::YellowGreen;
               this->button26->Location = System::Drawing::Point(448, 392);
               this->button26->Name = L"button26";
               this->button26->Size = System::Drawing::Size(62, 53);
               this->button26->TabIndex = 27;
               this->button26->Text = L"button26";
               this->button26->UseVisualStyleBackColor = false;
               this->button26->Visible = false;
               this->button26->Click += gcnew System::EventHandler(this, &playgameform::button26_Click);
               // 
               // button27
               // 
               this->button27->BackColor = System::Drawing::Color::YellowGreen;
               this->button27->Location = System::Drawing::Point(532, 94);
               this->button27->Name = L"button27";
               this->button27->Size = System::Drawing::Size(62, 53);
               this->button27->TabIndex = 28;
               this->button27->Text = L"button27";
               this->button27->UseVisualStyleBackColor = false;
               this->button27->Visible = false;
               this->button27->Click += gcnew System::EventHandler(this, &playgameform::button27_Click);
               // 
               // button28
               // 
               this->button28->BackColor = System::Drawing::Color::YellowGreen;
               this->button28->Location = System::Drawing::Point(532, 173);
               this->button28->Name = L"button28";
               this->button28->Size = System::Drawing::Size(62, 53);
               this->button28->TabIndex = 29;
               this->button28->Text = L"button28";
               this->button28->UseVisualStyleBackColor = false;
               this->button28->Visible = false;
               this->button28->Click += gcnew System::EventHandler(this, &playgameform::button28_Click);
               // 
               // button29
               // 
               this->button29->BackColor = System::Drawing::Color::YellowGreen;
               this->button29->Location = System::Drawing::Point(532, 248);
               this->button29->Name = L"button29";
               this->button29->Size = System::Drawing::Size(62, 53);
               this->button29->TabIndex = 30;
               this->button29->Text = L"button29";
               this->button29->UseVisualStyleBackColor = false;
               this->button29->Visible = false;
               this->button29->Click += gcnew System::EventHandler(this, &playgameform::button29_Click);
               // 
               // button30
               // 
               this->button30->BackColor = System::Drawing::Color::YellowGreen;
               this->button30->Location = System::Drawing::Point(532, 319);
               this->button30->Name = L"button30";
               this->button30->Size = System::Drawing::Size(62, 53);
               this->button30->TabIndex = 31;
               this->button30->Text = L"button30";
               this->button30->UseVisualStyleBackColor = false;
               this->button30->Visible = false;
               this->button30->Click += gcnew System::EventHandler(this, &playgameform::button30_Click);
               // 
               // button31
               // 
               this->button31->BackColor = System::Drawing::Color::YellowGreen;
               this->button31->Location = System::Drawing::Point(532, 392);
               this->button31->Name = L"button31";
               this->button31->Size = System::Drawing::Size(62, 53);
               this->button31->TabIndex = 32;
               this->button31->Text = L"button31";
               this->button31->UseVisualStyleBackColor = false;
               this->button31->Visible = false;
               this->button31->Click += gcnew System::EventHandler(this, &playgameform::button31_Click);
               // 
               // playgameform
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->BackColor = System::Drawing::Color::LemonChiffon;
               this->ClientSize = System::Drawing::Size(886, 522);
               this->Controls->Add(this->button31);
               this->Controls->Add(this->button30);
               this->Controls->Add(this->button29);
               this->Controls->Add(this->button28);
               this->Controls->Add(this->button27);
               this->Controls->Add(this->button26);
               this->Controls->Add(this->button25);
               this->Controls->Add(this->button24);
               this->Controls->Add(this->button23);
               this->Controls->Add(this->button22);
               this->Controls->Add(this->button21);
               this->Controls->Add(this->button20);
               this->Controls->Add(this->button19);
               this->Controls->Add(this->button18);
               this->Controls->Add(this->button17);
               this->Controls->Add(this->button16);
               this->Controls->Add(this->button15);
               this->Controls->Add(this->button14);
               this->Controls->Add(this->button13);
               this->Controls->Add(this->button12);
               this->Controls->Add(this->button11);
               this->Controls->Add(this->button10);
               this->Controls->Add(this->button9);
               this->Controls->Add(this->button8);
               this->Controls->Add(this->button7);
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
               this->label1->Text = ("Money: " + Convert::ToString(coin));
           }

           void Motion() {

           }

           void initialize() {

           }

           void button_hidden() {
               if (this->button7->Visible == true) {
                   this->button7->Visible = false;
               }
               if (this->button8->Visible == true) {
                   this->button8->Visible = false;
               }
               if (this->button9->Visible == true) {
                   this->button9->Visible = false;
               }
               if (this->button10->Visible == true) {
                   this->button10->Visible = false;
               }
               if (this->button11->Visible == true) {
                   this->button11->Visible = false;
               }
               if (this->button12->Visible == true) {
                   this->button12->Visible = false;
               }
               if (this->button13->Visible == true) {
                   this->button13->Visible = false;
               }
               if (this->button14->Visible == true) {
                   this->button14->Visible = false;
               }
               if (this->button15->Visible == true) {
                   this->button15->Visible = false;
               }
               if (this->button16->Visible == true) {
                   this->button16->Visible = false;
               }
               if (this->button17->Visible == true) {
                   this->button17->Visible = false;
               }
               if (this->button18->Visible == true) {
                   this->button18->Visible = false;
               }
               if (this->button19->Visible == true) {
                   this->button19->Visible = false;
               }
               if (this->button20->Visible == true) {
                   this->button20->Visible = false;
               }
               if (this->button21->Visible == true) {
                   this->button21->Visible = false;
               }
               if (this->button22->Visible == true) {
                   this->button22->Visible = false;
               }
               if (this->button23->Visible == true) {
                   this->button23->Visible = false;
               }
               if (this->button24->Visible == true) {
                   this->button24->Visible = false;
               }
               if (this->button25->Visible == true) {
                   this->button25->Visible = false;
               }
               if (this->button26->Visible == true) {
                   this->button26->Visible = false;
               }
               if (this->button27->Visible == true) {
                   this->button27->Visible = false;
               }
               if (this->button28->Visible == true) {
                   this->button28->Visible = false;
               }
               if (this->button29->Visible == true) {
                   this->button29->Visible = false;
               }
               if (this->button30->Visible == true) {
                   this->button30->Visible = false;
               }
               if (this->button31->Visible == true) {
                   this->button31->Visible = false;
               }
           }

           void button_display_laser() {
               if (map[0] == false) {
                   this->button7->Visible = true;
               }
               if (map[1] == false) {
                   this->button8->Visible = true;
               }
               if (map[2] == false) {
                   this->button9->Visible = true;
               }
               if (map[3] == false) {
                   this->button10->Visible = true;
               }
               if (map[4] == false) {
                   this->button11->Visible = true;
               }
           }

           void button_display_machine() {
               if (map[5] == false) {
                   this->button12->Visible = true;
               }
               if (map[6] == false) {
                   this->button13->Visible = true;
               }
               if (map[7] == false) {
                   this->button14->Visible = true;
               }
               if (map[8] == false) {
                   this->button15->Visible = true;
               }
               if (map[9] == false) {
                   this->button16->Visible = true;
               }
           }

           void button_display_cannon() {
               if (map[10] == false) {
                   this->button17->Visible = true;
               }
               if (map[11] == false) {
                   this->button18->Visible = true;
               }
               if (map[12] == false) {
                   this->button19->Visible = true;
               }
               if (map[13] == false) {
                   this->button20->Visible = true;
               }
               if (map[14] == false) {
                   this->button21->Visible = true;
               }
           }

           void button_display_landmine() {
               if (map[15] == false) {
                   this->button22->Visible = true;
               }
               if (map[16] == false) {
                   this->button23->Visible = true;
               }
               if (map[17] == false) {
                   this->button24->Visible = true;
               }
               if (map[18] == false) {
                   this->button25->Visible = true;
               }
               if (map[19] == false) {
                   this->button26->Visible = true;
               }
           }

           void button_display_bomb() {
               if (map[20] == false) {
                   this->button27->Visible = true;
               }
               if (map[21] == false) {
                   this->button28->Visible = true;
               }
               if (map[22] == false) {
                   this->button29->Visible = true;
               }
               if (map[23] == false) {
                   this->button30->Visible = true;
               }
               if (map[24] == false) {
                   this->button31->Visible = true;
               }
           }


#pragma endregion
    private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
        // main
        if (system_counter == 0) {
            initialize();
        }

        //plot_HMI();
        text_displayer();
        pictureBox1->Invalidate();
        system_counter++;
    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { // back
        this->Close();
    }
    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { // laser gun
        if (coin >= 20) {
            coin -= 20;
            button_display_laser();
        }
    }
    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { // machine gun
        if (coin >= 40) {
            coin -= 40;
            button_display_machine();
        }
    }
    private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) { // cannon
        if (coin >= 50) {
            coin -= 50;
            button_display_cannon();
        }
    }
    private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) { // landmine
        if (coin >= 15) {
            coin -= 15;
            button_display_landmine();
        }
    }
    private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) { // bomb
        if (coin >= 35) {
            coin -= 35;
            button_display_bomb();
        }
    }
    private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) { // map[0]
        map[0] = true;
        button_hidden();
    }
    private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) { // map[1]
        map[1] = true;
        button_hidden();
    }
    private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) { // map[2]
        map[2] = true;
        button_hidden();
    }
    private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) { // map[3]
        map[3] = true;
        button_hidden();
    }
    private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) { // map[4]
        map[4] = true;
        button_hidden();
    }
    private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) { // map[5]
        map[5] = true;
        button_hidden();
    }
    private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) { // map[6]
        map[6] = true;
        button_hidden();
    }
    private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) { // map[7]
        map[7] = true;
        button_hidden();
    }
    private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) { // map[8]
        map[8] = true;
        button_hidden();
    }
    private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) { // map[9]
        map[9] = true;
        button_hidden();
    }
    private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) { // map[10]
        map[10] = true;
        button_hidden();
    }
    private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) { // map[11]
        map[11] = true;
        button_hidden();
    }
    private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) { // map[12]
        map[12] = true;
        button_hidden();
    }
    private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) { // map[13]
        map[13] = true;
        button_hidden();
    }
    private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) { // map[14]
        map[14] = true;
        button_hidden();
    }
    private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) { // map[15]
        map[15] = true;
        button_hidden();
    }
    private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) { // map[16]
        map[16] = true;
        button_hidden();
    }
    private: System::Void button24_Click(System::Object^ sender, System::EventArgs^ e) { // map[17]
        map[17] = true;
        button_hidden();
    }
    private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) { // map[18]
        map[18] = true;
        button_hidden();
    }
    private: System::Void button26_Click(System::Object^ sender, System::EventArgs^ e) { // map[19]
        map[19] = true;
        button_hidden();
    }
    private: System::Void button27_Click(System::Object^ sender, System::EventArgs^ e) { // map[20]
        map[20] = true;
        button_hidden();
    }
    private: System::Void button28_Click(System::Object^ sender, System::EventArgs^ e) { // map[21]
        map[21] = true;
        button_hidden();
    }
    private: System::Void button29_Click(System::Object^ sender, System::EventArgs^ e) { // map[22]
        map[22] = true;
        button_hidden();
    }
    private: System::Void button30_Click(System::Object^ sender, System::EventArgs^ e) { // map[23]
        map[23] = true;
        button_hidden();
    }
    private: System::Void button31_Click(System::Object^ sender, System::EventArgs^ e) { // map[24]
        map[24] = true;
        button_hidden();
    }
    };
}