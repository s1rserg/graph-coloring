#include "pch.h"
#include "Form.h"

System::Void CppCLRWinFormsProject::Form::button1_Click(System::Object^ sender, System::EventArgs^ e) {
    int size = Convert::ToInt32(matrixSize->Value);
    if (!scanmatrix(size)) return;

    solutionLabel->Text = "";
    fileTextBox->Visible = false;
    String^ solutionText = "";

    if (greedyRB->Checked) {
        algorithmName = 'g';
        GreedyAlgorithm algorithm;
        graph->setColors(algorithm.solve(graph->getMatrix()));

        solutionText += "Хроматичне число: " + algorithm.getChromaticNumber() + "\n";
        for (int i = 0; i < size; i++) {
            solutionText += "V" + (i + 1) + ": " + graph->getElementColors(i) + "    ";
        }
        solutionText += "\n\nПорядок:\n";
        for (int i = 0; i < size; i++) {
            solutionText += "V" + (i + 1) + ": " + (algorithm.getElementOrder(i) + 1) + "    ";
        }
        solutionText += "\n\nК-сть перебраних кольорів: " + algorithm.getColorsTried();
        solutionLabel->Text = solutionText;
        pictureBox1->Invalidate();
        textButton->Visible = true;
        textButton->Enabled = true;
    }
    else if (mrvRB->Checked) {
        algorithmName = 'm';
        BacktrackingAlgorithm algorithm('m');
        graph->setColors(algorithm.solve(graph->getMatrix()));

        solutionText += "Хроматичне число: " + algorithm.getChromaticNumber() + "\n";
        for (int i = 0; i < size; i++) {
            solutionText += "V" + (i + 1) + ": " + graph->getElementColors(i) + "    ";
        }
        solutionText += "\n\nПорядок:\n";
        for (int i = 0; i < size; i++) {
            solutionText += "V" + (i + 1) + ": " + (algorithm.getElementOrder(i) + 1) + "    ";
        }
        solutionText += "\n\nК-сть вузлів у дереві пошуку: " + algorithm.getVerticesAssigned();
        solutionText += "\nПовернень: " + algorithm.getComebacks();
        solutionLabel->Text = solutionText;
        pictureBox1->Invalidate();
        textButton->Visible = true;
        textButton->Enabled = true;
    }
    else if(degreeRB->Checked) {
        algorithmName = 'd';
        BacktrackingAlgorithm algorithm('d');
        graph->setColors(algorithm.solve(graph->getMatrix()));

        solutionText += "Хроматичне число: " + algorithm.getChromaticNumber() + "\n";
        for (int i = 0; i < size; i++) {
            solutionText += "V" + (i + 1) + ": " + graph->getElementColors(i) + "    ";
        }
        solutionText += "\n\nПорядок:\n";
        for (int i = 0; i < size; i++) {
            solutionText += "V" + (i + 1) + ": " + (algorithm.getElementOrder(i) + 1) + "    ";
        }
        solutionText += "\n\nК-сть вузлів у дереві пошуку: " + algorithm.getVerticesAssigned();
        solutionText += "\nПовернень: " + algorithm.getComebacks();
        solutionLabel->Text = solutionText;
        pictureBox1->Invalidate();
        textButton->Visible = true;
        textButton->Enabled = true;
    }
    else {
        solutionLabel->Text = "Оберіть, будь ласка, операцію";
    }

}

bool CppCLRWinFormsProject::Form::scanmatrix(int size) {
    vector <vector<int>> matrix(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            try {
                matrix[i][j] = CppCLRWinFormsProject::Convert::ToInt32(matrixTable->Rows[i]->Cells[j]->Value);
            }
            catch (...) {
                matrixTable->Rows[i]->Cells[j]->Style->BackColor = Color::Red;
                solutionLabel->Text = "Некоректні символи у матриці суміжності. Будь ласка, видаліть їх та спробуйте ще раз";
                return false;
            }
            matrixTable->Rows[i]->Cells[j]->Style->BackColor = Color::White;
        }
    }
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            if (matrix[i][j] != 1 && matrix[i][j] != 0) {
                matrixTable->Rows[i]->Cells[j]->Style->BackColor = Color::Red;
                solutionLabel->Text = "Некоректні цифри у матриці суміжності. Будь ласка, вводьте лише або 0, або 1.";
                return false;
            }
            if (matrix[i][j] == 1 && matrix[j][i] != 1) {
                matrixTable->Rows[i]->Cells[j]->Style->BackColor = Color::Red;
                matrixTable->Rows[j]->Cells[i]->Style->BackColor = Color::Red;
                solutionLabel->Text = "Матриця суміжності є некоректною. Значення у рядку " + (i + 1) + " стовпці " + (j + 1) + " та у рядку " + (j + 1) + " стовпці " + (i + 1) + " мають бути ідентичними.";
                return false;
            }
        }
    }
    graph->setMatrix(matrix, size);
    return true;
}

