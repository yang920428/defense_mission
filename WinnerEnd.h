#pragma once
#include "playgameform3.h"

namespace defense_mission {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// WinnerEnd 的摘要
	/// </summary>
	public ref class WinnerEnd : public System::Windows::Forms::Form
	{
	public:
		WinnerEnd(void)
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
		~WinnerEnd()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Button^ button2;
    protected:

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
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->label1->Location = System::Drawing::Point(20, 56);
            this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(297, 40);
            this->label1->TabIndex = 1;
            this->label1->Text = L"Congratulations!!!";
            // 
            // button2
            // 
            this->button2->BackColor = System::Drawing::Color::Gold;
            this->button2->Font = (gcnew System::Drawing::Font(L"新細明體", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button2->Location = System::Drawing::Point(96, 151);
            this->button2->Margin = System::Windows::Forms::Padding(2);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(134, 46);
            this->button2->TabIndex = 3;
            this->button2->Text = L"EXIT";
            this->button2->UseVisualStyleBackColor = false;
            // 
            // WinnerEnd
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::LemonChiffon;
            this->ClientSize = System::Drawing::Size(328, 262);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->label1);
            this->Name = L"WinnerEnd";
            this->Text = L"WinnerEnd";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
	};
}
