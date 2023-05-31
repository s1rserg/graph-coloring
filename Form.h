#pragma once

#include "Algorithm.h"
#include "Graph.h"
#include <string>

namespace CppCLRWinFormsProject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Form : public System::Windows::Forms::Form {
    public:
        Form(void) {
            InitializeComponent();
            graph = new Graph();
        }

    protected:
        ~Form() {
            if (components) {
                delete components;
            }
            delete graph;
        }

    private:
        System::Windows::Forms::NumericUpDown^ matrixSize;
        System::Windows::Forms::Label^ numVerticesLabel;




        System::Windows::Forms::Button^ colorBtn;
        System::Windows::Forms::DataGridView^ matrixTable;
        System::Windows::Forms::Label^ matrixLabel;
        System::ComponentModel::Container^ components;
        System::Windows::Forms::Label^ solutionLabel;
        System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::Label^ GraphLabel;

    private: System::Windows::Forms::Label^ solLabel;
    private: System::Windows::Forms::RadioButton^ greedyRB;
    private: System::Windows::Forms::RadioButton^ mrvRB;
    private: System::Windows::Forms::RadioButton^ degreeRB;
    private: System::Windows::Forms::Panel^ rbPanel;
    private: System::Windows::Forms::Button^ textButton;



           Graph* graph;
    private: System::Windows::Forms::TextBox^ fileTextBox;

           char algorithmName;

#pragma region Windows Form Designer generated code

