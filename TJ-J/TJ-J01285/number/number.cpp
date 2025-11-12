#include<bits/stdc++.h>
using namespace std;
void qq(string a)
{
	while(1)
	{
		int qqq=0;
		for(int i=0;i<a.size()-1;i++)
		{
			if(a[i+1]<a[i])
			{
				int temp;
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				qqq=1;
			 } 
		}
		if(qqq==0)
		{
			for(int i=a.size();i>=0;i--)
			{
				if(a[i]<='0')
				{
					continue;
				}
				cout<<a[i];
			}
			break;
			
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&'9'<=a[i])
		{
			a[i]='\0';
		}
	}
	qq(a);
	//cout<<a;
	return 0;
 } 
