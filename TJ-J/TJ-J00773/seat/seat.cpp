#include <iostream>
#include <string>
#include <fstream> 
using namespace std;
int d;

void number(int d)
{
	int m,n;
	int c[m*n];
	for(int i=d;i<m*n;i++)
	{
		bool d=true;
		for(int j=1;j<m*n;j++)
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
		int e[m*n];
		int f;
		if(d)
		{
			e[f]=c[i];
			f++;
		}
	}
}
int b[m][n];
struct node
{
	int x;
}
node* n1=new node;
n1->x=1;
node* n2=new node;
n2->x=-1;
void seat(int m,int n)
{
	int g;
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
	    {
	    	if(i%2==1)
	    	{
	    		b[m][n]=e[f];
			}
		}
		
	}
} 
int main(int argc, char** argv) {
	ifstream file("seat1.in");
	if(!file.is_open())
	{
		cout<<"无法打开文件"; 
	}
	string line;
	while(getline(file,line))
	{
		cout<<line;
	}
	int m,n;
	cin>>m>>n;
	int c[m*n];
	for(int i=0;i<m*n;i++)
	{
		cin>>c[i];
	}
	number(d);
	seat(m,n);
	int b[m][n];
	
	return 0;
}
