#include "pch.h"
#include <vector>
#include <string>
#include <string>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <dos.h>
#include <fstream>
#include <iterator>
using namespace std;


void printArray(vector<int> &d);

void swap(int* a, int* b);

int partition(vector<int> &vector, int start, int end);
void quickSort(vector<int> &A, int start, int end);
void insertionSort(vector<int> &vector, int num);
void shellSort(vector<int> &vector, int num);
void getCorrectFile(ifstream& inFS, string& myFile);
string getFileName();
ifstream openFile(string& file);


int main() {
	vector<int> *listA1 = new vector<int>;
	vector<int> *listA2 = new vector<int>;
	vector<int> *listA3 = new vector<int>;
	vector<int> *listB1 = new vector<int>;
	vector<int> *listB2 = new vector<int>;
	vector<int> *listB3 = new vector<int>;
	vector<int> *listC1 = new vector<int>;
	vector<int> *listC2 = new vector<int>;
	vector<int> *listC3 = new vector<int>;

	ifstream ifs;
	
	string filename;
	int size1 = 0, size2 = 0, size3 = 0, num = 0;

	for (int i = 1; i <= 3; i++)
	{
		if (i == 1)
		{
			cout << "\nEnter first file name: " << endl;
			filename = getFileName(); // Get user input for file name >
			ifs = openFile(filename); // Open file > Get correct file if file invalid, while loop will repeatedly call until valid name is entered by user
			while (ifs >> num)
			{
				size1++;
				//cout << "\nnum is: " << num << endl;
				listA1->push_back(num);
				listA2->push_back(num);
				listA3->push_back(num);
			}
			num = 0;
		}
		else if (i == 2)
		{
			cout << "\nEnter second file name: " << endl;
			filename = getFileName(); // Get user input for file name >
			ifs = openFile(filename); // Open file > Get correct file if file invalid, while loop will repeatedly call until valid name is entered by user
			while (ifs >> num)
			{
				size2++;
				//cout << "\nnum is: " << num << endl;     a ;sdlfjk
				listB1->push_back(num);
				listB2->push_back(num);
				listB3->push_back(num);
			}
			num = 0;
		}
		else if (i == 3)
		{
			cout << "\nEnter third file name: " << endl;
			filename = getFileName(); // Get user input for file name >
			ifs = openFile(filename); // Open file > Get correct file if file invalid, while loop will repeatedly call until valid name is entered by user
			while (ifs >> num)
			{
				size3++;
				//cout << "\nnum is: " << num << endl;
				listC1->push_back(num);
				listC2->push_back(num);
				listC3->push_back(num);
			}

		}

	}
	ifs.close();
	cout << "\n                     NUMBER      ELAPSED        ELAPSED      "; 
	cout << "\nSORT      FILE#      ITEMS        CLOCK          TIME        ";
	cout << "\n-------------------------------------------------------------";

	clock_t start = clock();
	insertionSort(*listA1, listA1->size());
	clock_t end = clock();
	clock_t total = end - start;
	double seconds = (double)total / (double)CLOCKS_PER_SEC;
	cout << "\nInsertion   1          " << size1 << "            " << total << "            " << seconds;
	start = clock();
	quickSort(*listA2, 0, listA2->size() - 1);
	end = clock();
	total = end - start;
	seconds = (double)total / (double)CLOCKS_PER_SEC;
	cout << "\nQuickSort   1          " << size1 << "            " << total << "            " << seconds;
	start = clock();
	shellSort(*listA3, listA3->size());
	end = clock();
	total = end - start;
	seconds = (double)total / (double)CLOCKS_PER_SEC;
	cout << "\nShellsort   1          " << size1 << "            " << total << "            " << seconds;


	start = clock();
	insertionSort(*listB1, listB1->size());
	end = clock();
	total = end - start;
	seconds = (double)total / (double)CLOCKS_PER_SEC;
	cout << "\nInsertion   2          " << size2 << "            " << total << "            " << seconds;
	start = clock();
	quickSort(*listB2, 0, listB2->size() - 1);
	end = clock();
	total = end - start;
	seconds = (double)total / (double)CLOCKS_PER_SEC;
	cout << "\nQuickSort   2          " << size2 << "            " << total << "            " << seconds;
	start = clock();
	shellSort(*listB3, listB3->size());
	end = clock();
	total = end - start;
	seconds = (double)total / (double)CLOCKS_PER_SEC;
	cout << "\nShellsort   2         " << size2 << "            " << total << "            " << seconds;
	/*
	SHELL SORT2
	NEEDS
	TO GO
	HERE*/
	start = clock();
	insertionSort(*listC1, listC1->size());
	end = clock();
	total = end - start;
	seconds = (double)total / (double)CLOCKS_PER_SEC;
	cout << "\nInsertion   3          " << size3 << "            " << total << "            " << seconds;
	start = clock();
	quickSort(*listC2, 0, listC2->size() - 1);
	end = clock();
	total = end - start;
	seconds = (double)total / (double)CLOCKS_PER_SEC;
	cout << "\nQuickSort   3          " << size3 << "            " << total << "            " << seconds;
	start = clock();
	shellSort(*listC3, listC3->size());
	end = clock();
	total = end - start;
	seconds = (double)total / (double)CLOCKS_PER_SEC;
	cout << "\nShellsort   3          " << size3 << "            " << total << "            " << seconds;

	ofstream I1("I1.txt");
	ofstream Q1("Q1.txt");
	ofstream S1("S1.txt");
	ofstream I2("I2.txt");
	ofstream Q2("Q2.txt");
	ofstream S2("S2.txt");
	ofstream I3("I3.txt");
	ofstream Q3("Q3.txt");
	ofstream S3("S3.txt");

	for (const auto &e : *listA1) I1 << e << "\n";
	for (const auto &e : *listA2) Q1 << e << "\n";
	for (const auto &e : *listA3) S1 << e << "\n";
	for (const auto &e : *listB1) I2 << e << "\n";
	for (const auto &e : *listB2) Q2 << e << "\n";
	for (const auto &e : *listB3) S2 << e << "\n";
	for (const auto &e : *listC1) I3 << e << "\n";
	for (const auto &e : *listC2) Q3 << e << "\n";
	for (const auto &e : *listC3) S3 << e << "\n";
	

	I1.close();
	Q1.close();
	S1.close();
	I2.close();
	Q2.close();
	S2.close();
	I3.close();
	Q3.close();
	S3.close();

	cout << endl << "\n    EXPORTED FILE NAMES" << "\n----------------------------";
	cout << "\nFile1 Insertion -- I1";
	cout << "\nFile1 QuickSort -- Q1";
	cout << "\nFile1 ShellSort -- S1";
	cout << "\nFile2 Insertion -- I2";
	cout << "\nFile2 QuickSort -- Q2";
	cout << "\nFile2 ShellSort -- S2";
	cout << "\nFile3 Insertion -- I3";
	cout << "\nFile3 QuickSort -- Q3";
	cout << "\nFile3 ShellSort -- S3";

	string a;
	cout << endl << endl << endl << "Type any letter followed by pressing 'Enter' to exit" << endl;
	cin >> a;
}

