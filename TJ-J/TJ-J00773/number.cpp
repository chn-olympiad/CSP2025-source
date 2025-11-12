#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int a=0;
int f;



void number(int d)
{
	int c[a];
	for(int i=d;i<a;i++)
	{
		bool d=true;
		for(int j=1;j<a;j++)
		{
			if(c[i]>=c[j])
			{
				continue;
			}
			else
			{
				d=false;
				number(j);
			}
		}
		int e[a];
		
		if(d)
		{
			e[f]=c[i];
			f++;
		}
	}
	ofstream file("number.ans");
	if(!file.is_open())
	{
		
		cout<<"无法打开文件"; 
	}
	for(int i=0;i<f;i++)
	{
		file<<e[f];
	}
	
}
int main(int argc, char** argv) {
	ifstream file("number.in");
	if(!file.is_open())
	{
		cout<<"无法打开文件"; 
		
	}
	string line;
	int a;
	while(getline(file,line))
	{
		cout<<line;
		char b=line[a];
		a++;
	}
	int c[a];
	int a=0;
	while(getline(file,line))
	{
		
		char b=line[a];
		if(b>=0&&<10)
		{
			c[a]=b;
			a++;
		}
		
	}
	int d=0;
	number(d);
	file.close();
	return 0;
}
