#pragma once
#include"gameruleform.h"
#include"playgameform.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	public: System::Windows::Forms::Label^ name;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	public:
	private:




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
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->name = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::Gold;
            this->button1->Font = (gcnew System::Drawing::Font(L"新細明體", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button1->Location = System::Drawing::Point(686, 192);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(309, 54);
            this->button1->TabIndex = 0;
            this->button1->Text = L"play game";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
            // 
            // button2
            // 
            this->button2->BackColor = System::Drawing::Color::Gold;
            this->button2->Font = (gcnew System::Drawing::Font(L"新細明體", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button2->Location = System::Drawing::Point(686, 295);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(309, 54);
            this->button2->TabIndex = 1;
            this->button2->Text = L"game rule";
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
            // 
            // button3
            // 
            this->button3->BackColor = System::Drawing::Color::Gold;
            this->button3->Font = (gcnew System::Drawing::Font(L"新細明體", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button3->Location = System::Drawing::Point(686, 406);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(309, 54);
            this->button3->TabIndex = 2;
            this->button3->Text = L"exit game";
            this->button3->UseVisualStyleBackColor = false;
            this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
            // 
            // name
            // 
            this->name->AutoSize = true;
            this->name->Font = (gcnew System::Drawing::Font(L"新細明體", 50, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->name->ForeColor = System::Drawing::Color::Red;
            this->name->Location = System::Drawing::Point(55, 40);
            this->name->Name = L"name";
            this->name->Size = System::Drawing::Size(569, 84);
            this->name->TabIndex = 3;
            this->name->Text = L"Defense Mission";
            this->name->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label1->ForeColor = System::Drawing::Color::Red;
            this->label1->Location = System::Drawing::Point(191, 138);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(529, 34);
            this->label1->TabIndex = 4;
            this->label1->Text = L"Protecting our homeland with our lives.";
            this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click_1);
            // 
            // pictureBox1
            // 
            System::Drawing::Image^ img = System::Drawing::Image::FromFile("soviet.jpg");
            this->pictureBox1->Image = img;
            //this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(147, 192);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(307, 355);
            this->pictureBox1->TabIndex = 5;
            this->pictureBox1->TabStop = false;
            this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::LemonChiffon;
            this->ClientSize = System::Drawing::Size(1182, 653);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->name);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->ForeColor = System::Drawing::SystemColors::ControlText;
            this->Name = L"Form1";
            this->Text = L"Defense Mission";
            this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        defense_mission::gameruleform^ gamerule = gcnew defense_mission::gameruleform();
        gamerule->Show();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        defense_mission::playgameform^ playgame = gcnew defense_mission::playgameform();
        playgame->Show();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