void printArray(vector<int> &d)
{
	int i;
	for (i = 0; i < d.size(); i++)
		printf("%d ", d.at(i));
	printf("\ndone");
}
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(vector<int> &vector, int a, int z) {
	int i = a + 1;
	int pivot = vector[a];           
	for (int j = a + 1; j <= z; j++) {

		if (vector[j] < pivot) {
			//swap(vector[j], vector[z]
			swap(vector[i], vector[j]);
			i = i + 1;
		}
	}
	//swap(vector[z], vector[a];
	swap(vector[a], vector[i - 1]); 
	return i - 1;                      
}
void quickSort(vector<int> &vector, int a, int z) {
	if (a < z) {
		
		int key = partition(vector, a, z);
		quickSort(vector, a, key - 1);
		quickSort(vector, key + 1, z);
	}
}
void insertionSort(vector<int> &vector , int num)
{
	for (int i = 0; i < num; i++) {
		int a = i;
		int tempNum = vector[i];
		while ((a > 0) && (tempNum < vector[a - 1])) {

			vector[a] = vector[a - 1];
			a = a - 1;
		}
		vector[a] = tempNum;
	}
}

void shellSort(vector<int> &vector, int num)
{
	//Method with the KN method didn't  work
	//Unable to figure out interval.....
	//Method from Powerpoint didn't work, instructions not clear
	int a;
	for (int sub = num / 2; sub > 0; sub /= 2) {
		for (int i = sub; i < num; i += 1) {
			int tempNum = vector[i];
			for (a = i; a >= sub && vector[a - sub] > tempNum; a -= sub)
				vector[a] = vector[a - sub];
			vector[a] = tempNum;
		}
	}
}
void getCorrectFile(ifstream& inFS, string& myFile)
{   //Function serves to give user ability to re-enter file name after invalid entry
	cout << endl << "File '" << myFile << "' not found." << endl;
	myFile = getFileName();
	inFS.open(myFile);

}
string getFileName()
{   //Function asks user for file name
	string tempFileName;
	cin >> tempFileName;
	return tempFileName;
}
ifstream openFile(string& file)
{   //Opens file, checks name repeatedly until valid
	ifstream inFS;
	inFS.open(file);
	while (!inFS.is_open())
		getCorrectFile(inFS, file);

	return inFS;
}


/*
std::ostream_iterator<std::string> output_iterator0(I1, "\n");
std::copy(listA1->begin(), listA1->end(), output_iterator0);

std::ostream_iterator<std::string> output_iterator1(Q1, "\n");
std::copy(listA2->begin(), listA2->end(), output_iterator1);

std::ostream_iterator<std::string> output_iterator2(S1, "\n");
std::copy(listA3->begin(), listA3->end(), output_iterator2);

std::ostream_iterator<std::string> output_iterator3(I2, "\n");
std::copy(listB1->begin(), listB1->end(), output_iterator3);

std::ostream_iterator<std::string> output_iterator4(Q2, "\n");
std::copy(listB2->begin(), listB2->end(), output_iterator4);

std::ostream_iterator<std::string> output_iterator5(S2, "\n");
std::copy(listB3->begin(), listB3->end(), output_iterator5);

std::ostream_iterator<std::string> output_iterator6(I3, "\n");
std::copy(listC1->begin(), listC1->end(), output_iterator6);

std::ostream_iterator<std::string> output_iterator7(Q3, "\n");
std::copy(listC2->begin(), listC2->end(), output_iterator7);

std::ostream_iterator<std::string> output_iterator8(S3, "\n");
std::copy(listC3->begin(), listC3->end(), output_iterator8);
*/