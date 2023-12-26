#pragma once


namespace defense_mission {

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
        int coin = 0;
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
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(playgameform::typeid));
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::Gold;
            this->button1->Font = (gcnew System::Drawing::Font(L"新細明體", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(136)));
            this->button1->Location = System::Drawing::Point(1042, 0);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(137, 43);
            this->button1->TabIndex = 0;
            this->button1->Text = L"back";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &playgameform::button1_Click);
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(1, 113);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(1178, 493);
            this->pictureBox1->TabIndex = 1;
            this->pictureBox1->TabStop = false;
            // 
            // playgameform
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::LemonChiffon;
            this->ClientSize = System::Drawing::Size(1182, 653);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->button1);
            this->Name = L"playgameform";
            this->Text = L"gaming";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
	}
	};
}
