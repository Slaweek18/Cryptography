#pragma once
#include "MyForm.h"
#include "Transposition.h"
#include "Feistel.h"
namespace SPZKurs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Encrypt
	/// </summary>
	public ref class Encrypt : public System::Windows::Forms::Form
	{
	public:
		Encrypt(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Encrypt()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ PathFile;

	private: System::Windows::Forms::Button^ openFileEnc;
	private: System::Windows::Forms::RadioButton^ radioFeist;
	private: System::Windows::Forms::RadioButton^ radioTrans;
	private: System::Windows::Forms::Button^ buttonKey;
	private: System::Windows::Forms::TextBox^ textBoxKey;

	private: System::Windows::Forms::Button^ buttonEncrypt;


	private: System::Windows::Forms::ToolStripMenuItem^ повернутисяВГоловнеМенюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ вийтиЗПрограмиToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ вихідToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2;


	private: System::Windows::Forms::ToolStripMenuItem^ проВікноToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox1;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Encrypt::typeid));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->PathFile = (gcnew System::Windows::Forms::TextBox());
			this->openFileEnc = (gcnew System::Windows::Forms::Button());
			this->radioFeist = (gcnew System::Windows::Forms::RadioButton());
			this->radioTrans = (gcnew System::Windows::Forms::RadioButton());
			this->buttonKey = (gcnew System::Windows::Forms::Button());
			this->textBoxKey = (gcnew System::Windows::Forms::TextBox());
			this->buttonEncrypt = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->вихідToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->проВікноToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"Text files(*.txt)|*.txt";
			// 
			// PathFile
			// 
			this->PathFile->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->PathFile->Cursor = System::Windows::Forms::Cursors::Default;
			this->PathFile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PathFile->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->PathFile->Location = System::Drawing::Point(426, 106);
			this->PathFile->MaximumSize = System::Drawing::Size(400, 30);
			this->PathFile->Multiline = true;
			this->PathFile->Name = L"PathFile";
			this->PathFile->ReadOnly = true;
			this->PathFile->Size = System::Drawing::Size(400, 30);
			this->PathFile->TabIndex = 2;
			// 
			// openFileEnc
			// 
			this->openFileEnc->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->openFileEnc->Cursor = System::Windows::Forms::Cursors::Hand;
			this->openFileEnc->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->openFileEnc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->openFileEnc->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->openFileEnc->Location = System::Drawing::Point(501, 43);
			this->openFileEnc->Name = L"openFileEnc";
			this->openFileEnc->Size = System::Drawing::Size(260, 45);
			this->openFileEnc->TabIndex = 3;
			this->openFileEnc->Text = L"Вибрати файл";
			this->openFileEnc->UseVisualStyleBackColor = false;
			this->openFileEnc->Click += gcnew System::EventHandler(this, &Encrypt::openFileEnc_Click_1);
			// 
			// radioFeist
			// 
			this->radioFeist->AutoSize = true;
			this->radioFeist->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->radioFeist->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioFeist->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioFeist->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioFeist->Location = System::Drawing::Point(367, 47);
			this->radioFeist->Name = L"radioFeist";
			this->radioFeist->Size = System::Drawing::Size(158, 33);
			this->radioFeist->TabIndex = 4;
			this->radioFeist->Text = L"Фейстеля";
			this->radioFeist->UseVisualStyleBackColor = false;
			// 
			// radioTrans
			// 
			this->radioTrans->AutoSize = true;
			this->radioTrans->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->radioTrans->Checked = true;
			this->radioTrans->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioTrans->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioTrans->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioTrans->Location = System::Drawing::Point(15, 47);
			this->radioTrans->Name = L"radioTrans";
			this->radioTrans->Size = System::Drawing::Size(253, 33);
			this->radioTrans->TabIndex = 5;
			this->radioTrans->TabStop = true;
			this->radioTrans->Text = L"Перестановочний";
			this->radioTrans->UseVisualStyleBackColor = false;
			// 
			// buttonKey
			// 
			this->buttonKey->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->buttonKey->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonKey->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonKey->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->buttonKey->Location = System::Drawing::Point(501, 343);
			this->buttonKey->Name = L"buttonKey";
			this->buttonKey->Size = System::Drawing::Size(260, 45);
			this->buttonKey->TabIndex = 6;
			this->buttonKey->Text = L"Згенерувати ключ";
			this->buttonKey->UseVisualStyleBackColor = false;
			this->buttonKey->Click += gcnew System::EventHandler(this, &Encrypt::buttonKey_Click);
			// 
			// textBoxKey
			// 
			this->textBoxKey->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->textBoxKey->Cursor = System::Windows::Forms::Cursors::Default;
			this->textBoxKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxKey->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->textBoxKey->Location = System::Drawing::Point(368, 406);
			this->textBoxKey->Multiline = true;
			this->textBoxKey->Name = L"textBoxKey";
			this->textBoxKey->ReadOnly = true;
			this->textBoxKey->Size = System::Drawing::Size(515, 40);
			this->textBoxKey->TabIndex = 7;
			// 
			// buttonEncrypt
			// 
			this->buttonEncrypt->BackColor = System::Drawing::Color::Green;
			this->buttonEncrypt->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonEncrypt->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonEncrypt->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonEncrypt->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->buttonEncrypt->Location = System::Drawing::Point(501, 473);
			this->buttonEncrypt->Name = L"buttonEncrypt";
			this->buttonEncrypt->Size = System::Drawing::Size(260, 60);
			this->buttonEncrypt->TabIndex = 8;
			this->buttonEncrypt->Text = L"Зашифрувати";
			this->buttonEncrypt->UseVisualStyleBackColor = false;
			this->buttonEncrypt->Click += gcnew System::EventHandler(this, &Encrypt::buttonEncrypt_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Transparent;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->вихідToolStripMenuItem,
					this->проВікноToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->MaximumSize = System::Drawing::Size(250, 42);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(250, 33);
			this->menuStrip1->TabIndex = 9;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// вихідToolStripMenuItem
			// 
			this->вихідToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripMenuItem1,
					this->toolStripMenuItem2
			});
			this->вихідToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->вихідToolStripMenuItem->ForeColor = System::Drawing::SystemColors::Control;
			this->вихідToolStripMenuItem->Name = L"вихідToolStripMenuItem";
			this->вихідToolStripMenuItem->Size = System::Drawing::Size(75, 29);
			this->вихідToolStripMenuItem->Text = L"Вихід";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(372, 30);
			this->toolStripMenuItem1->Text = L"Повернутися в головне меню";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &Encrypt::toolStripMenuItem1_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(372, 30);
			this->toolStripMenuItem2->Text = L"Вийти з програми";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &Encrypt::toolStripMenuItem2_Click);
			// 
			// проВікноToolStripMenuItem
			// 
			this->проВікноToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->проВікноToolStripMenuItem->ForeColor = System::Drawing::SystemColors::Control;
			this->проВікноToolStripMenuItem->Name = L"проВікноToolStripMenuItem";
			this->проВікноToolStripMenuItem->Size = System::Drawing::Size(113, 29);
			this->проВікноToolStripMenuItem->Text = L"Про вікно";
			this->проВікноToolStripMenuItem->Click += gcnew System::EventHandler(this, &Encrypt::проВікноToolStripMenuItem_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Transparent;
			this->groupBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->groupBox1->Controls->Add(this->radioFeist);
			this->groupBox1->Controls->Add(this->radioTrans);
			this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Arial Black", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->ForeColor = System::Drawing::Color::Gold;
			this->groupBox1->Location = System::Drawing::Point(358, 197);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->groupBox1->Size = System::Drawing::Size(533, 111);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Метод шифрування";
			// 
			// Encrypt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1255, 573);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->buttonEncrypt);
			this->Controls->Add(this->textBoxKey);
			this->Controls->Add(this->buttonKey);
			this->Controls->Add(this->openFileEnc);
			this->Controls->Add(this->PathFile);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1273, 620);
			this->MinimumSize = System::Drawing::Size(1273, 620);
			this->Name = L"Encrypt";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Encrypt";
			this->Load += gcnew System::EventHandler(this, &Encrypt::Encrypt_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Encrypt_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void openFileEnc_Click_1(System::Object^ sender, System::EventArgs^ e);

	private: System::Void buttonKey_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonEncrypt_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void toolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void toolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void проВікноToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

};
}
