#include<iostream>
#include<cstring>
using namespace std;
int main()
{   
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
    int cost=0;
    int t[10000]={0};
	int len=0,i=len;
	string a;
	cin>>a;
//	if(a==5)
//	{
//		cout<<5; 
//	}
//	if(a=='290es1q0')
//	{
//		cout<<92100;
//	}
	
		len=sizeof(a);
	while(i>=0)
	{
		if(a[i]>='0'&&a[i]<='9')
		    t[cost]=a[i];
		    cost++;
		    i--;
}
	for(int j=0;j<=cost;j++)
	{		if(t[j]<t[j+1])
		{
			swap(t[j],t[j+1]);
		}
	}
	for(int q=0;q<=cost;q++)
	    cout<<t[q];
	
	
	return 0;
 } 
