#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct supply //��� ���������
{
	long int number; // ����� ��������
	char product[25]; //�����
	char supplier[15]; // ���������
	char date[10]; //���� ��������
};


void reading(supply mas[], int k)
{ 
	ifstream ff("Text.txt");
	if (ff)
	{
		for (int i = 0; i < k; i++)
		{
			ff >> mas[i].number;
			ff >> mas[i].product;
			ff >> mas[i].supplier;
			ff >> mas[i].date;
		}
		ff.close();
	}
	else
	{
		cout << "Open file error";
	}
}
void prinllt(supply arr[], int m)
{
	for (int i = 0; i < m; i++) {
		cout << endl;
		cout << arr[i].number << " ";
		cout << arr[i].product << " ";
		cout << arr[i].supplier << " ";
		cout << arr[i].date;
		cout << endl;
	}
}
void sorting(supply p[], int length) 
{
	for (int j = 1; j < length; j++) {
		supply count = p[j];
		while (p[j].number < p[j - 1].number && j > 0) {
			p[j] = p[j - 1]; 
			p[j - 1] = count; 
			if (j  > 1) j--;
		}
	}
}
int Search_Binary(supply array[], int k, int left, int right) {
	int midd = 0;
	while (1)
	{
		midd = (left + right) / 2;
		if (k < array[midd].number)
			right = midd - 1;
		else if (k > array[midd].number)
			left = midd + 1;
		else
			return midd;
		if (left > right)
			return -1;
	}
}
void output_file(char file_name[30]) 
{
	supply proba;
	ofstream f;
	f.open(file_name, ios::binary);
	for (int i = 0; i < 1; i++)
	{
		cout << "������� ����� ��������: " ;
		cin >> proba.number;
		cout << "������� �������� ��������: ";
		cin >> proba.product;
		cout << "������� ��� ����������: ";
		cin >> proba.supplier;
		cout << "������� ���� ��������: ";
		cin >> proba.date;
		f << proba.number <<" " << proba.product<<" " << proba.supplier<< " " << proba.date << endl;
	}
	f.close();
}

	int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 0;
	int index = 0;
	ifstream in("Text.txt", ios::in);
	//in.open("Text.txt", ios::in);
	string line;
	while (getline(in, line))
	{
		n++;
	}
	if (n >= 50 || n <= 0)
		cout << "Mnogo objectov";
	supply *obj = new supply[n];

	reading(obj,n);
	sorting(obj, n);
	prinllt(obj, n);
	int key = 0;
	cout << endl;
	cout << "������� ����� �������� ��� ������ ";
	cin >> key;
	int min = 0, max = n - 1;
	index =	Search_Binary(obj, key, min, max);
	cout << obj[index].number << " " << obj[index].product << " " << obj[index].supplier << " " << obj[index].date << endl;
	cout << endl;
	char file_name[30];  

	cout << " ������� �������� ����� ";
	cin >> file_name;
	output_file(file_name);
	system("pause");
	
}

	
	
	
	



	/*reading();
	cout << " vot: " << n << " ";
	supply *obj1 = new supply[n];
	//FILE *myFile;
	fopen_s(&myFile, "Text.txt", "r"); //myFile = fopen(*_myFile, "Text.txt");
	
	ifstream in("Text.txt", ios::in | ios::binary);
	string line;
	//in.open("Text.txt", ios::in);
	for (int i = 0; i < n; i++)
	{
		in.getline(obj1[i].number);    //fscanf_s(myFile, "%ld %s %s %s", &obj1[i].number, &obj1[i].product, &obj1[i].supplier, &obj1[i].date);

	}
	for (int i = 0; i < n; i++)
	{
		cout << obj1[i].number << ", ";
		cout << obj1[i].product << ", ";
		cout << obj1[i].supplier << ", ";
		cout << obj1[i].date << endl;

	}
	system("pause");
	return 0;
	*/


/*
using namespace std; // ��� �� �����

int main()
{

	const int len = 30, strings = 5;
	const char ch = '\n';
	char mass[len][strings];
	int sum[10];

	ifstream fs("Text.txt", ios::in | ios::binary);

	if (!fs) return 1; //���� ������ �������� �����, �� ��������� ���������

	for (int r = 0; r<strings; r++)
	{
		fs.getline(sum[r], sum[r]); //��������� ������ � ������
		std::cout << "String " << r + 1 << " = " << mass[r] << endl; //������ ������ �� �������
	}
	fs.close(); //��������� ����
	system("pause");
	return 0;
}
*/

/*#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
struct School
{
	int mark;
	char subject[6];
	char surname[9];
	int age;
};



void readAllSchoolObj(vector <School> vSchool)
{
	School school;
	ifstream fin("Text.txt");
	while (!fin.eof)
	{
		fin.read((char*)&school, sizeof(School));
		vSchool.push_back(school);
	}
}

int main()
{

	setlocale(LC_ALL, "Rus");
	vector <School> obj;
	readAllSchoolObj(obj);
	system("pause");
	return 0; 

}*/