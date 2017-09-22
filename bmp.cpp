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

                while(choice)
		{
		cout<<"Your choice: "; cin>>choice;
		if(choice==1)
		{
			file1 = fopen("file.bmp", "r+b");
            file2 = fopen("file1.bmp", "w+b");

			fread(&header,sizeof(header),1,file1);                     //файловий заголовок(BITMAPFILEHEADER)
            fwrite(&header, sizeof(header), 1, file2);  
            fread(&bmiHeader,sizeof(bmiHeader),1,file1);               //заголовок зображення(BITMAPINFOHEADER)
            fwrite(&bmiHeader, sizeof(bmiHeader), 1, file2);  

		    string messages;
		    cout<<"Enter messages:"<<endl;
			cin.get();
		    getline(cin,messages);

		    int len=messages.size(); int size=len;
		    int k=8;
		    int number_ascii=(int)(messages[len-size]);
                }
                }
}