#pragma once

namespace defense_mission {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// gameoverform 的摘要
	/// </summary>
	public ref class gameoverform : public System::Windows::Forms::Form
	{
	public:
		gameoverform(void)
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
		~gameoverform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;

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
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label1->Location = System::Drawing::Point(162, 108);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(192, 42);
            this->label1->TabIndex = 0;
            this->label1->Text = L"GameOver";
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::Gold;
            this->button1->Font = (gcnew System::Drawing::Font(L"新細明體", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button1->Location = System::Drawing::Point(123, 218);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(271, 71);
            this->button1->TabIndex = 1;
            this->button1->Text = L"EXIT";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &gameoverform::button1_Click);
            // 
            // gameoverform
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::LemonChiffon;
            this->ClientSize = System::Drawing::Size(545, 391);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->label1);
            this->Name = L"gameoverform";
            this->Text = L"GameOver";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }
    };
}