void CppCLRWinFormsProject::Form::DrawGraph(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    vector<vector<int>> adjMatrix = graph->getMatrix();
    vector<int> colors = graph->getColors();

    System::Drawing::Graphics^ g = e->Graphics;

    int numVertices = adjMatrix.size();
    int radius = 170;

    int centerX = pictureBox1->Width / 2;
    int centerY = pictureBox1->Height / 2;

    cli::array<System::Drawing::Color>^ vertexColors = gcnew cli::array<System::Drawing::Color> {
        System::Drawing::Color::Khaki,
        System::Drawing::Color::LightCoral,
        System::Drawing::Color::LightGoldenrodYellow,
        System::Drawing::Color::LightGray,
        System::Drawing::Color::LightGreen,
        System::Drawing::Color::LightBlue,
        System::Drawing::Color::LightPink,
        System::Drawing::Color::LightSeaGreen,
        System::Drawing::Color::Orange,
        System::Drawing::Color::Orchid,
        System::Drawing::Color::OrangeRed,
        System::Drawing::Color::Tan,
        System::Drawing::Color::Aqua,
        System::Drawing::Color::Red,
        System::Drawing::Color::SandyBrown,
        System::Drawing::Color::Yellow,
        System::Drawing::Color::YellowGreen,
        System::Drawing::Color::Gold,
        System::Drawing::Color::Olive,
        System::Drawing::Color::Fuchsia,
        System::Drawing::Color::DarkSeaGreen
    };


    System::Drawing::Brush^ brush;
    double angle = 2 * Math::PI / numVertices;

    for (int i = 0; i < numVertices; i++){
        int x = centerX + (int)(radius * Math::Cos(angle * i));
        int y = centerY + (int)(radius * Math::Sin(angle * i));
        for (int j = 0; j < numVertices; j++){
            if (adjMatrix[i][j] == 1){
                int nextX = centerX + (int)(radius * Math::Cos(angle * j));
                int nextY = centerY + (int)(radius * Math::Sin(angle * j));
                if (i == j){
                    int startAngle = (int)(angle * i * 180 / Math::PI) - 45;
                    int sweepAngle = 360;

                    g->DrawArc(System::Drawing::Pens::Black, x - 20, y - 20, 40, 40, startAngle, sweepAngle);
                }else{
                    g->DrawLine(System::Drawing::Pens::Black, x , y, nextX, nextY);
                }
            }
        }
    }
    for (int i = 0; i < numVertices; i++) {
        int x = centerX + (int)(radius * Math::Cos(angle * i));
        int y = centerY + (int)(radius * Math::Sin(angle * i));
        System::Drawing::Color vertexColor;
        if (colors[i] >= 0 && colors[i] < vertexColors->Length) vertexColor = vertexColors[colors[i]];
        else vertexColor = System::Drawing::Color::Black;

        brush = gcnew System::Drawing::SolidBrush(vertexColor);
        g->FillEllipse(brush, x - 15, y - 15, 30, 30);
        System::String^ label;
        if (i + 1 < 10) label = " " + (i + 1);
        else label = "" + (i + 1);

        System::Drawing::Font^ font = gcnew System::Drawing::Font("Times New Roman", 18);
        System::Drawing::Brush^ brush = System::Drawing::Brushes::Black;
        g->DrawString(label, font, brush, x - 15, y - 15);
    }
}

System::Void CppCLRWinFormsProject::Form::textButton_Click(System::Object^ sender, System::EventArgs^ e) {
    fileTextBox->Visible = true;
    if (!graph->fileoutput()) {
        fileTextBox->Text = "Помилка при відкритті файлу";
        return;
    }

    ofstream outputFile;

    outputFile.open("result.txt", ios::app);

    if (outputFile.is_open()) {

        outputFile << endl << "Method of coloring: " << endl;

        if (algorithmName == 'g') {
            outputFile << "Greedy algorithm" << endl;
        }
        else if (algorithmName == 'm') {
            outputFile << "backtracking with MRV heuristic" << endl;
        }
        else if (algorithmName == 'd') {
            outputFile << "backtracking with degree heuristic" << endl;
        }

        outputFile.close();

    }
    else {
        fileTextBox->Text = "Помилка при відкритті файлу";
        return;
    }

    fileTextBox->Text = "Результати збережено";
}

System::Void CppCLRWinFormsProject::Form::Form1_Load(System::Object^ sender, System::EventArgs^ e) {
    matrixTable->ColumnCount = 1;
    matrixTable->RowCount = 1;
    matrixTable->AutoResizeColumns();
}

System::Void CppCLRWinFormsProject::Form::numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    matrixTable->ColumnCount = Convert::ToInt32(matrixSize->Value);
    matrixTable->RowCount = Convert::ToInt32(matrixSize->Value);
    matrixTable->AutoResizeColumns();
}

System::Void CppCLRWinFormsProject::Form::matrix_table_CellValueChanged(System::Object^ sender, DataGridViewCellEventArgs^ e) {
    matrixTable->AutoResizeColumns();
}