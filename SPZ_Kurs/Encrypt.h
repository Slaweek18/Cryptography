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
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ вийтиToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ повернутисяВГоловнеМенюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ вийтиЗПрограмиToolStripMenuItem;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ PathFile;

	private: System::Windows::Forms::Button^ openFileEnc;
	private: System::Windows::Forms::RadioButton^ radioFeist;
	private: System::Windows::Forms::RadioButton^ radioTrans;
	private: System::Windows::Forms::Button^ buttonKey;
	private: System::Windows::Forms::TextBox^ textBoxKey;

	private: System::Windows::Forms::Button^ buttonEncrypt;

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->вийтиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->повернутисяВГоловнеМенюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вийтиЗПрограмиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->PathFile = (gcnew System::Windows::Forms::TextBox());
			this->openFileEnc = (gcnew System::Windows::Forms::Button());
			this->radioFeist = (gcnew System::Windows::Forms::RadioButton());
			this->radioTrans = (gcnew System::Windows::Forms::RadioButton());
			this->buttonKey = (gcnew System::Windows::Forms::Button());
			this->textBoxKey = (gcnew System::Windows::Forms::TextBox());
			this->buttonEncrypt = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->вийтиToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->MaximumSize = System::Drawing::Size(90, 41);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(90, 33);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// вийтиToolStripMenuItem
			// 
			this->вийтиToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->повернутисяВГоловнеМенюToolStripMenuItem,
					this->вийтиЗПрограмиToolStripMenuItem
			});
			this->вийтиToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->вийтиToolStripMenuItem->Name = L"вийтиToolStripMenuItem";
			this->вийтиToolStripMenuItem->Size = System::Drawing::Size(75, 29);
			this->вийтиToolStripMenuItem->Text = L"Вихід";
			// 
			// повернутисяВГоловнеМенюToolStripMenuItem
			// 
			this->повернутисяВГоловнеМенюToolStripMenuItem->Name = L"повернутисяВГоловнеМенюToolStripMenuItem";
			this->повернутисяВГоловнеМенюToolStripMenuItem->Size = System::Drawing::Size(372, 30);
			this->повернутисяВГоловнеМенюToolStripMenuItem->Text = L"Повернутися в головне меню";
			this->повернутисяВГоловнеМенюToolStripMenuItem->Click += gcnew System::EventHandler(this, &Encrypt::повернутисяВГоловнеМенюToolStripMenuItem_Click);
			// 
			// вийтиЗПрограмиToolStripMenuItem
			// 
			this->вийтиЗПрограмиToolStripMenuItem->Name = L"вийтиЗПрограмиToolStripMenuItem";
			this->вийтиЗПрограмиToolStripMenuItem->Size = System::Drawing::Size(372, 30);
			this->вийтиЗПрограмиToolStripMenuItem->Text = L"Вийти з програми";
			this->вийтиЗПрограмиToolStripMenuItem->Click += gcnew System::EventHandler(this, &Encrypt::вийтиЗПрограмиToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"Text files(*.txt)|*.txt|All files(*.*)|*.*";
			// 
			// PathFile
			// 
			this->PathFile->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->PathFile->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->PathFile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PathFile->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->PathFile->Location = System::Drawing::Point(390, 105);
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
			this->openFileEnc->Location = System::Drawing::Point(466, 38);
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
			this->radioFeist->Location = System::Drawing::Point(668, 264);
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
			this->radioTrans->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioTrans->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->radioTrans->Location = System::Drawing::Point(358, 264);
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
			this->buttonKey->Location = System::Drawing::Point(466, 343);
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
			this->textBoxKey->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBoxKey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxKey->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->textBoxKey->Location = System::Drawing::Point(358, 403);
			this->textBoxKey->Multiline = true;
			this->textBoxKey->Name = L"textBoxKey";
			this->textBoxKey->ReadOnly = true;
			this->textBoxKey->Size = System::Drawing::Size(468, 40);
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
			this->buttonEncrypt->Location = System::Drawing::Point(466, 478);
			this->buttonEncrypt->Name = L"buttonEncrypt";
			this->buttonEncrypt->Size = System::Drawing::Size(260, 60);
			this->buttonEncrypt->TabIndex = 8;
			this->buttonEncrypt->Text = L"Зашифрувати";
			this->buttonEncrypt->UseVisualStyleBackColor = false;
			this->buttonEncrypt->Click += gcnew System::EventHandler(this, &Encrypt::buttonEncrypt_Click);
			// 
			// Encrypt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1205, 573);
			this->Controls->Add(this->buttonEncrypt);
			this->Controls->Add(this->textBoxKey);
			this->Controls->Add(this->buttonKey);
			this->Controls->Add(this->radioTrans);
			this->Controls->Add(this->radioFeist);
			this->Controls->Add(this->openFileEnc);
			this->Controls->Add(this->PathFile);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1223, 620);
			this->MinimumSize = System::Drawing::Size(1223, 620);
			this->Name = L"Encrypt";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Encrypt";
			this->Load += gcnew System::EventHandler(this, &Encrypt::Encrypt_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Encrypt_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void вийтиЗПрограмиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void повернутисяВГоловнеМенюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void openFileEnc_Click_1(System::Object^ sender, System::EventArgs^ e);

	private: System::Void buttonKey_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonEncrypt_Click(System::Object^ sender, System::EventArgs^ e);
};
}
