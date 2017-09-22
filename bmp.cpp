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
}
