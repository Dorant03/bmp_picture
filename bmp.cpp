#include<iostream>
#include <windows.h>;
#include <string>
 using namespace std;

int main()
{   
        // ��������� �����
        BITMAPFILEHEADER header;
        BITMAPINFOHEADER bmiHeader;
		//��� ��� �����
        RGBTRIPLE rgb; 
		//����� ��� ������� � ������
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

			fread(&header,sizeof(header),1,file1);                     //�������� ���������(BITMAPFILEHEADER)
            fwrite(&header, sizeof(header), 1, file2);  
            fread(&bmiHeader,sizeof(bmiHeader),1,file1);               //��������� ����������(BITMAPINFOHEADER)
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