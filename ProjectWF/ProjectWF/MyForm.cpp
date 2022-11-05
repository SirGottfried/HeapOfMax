#include "MyForm.h"
#include "Foo.h"
#include <string>
#include <iostream>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ProjectWF::MyForm form;
	Application::Run(% form);
}

System::Void ProjectWF::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ name;
	name = textBox1->Text;
	std::string nam = msclr::interop::marshal_as<std::string>(name);
	for (int i = 0; i < HeapSize; i++)
	{
		if (h[i] == nam)
		{
			for (int j = i; j < HeapSize; j++)
			{
				swap(h1[j], h1[j + 1]);
				swap(h[j], h[j + 1]);
			}
			heapify(HeapSize, h, h1, 0);
			HeapSize--;
			HeapSize1--;
		}
	}
	label7->Text = name + " Removed";
	label9->Text = "";
}

System::Void ProjectWF::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ name;
	std::string x;
	name = textBox2->Text;
	std::string nam = msclr::interop::marshal_as<std::string>(name);
	for (int i = 0; i < HeapSize; i++)
	{
		if (h[i] == nam)
		{
			x = h1[i];
		}
	}
	String^ VAL = gcnew String(x.c_str());
	String^ NAME = gcnew String(nam.c_str());
	label9->Text = "Name: " + NAME + " Value: " + VAL;
}

System::Void ProjectWF::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string names[] = { "A", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "B11", "B12", "B13", "B15", "C", "D", "E", "K", "N" };
	std::string mg[] = { "0.009", "1.5", "1.8", "20", "425", "5", "2", "50", "500", "400", "200", "300", "0.000003", "0.5", "50", "90", "0.000001", "15", "0.0012", "30" };
	HeapSize = 0;
	HeapSize1 = 0;
	for (int i = 0; i < 20; i++)
	{
		label7->Text = "";
		label9->Text = "";
		int j, parent;
		j = HeapSize;
		h[j] = names[i];
		h1[j] = mg[i];
		parent = (j - 1) / 2;
		while (parent >= 0 && j > 0) {
			if (stod(h1[j]) > stod(h1[parent])) {
				std::string temp = h[j];
				std::string temp1 = h1[j];
				h[j] = h[parent];
				h[parent] = temp;
				h1[j] = h1[parent];
				h1[parent] = temp1;
			}
			j = parent;
			parent = (j - 1) / 2;
		}
		HeapSize++;
		HeapSize1++;
	}
}

System::Void ProjectWF::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ value;
	String^ name;
	value = textBox5->Text;
	name = textBox4->Text;
	std::string val = msclr::interop::marshal_as<std::string>(value);
	std::string nam = msclr::interop::marshal_as<std::string>(name);
	int i, parent;
	i = HeapSize;
	h[i] = nam;
	h1[i] = val;
	parent = (i - 1) / 2;
	while (parent >= 0 && i > 0) {
		if (stod(h1[i]) > stod(h1[parent])) {
			std::string temp = h1[i];
			std::string temp1 = h[i];
			h1[i] = h1[parent];
			h1[parent] = temp;
			h[i] = h[parent];
			h[parent] = temp1;
		}
		i = parent;
		parent = (i - 1) / 2;
	}
	HeapSize++;
	HeapSize1++;
}

System::Void ProjectWF::MyForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string sString("");
	std::string sString1("");
	int i = 0;
	int k = 1;
	while (i < HeapSize) {
		while ((i < k) && (i < HeapSize)) {
			sString += h[i] + " ";
			i++;
		}
		sString += "\n";
		k = k * 2 + 1;
	}
	i = 0;
	k = 1;
	while (i < HeapSize) {
		while ((i < k) && (i < HeapSize)) {
			sString1 += h1[i] + " ";
			i++;
		}
		sString1 += "\n";
		k = k * 2 + 1;
	}
	String^ something = gcnew String(sString.c_str());
	label7->Text = something;
	String^ something1 = gcnew String(sString1.c_str());
	label9->Text = something1;
}
