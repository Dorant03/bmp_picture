#include<iostream>
#include <windows.h>;
#include <string>
 using namespace std;

int main()
{   
        // Структури файла
        BITMAPFILEHEADER header;
        BITMAPINFOHEADER bmiHeader;
		//дані про пікселі
        RGBTRIPLE rgb; 
		//файли для читання і запису
        FILE * file1, * file2;
 
		cout<<"Menu:"<<endl;
		cout<<"1.Encode messages"<<endl;
		cout<<"2.Decode messages"<<endl;
        
		int choice=1;
}
