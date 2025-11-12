#include<iostream>
#include<iomanip>
#include<cstring> 
using namespace std;

int main()
{ 

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	 char a[100005]={0};
 int n,sl,b[15]={0}; 
	cin>>a;
    sl=strlen(a);
    for(int i=0;i<sl;i++)
    {
    	n=a[i];
    	if(n>=48&&n<=57)
    	{
    		b[n-48]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=b[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
