#include<iostream>
#include <windows.h>;
#include <string>
 using namespace std;

int main()
{   
        // Ñòðóêòóðè ôàéëà
        BITMAPFILEHEADER header;
        BITMAPINFOHEADER bmiHeader;
		//äàí³ ïðî ï³êñåë³
        RGBTRIPLE rgb; 
		//ôàéëè äëÿ ÷èòàííÿ ³ çàïèñó
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

			fread(&header,sizeof(header),1,file1);                     //ôàéëîâèé çàãîëîâîê(BITMAPFILEHEADER)
            fwrite(&header, sizeof(header), 1, file2);  
            fread(&bmiHeader,sizeof(bmiHeader),1,file1);               //çàãîëîâîê çîáðàæåííÿ(BITMAPINFOHEADER)
            fwrite(&bmiHeader, sizeof(bmiHeader), 1, file2);  

		    string messages;
		    cout<<"Enter messages:"<<endl;
			cin.get();
		    getline(cin,messages);

		    int len=messages.size(); int size=len;
		    int k=8;
		    int number_ascii=(int)(messages[len-size]);
			for(int i=0;i< bmiHeader.biWidth;i++)     //bmiHeader.biWidth
            {
                for (int j = 0; j < bmiHeader.biHeight; j++)   //bmiHeader.biHeight
                {
					fread(&rgb, sizeof(rgb),1, file1);
					if(size)
						{
							if(k>=0)
							{
								if(number_ascii>=pow(2,k))
		                        {
		                         	number_ascii-=pow(2,k);
			                        rgb.rgbtBlue=rgb.rgbtBlue+rgb.rgbtBlue%2-1;
		                        }
		                        else
		                        {
		                         	rgb.rgbtBlue=rgb.rgbtBlue+rgb.rgbtBlue%2;
		                        } 
								k--;
							}
						}
						if(k<0)
					    {
							k=8; size--;
							number_ascii=(int)(messages[len-size]);
						}
					    fwrite(&rgb, sizeof(rgb), 1, file2);
				}
			}
                fcloseall();
		cout<<"Encoded!!!"<<endl;
			
                }
                if(choice==2)
		{
			file2 = fopen("file1.bmp", "r+b");
			fread(&header,sizeof(header),1,file2);             
			fread(&bmiHeader,sizeof(bmiHeader),1,file2);   
			char messages2[1000]; int size=0; 
			int binary_number=0;
	        int k=9;
			for (int i = 0; i < bmiHeader.biWidth ; i++) 
			{   
				for (int j = 0; j < bmiHeader.biHeight; j++)
				{ 
					fread(&rgb, sizeof(rgb),1, file2);
					if(!k)
					{
						int number_ascii=0; int power=0; 
						while(binary_number)
						{
							number_ascii+=binary_number%10*pow(2,power); power++;
							binary_number/=10;
						}
						k=9;
						messages2[size]=(char)(number_ascii); size++;
					}
					binary_number=binary_number*10+rgb.rgbtBlue%2;
					k--;
					if(messages2[size-1]=='!') break;
				}   
				if(messages2[size-1]=='!') break;
			}      
			cout<<endl<<"Messages: "<<endl;
			for(int i=0; i<size; i++)
			{
				cout<<messages2[i];
			}
                        fcloseall();
			cout<<endl<<"Decoded!!!"<<endl;
		}
                 }
}
