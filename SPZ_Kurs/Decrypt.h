#pragma once
#include"MyForm.h"

namespace SPZKurs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Decrypt
	/// </summary>
	public ref class Decrypt : public System::Windows::Forms::Form
	{
	public:
		Decrypt(void)
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
		~Decrypt()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	private: System::Windows::Forms::Button^ openFileDec;

	private: System::Windows::Forms::TextBox^ PathFile;
	private: System::Windows::Forms::Button^ buttonDecrypt;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ вихідToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ проВікноToolStripMenuItem;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Decrypt::typeid));
			this->openFileDec = (gcnew System::Windows::Forms::Button());
			this->PathFile = (gcnew System::Windows::Forms::TextBox());
			this->buttonDecrypt = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->вихідToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->проВікноToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDec
			// 
			this->openFileDec->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->openFileDec->Cursor = System::Windows::Forms::Cursors::Hand;
			this->openFileDec->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->openFileDec->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->openFileDec->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->openFileDec->Location = System::Drawing::Point(363, 48);
			this->openFileDec->Name = L"openFileDec";
			this->openFileDec->Size = System::Drawing::Size(260, 45);
			this->openFileDec->TabIndex = 5;
			this->openFileDec->Text = L"Вибрати файл";
			this->openFileDec->UseVisualStyleBackColor = false;
			this->openFileDec->Click += gcnew System::EventHandler(this, &Decrypt::openFileDec_Click);
			// 
			// PathFile
			// 
			this->PathFile->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->PathFile->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->PathFile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->PathFile->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->PathFile->Location = System::Drawing::Point(282, 116);
			this->PathFile->MaximumSize = System::Drawing::Size(400, 30);
			this->PathFile->Multiline = true;
			this->PathFile->Name = L"PathFile";
			this->PathFile->ReadOnly = true;
			this->PathFile->Size = System::Drawing::Size(400, 30);
			this->PathFile->TabIndex = 4;
			// 
			// buttonDecrypt
			// 
			this->buttonDecrypt->BackColor = System::Drawing::Color::Green;
			this->buttonDecrypt->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonDecrypt->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonDecrypt->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonDecrypt->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->buttonDecrypt->Location = System::Drawing::Point(363, 280);
			this->buttonDecrypt->Name = L"buttonDecrypt";
			this->buttonDecrypt->Size = System::Drawing::Size(260, 60);
			this->buttonDecrypt->TabIndex = 9;
			this->buttonDecrypt->Text = L"Дешифрувати";
			this->buttonDecrypt->UseVisualStyleBackColor = false;
			this->buttonDecrypt->Click += gcnew System::EventHandler(this, &Decrypt::buttonDecrypt_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"Text files(*.tra)|*.tra|Text files(*.fei)|*.fei";
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
			this->menuStrip1->TabIndex = 10;
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
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &Decrypt::toolStripMenuItem1_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(372, 30);
			this->toolStripMenuItem2->Text = L"Вийти з програми";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &Decrypt::toolStripMenuItem2_Click);
			// 
			// проВікноToolStripMenuItem
			// 
			this->проВікноToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->проВікноToolStripMenuItem->ForeColor = System::Drawing::SystemColors::Control;
			this->проВікноToolStripMenuItem->Name = L"проВікноToolStripMenuItem";
			this->проВікноToolStripMenuItem->Size = System::Drawing::Size(113, 29);
			this->проВікноToolStripMenuItem->Text = L"Про вікно";
			this->проВікноToolStripMenuItem->Click += gcnew System::EventHandler(this, &Decrypt::проВікноToolStripMenuItem_Click);
			// 
			// Decrypt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(965, 449);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->buttonDecrypt);
			this->Controls->Add(this->openFileDec);
			this->Controls->Add(this->PathFile);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Decrypt";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Decrypt";
			this->Load += gcnew System::EventHandler(this, &Decrypt::Decrypt_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Decrypt_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void toolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e); 

	private: System::Void toolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void openFileDec_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void buttonDecrypt_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void проВікноToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
