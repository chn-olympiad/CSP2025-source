#include <fstream>
using namespace std;
ifstream cin("number1.in");
ofstream cout("number.out");
int a[1000001],t=1,b=0,e=1;
int main()
{
	char x[1000001];
	cin>>x;
	for(int i=1;i<=1000001;i++){
		switch(x[i])
		{
			case '0':a[t]=0;t++;b++;break;
			case '1':a[t]=1;t++;b++;break;
			case '2':a[t]=2;t++;b++;break;
			case '3':a[t]=3;t++;b++;break;
			case '4':a[t]=4;t++;b++;break;
			case '5':a[t]=5;t++;b++;break;
			case '6':a[t]=6;t++;b++;break;
			case '7':a[t]=7;t++;b++;break;
			case '8':a[t]=8;t++;b++;break;
			case '9':a[t]=9;t++;b++;break;
			defult :e++;break;
		}
	}
	for(int i=1;i<=b;i++)
		for(int k=i+1;k<=b;k++)
			for(int l=b-i;l<=b;l++)
				if(a[i]<a[k])
					swap(a[i],a[k]);
	for(int i=1;i<=b;i++)
		cout<<a[i];
}