           void InitializeComponent(void) {
               System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
               this->matrixSize = (gcnew System::Windows::Forms::NumericUpDown());
               this->numVerticesLabel = (gcnew System::Windows::Forms::Label());
               this->colorBtn = (gcnew System::Windows::Forms::Button());
               this->matrixTable = (gcnew System::Windows::Forms::DataGridView());
               this->matrixLabel = (gcnew System::Windows::Forms::Label());
               this->solutionLabel = (gcnew System::Windows::Forms::Label());
               this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
               this->GraphLabel = (gcnew System::Windows::Forms::Label());
               this->solLabel = (gcnew System::Windows::Forms::Label());
               this->greedyRB = (gcnew System::Windows::Forms::RadioButton());
               this->mrvRB = (gcnew System::Windows::Forms::RadioButton());
               this->degreeRB = (gcnew System::Windows::Forms::RadioButton());
               this->rbPanel = (gcnew System::Windows::Forms::Panel());
               this->textButton = (gcnew System::Windows::Forms::Button());
               this->fileTextBox = (gcnew System::Windows::Forms::TextBox());
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->matrixSize))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->matrixTable))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
               this->rbPanel->SuspendLayout();
               this->SuspendLayout();
               // 
               // matrixSize
               // 
               this->matrixSize->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                   static_cast<System::Int32>(static_cast<System::Byte>(255)));
               this->matrixSize->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->matrixSize->Location = System::Drawing::Point(16, 47);
               this->matrixSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
               this->matrixSize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
               this->matrixSize->Name = L"matrixSize";
               this->matrixSize->Size = System::Drawing::Size(204, 32);
               this->matrixSize->TabIndex = 5;
               this->matrixSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
               this->matrixSize->ValueChanged += gcnew System::EventHandler(this, &Form::numericUpDown1_ValueChanged);
               // 
               // numVerticesLabel
               // 
               this->numVerticesLabel->AutoSize = true;
               this->numVerticesLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->numVerticesLabel->Location = System::Drawing::Point(12, 21);
               this->numVerticesLabel->Name = L"numVerticesLabel";
               this->numVerticesLabel->Size = System::Drawing::Size(166, 23);
               this->numVerticesLabel->TabIndex = 6;
               this->numVerticesLabel->Text = L"Кількість вершин";
               // 
               // colorBtn
               // 
               this->colorBtn->BackColor = System::Drawing::Color::Orange;
               this->colorBtn->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->colorBtn->Location = System::Drawing::Point(193, 617);
               this->colorBtn->Name = L"colorBtn";
               this->colorBtn->Size = System::Drawing::Size(203, 60);
               this->colorBtn->TabIndex = 10;
               this->colorBtn->Text = L"Розфарбувати";
               this->colorBtn->UseVisualStyleBackColor = false;
               this->colorBtn->Click += gcnew System::EventHandler(this, &Form::button1_Click);
               // 
               // matrixTable
               // 
               this->matrixTable->AllowUserToAddRows = false;
               this->matrixTable->AllowUserToDeleteRows = false;
               this->matrixTable->AllowUserToResizeColumns = false;
               this->matrixTable->AllowUserToResizeRows = false;
               this->matrixTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
               this->matrixTable->ColumnHeadersVisible = false;
               dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
               dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
               dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
               dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
               dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
               dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
               this->matrixTable->DefaultCellStyle = dataGridViewCellStyle1;
               this->matrixTable->Location = System::Drawing::Point(16, 120);
               this->matrixTable->Name = L"matrixTable";
               this->matrixTable->RowHeadersVisible = false;
               this->matrixTable->Size = System::Drawing::Size(425, 445);
               this->matrixTable->TabIndex = 9;
               this->matrixTable->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form::matrix_table_CellValueChanged);
               // 
               // matrixLabel
               // 
               this->matrixLabel->AutoSize = true;
               this->matrixLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->matrixLabel->Location = System::Drawing::Point(12, 94);
               this->matrixLabel->Name = L"matrixLabel";
               this->matrixLabel->Size = System::Drawing::Size(190, 23);
               this->matrixLabel->TabIndex = 12;
               this->matrixLabel->Text = L"Матриця суміжності";
               // 
               // solutionLabel
               // 
               this->solutionLabel->AutoSize = true;
               this->solutionLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->solutionLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->solutionLabel->Location = System::Drawing::Point(901, 177);
               this->solutionLabel->MaximumSize = System::Drawing::Size(350, 350);
               this->solutionLabel->MinimumSize = System::Drawing::Size(350, 350);
               this->solutionLabel->Name = L"solutionLabel";
               this->solutionLabel->Size = System::Drawing::Size(350, 350);
               this->solutionLabel->TabIndex = 13;
               // 
               // pictureBox1
               // 
               this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->pictureBox1->Location = System::Drawing::Point(469, 145);
               this->pictureBox1->Name = L"pictureBox1";
               this->pictureBox1->Size = System::Drawing::Size(400, 400);
               this->pictureBox1->TabIndex = 14;
               this->pictureBox1->TabStop = false;
               this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form::DrawGraph);
               // 
               // GraphLabel
               // 
               this->GraphLabel->AutoSize = true;
               this->GraphLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->GraphLabel->Location = System::Drawing::Point(465, 120);
               this->GraphLabel->Name = L"GraphLabel";
               this->GraphLabel->Size = System::Drawing::Size(281, 23);
               this->GraphLabel->TabIndex = 15;
               this->GraphLabel->Text = L"Графічне представлення графа";
               // 
               // solLabel
               // 
               this->solLabel->AutoSize = true;
               this->solLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->solLabel->Location = System::Drawing::Point(897, 154);
               this->solLabel->Name = L"solLabel";
               this->solLabel->Size = System::Drawing::Size(85, 23);
               this->solLabel->TabIndex = 16;
               this->solLabel->Text = L"Рішення";
               // 
               // greedyRB
               // 
               this->greedyRB->AutoSize = true;
               this->greedyRB->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->greedyRB->Location = System::Drawing::Point(3, 3);
               this->greedyRB->Name = L"greedyRB";
               this->greedyRB->Size = System::Drawing::Size(116, 27);
               this->greedyRB->TabIndex = 3;
               this->greedyRB->Text = L"Жадібний";
               this->greedyRB->UseVisualStyleBackColor = true;
               // 
               // mrvRB
               // 
               this->mrvRB->AutoSize = true;
               this->mrvRB->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->mrvRB->Location = System::Drawing::Point(3, 46);
               this->mrvRB->Name = L"mrvRB";
               this->mrvRB->Size = System::Drawing::Size(73, 27);
               this->mrvRB->TabIndex = 4;
               this->mrvRB->Text = L"MRV";
               this->mrvRB->UseVisualStyleBackColor = true;
               // 
               // degreeRB
               // 
               this->degreeRB->AutoSize = true;
               this->degreeRB->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->degreeRB->Location = System::Drawing::Point(3, 88);
               this->degreeRB->Name = L"degreeRB";
               this->degreeRB->Size = System::Drawing::Size(119, 27);
               this->degreeRB->TabIndex = 5;
               this->degreeRB->Text = L"Степенева";
               this->degreeRB->UseVisualStyleBackColor = true;
               // 
               // rbPanel
               // 
               this->rbPanel->Controls->Add(this->degreeRB);
               this->rbPanel->Controls->Add(this->mrvRB);
               this->rbPanel->Controls->Add(this->greedyRB);
               this->rbPanel->Location = System::Drawing::Point(16, 588);
               this->rbPanel->Name = L"rbPanel";
               this->rbPanel->Size = System::Drawing::Size(132, 119);
               this->rbPanel->TabIndex = 8;
               // 
               // textButton
               // 
               this->textButton->BackColor = System::Drawing::Color::Orange;
               this->textButton->Enabled = false;
               this->textButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->textButton->Location = System::Drawing::Point(977, 545);
               this->textButton->Name = L"textButton";
               this->textButton->Size = System::Drawing::Size(209, 50);
               this->textButton->TabIndex = 18;
               this->textButton->Text = L"Зберегти результати";
               this->textButton->UseVisualStyleBackColor = false;
               this->textButton->Visible = false;
               this->textButton->Click += gcnew System::EventHandler(this, &Form::textButton_Click);
               // 
               // fileTextBox
               // 
               this->fileTextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                   static_cast<System::Int32>(static_cast<System::Byte>(255)));
               this->fileTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->fileTextBox->Location = System::Drawing::Point(901, 607);
               this->fileTextBox->MaximumSize = System::Drawing::Size(350, 60);
               this->fileTextBox->MinimumSize = System::Drawing::Size(350, 60);
               this->fileTextBox->Name = L"fileTextBox";
               this->fileTextBox->ReadOnly = true;
               this->fileTextBox->Size = System::Drawing::Size(350, 32);
               this->fileTextBox->TabIndex = 19;
               this->fileTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
               this->fileTextBox->Visible = false;
               // 
               // Form
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                   static_cast<System::Int32>(static_cast<System::Byte>(255)));
               this->ClientSize = System::Drawing::Size(1268, 714);
               this->Controls->Add(this->fileTextBox);
               this->Controls->Add(this->textButton);
               this->Controls->Add(this->solLabel);
               this->Controls->Add(this->GraphLabel);
               this->Controls->Add(this->pictureBox1);
               this->Controls->Add(this->solutionLabel);
               this->Controls->Add(this->matrixLabel);
               this->Controls->Add(this->colorBtn);
               this->Controls->Add(this->matrixTable);
               this->Controls->Add(this->rbPanel);
               this->Controls->Add(this->numVerticesLabel);
               this->Controls->Add(this->matrixSize);
               this->Name = L"Form";
               this->Text = L"Graph Coloring";
               this->Load += gcnew System::EventHandler(this, &Form::Form1_Load);
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->matrixSize))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->matrixTable))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
               this->rbPanel->ResumeLayout(false);
               this->rbPanel->PerformLayout();
               this->ResumeLayout(false);
               this->PerformLayout();

           }

#pragma endregion

    private:

        System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e);

        System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e);

        System::Void matrix_table_CellValueChanged(System::Object^ sender, DataGridViewCellEventArgs^ e);

        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);

        bool scanmatrix(int size);

        void DrawGraph(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);

        System::Void textButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
