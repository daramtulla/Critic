#pragma once
#include <map>
#include <msclr/marshal_cppstd.h>
#include <array>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <istream>
#include <fstream>
#include <iomanip>
namespace Critic {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	map<string, int>delays;
	map<string, int>cancels;
	map<string, int>weathercancels;
	map<string, int>airlines;
	vector<int> airport;

	//quicksorting Delays

	int partition(vector<int>& arr, int low, int high)

	{
		int pivot = delays[to_string(arr[high])];
		
		int i = (low - 1); 



		for (int j = low; j <= high - 1; j++) {
			if (delays[to_string(arr[j])] <= pivot) {
				i++;
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[i + 1], arr[high]);
		return (i + 1); 
	}

	void quickSort(vector<int>& arr, int low, int high)

	{
		if (low < high) {
		
			int pi = partition(arr, low, high);

			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
	}

	//merge sort

	void merge(vector<int>& arr, int low, int mid, int high) {
		int n1 = mid - low + 1;
		int n2 = high - mid;
		vector<int> left(n1);
		vector<int> right(n2);
		for (int i = 0; i < n1; i++) {
			left[i] = arr[low + i];
		}
		for (int j = 0; j < n2; j++) {
			right[j] = arr[mid + 1 + j];
		}

		int i = 0, j = 0, k = low;
		while (i < n1 && j < n2) {
			if (cancels[to_string(left[i])] <= cancels[to_string(right[j])]) {
				arr[k] = left[i];
				i++;
			}
			else {
				arr[k] = right[j];
				j++;
			}
			k++;
		}
		while (i < n1) {
			arr[k] = left[i];
			i++;
			k++;
		}
		while (j < n2) {
			arr[k] = right[j];
			j++;
			k++;
		}
	}

	void mergeSort(vector<int>& arr, int low, int high)

	{
		if (low < high) {


			int mid = low + (high - low) / 2;

			mergeSort(arr, low, mid);
			mergeSort(arr, mid + 1, high);

			merge(arr, low, mid, high);
		}
	}


	void merge1(vector<int>& arr, int low, int mid, int high) {
		int n1 = mid - low + 1;
		int n2 = high - mid;
		vector<int> left(n1);
		vector<int> right(n2);
		for (int i = 0; i < n1; i++) {
			left[i] = arr[low + i];
		}
		for (int j = 0; j < n2; j++) {
			right[j] = arr[mid + 1 + j];
		}

		int i = 0, j = 0, k = low;
		while (i < n1 && j < n2) {
			if (weathercancels[to_string(left[i])] <= weathercancels[to_string(right[j])]) {
				arr[k] = left[i];
				i++;
			}
			else {
				arr[k] = right[j];
				j++;
			}
			k++;
		}
		while (i < n1) {
			arr[k] = left[i];
			i++;
			k++;
		}
		while (j < n2) {
			arr[k] = right[j];
			j++;
			k++;
		}
	}

	void mergeSort1(vector<int>& arr, int low, int high)

	{
		if (low < high) {


			int mid = low + (high - low) / 2;

			mergeSort1(arr, low, mid);
			mergeSort1(arr, mid + 1, high);

			merge1(arr, low, mid, high);
		}
	}



	vector<int> activeplanes;
	vector<string> solution{ "United Air Lines Inc.", "American Airlines Inc.", "US Airways Inc.", "Frontier Airlines Inc.", "JetBlue Airways", "Skywest Airlines Inc.", "Alaska Airlines Inc.", "Spirit Air Lines", "Southwest Airlines Co.", "Delta Air Lines Inc.", "Atlantic Southeast Airlines", "Hawaiian Airlines Inc.", "American Eagle Airlines Inc.", "Virgin America" };

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		static System::Collections::Generic::List<String^> bob;
		static System::Collections::Generic::List<String^> bob2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	public:
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;

	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
		  

	protected:



		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBox1;
	protected:

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
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 31;
			this->listBox1->Location = System::Drawing::Point(1313, 90);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(444, 469);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(26, 596);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(138, 36);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Delays";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(305, 596);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(154, 36);
			this->radioButton2->TabIndex = 2;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Cancels";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(589, 595);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(268, 36);
			this->radioButton3->TabIndex = 3;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Weather Cancels";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 31;
			this->listBox2->Location = System::Drawing::Point(26, 419);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(974, 128);
			this->listBox2->TabIndex = 5;
			this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox2_SelectedIndexChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(26, 90);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(974, 309);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Info;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.1F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(26, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(264, 38);
			this->textBox1->TabIndex = 7;
			this->textBox1->Text = L"SKY CRITIC";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1812, 669);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->listBox1);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->MaximumSize = System::Drawing::Size(1844, 757);
			this->MinimumSize = System::Drawing::Size(1844, 757);
			this->Name = L"MyForm";
			this->Text = L"Project Sky Critic";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		this->listBox2->Items->Clear();
		String^ str = listBox1->SelectedItem->ToString();
		//String^ str = "This is a managed string";
		char cStr[50];
		sprintf_s(cStr, "%s", str);
		std::string cpp_str(cStr);
		for (int i = 0; i < Critic::airlines[cpp_str]; i++) {
		
			String^ str2 = gcnew String(Critic::solution.at(i).c_str());
			this->listBox2->Items->Insert(0, str2);
		}
		
	}

	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->listBox1->Items->Clear();
		Critic::MyForm::bob.Clear();
		Critic::quickSort(Critic::airport, 0, Critic::airport.size()-1);
		for (int i = 0; i < 10; i++) {
			String^ str2 = gcnew String(to_string(Critic::airport.at(i)).c_str());
			Critic::MyForm::bob.Add(str2);
			this->listBox1->Items->Insert(i, bob[i]);
		}
		
	}
private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	this->listBox1->Items->Clear();
	Critic::MyForm::bob.Clear();
	Critic::mergeSort1(Critic::airport, 0, Critic::airport.size() - 1);
	for (int i = 0; i < 10; i++) {
		String^ str2 = gcnew String(to_string(Critic::airport.at(i)).c_str());
		Critic::MyForm::bob.Add(str2);
		this->listBox1->Items->Insert(i, bob[i]);
	}


}
private: System::Void listBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	String^ str = listBox2->SelectedItem->ToString();
	//String^ str = "This is a managed string";
	char cStr[50];
	sprintf_s(cStr, "%s", str);
	std::string cpp_str(cStr);
	auto it = find(solution.begin(), solution.end(), cpp_str);
	int answer = it - solution.begin()+1;
	string finals = "pictures/" + to_string(answer) + ".jpg";
	String^ str2 = gcnew String(finals.c_str());

	Image^ newImage = Image::FromFile(str2);
	pictureBox1->Image = newImage;
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	this->listBox1->Items->Clear();
	Critic::MyForm::bob.Clear();
	Critic::mergeSort(Critic::airport, 0, Critic::airport.size() - 1);
	for (int i = 0; i < 10; i++) {
		String^ str2 = gcnew String(to_string(Critic::airport.at(i)).c_str());
		Critic::MyForm::bob.Add(str2);
		this->listBox1->Items->Insert(i, bob[i]);
	}
}
};

	


}
