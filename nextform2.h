#pragma once
#include "playgameform2.h"

namespace defense_mission {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// nextform2 的摘要
	/// </summary>
	public ref class nextform2 : public System::Windows::Forms::Form
	{
	public:
		nextform2(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~nextform2()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::Label^ label1;
    protected:
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label1->Location = System::Drawing::Point(122, 85);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(167, 34);
            this->label1->TabIndex = 0;
            this->label1->Text = L"You Win!!!";
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::Gold;
            this->button1->Font = (gcnew System::Drawing::Font(L"新細明體", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button1->Location = System::Drawing::Point(111, 147);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(178, 64);
            this->button1->TabIndex = 1;
            this->button1->Text = L"NEXT";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &nextform2::button1_Click);
            // 
            // button2
            // 
            this->button2->BackColor = System::Drawing::Color::Gold;
            this->button2->Font = (gcnew System::Drawing::Font(L"新細明體", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button2->Location = System::Drawing::Point(111, 230);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(178, 58);
            this->button2->TabIndex = 2;
            this->button2->Text = L"EXIT";
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Click += gcnew System::EventHandler(this, &nextform2::button2_Click);
            // 
            // nextform2
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::LemonChiffon;
            this->ClientSize = System::Drawing::Size(438, 328);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->label1);
            this->Name = L"nextform2";
            this->Text = L"nextstage";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        playgameform2^ play2 = gcnew playgameform2();

        // 顯示SecondForm
        play2->Show();
        
        this->Close();
    }
    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }
    };
}
