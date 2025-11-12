#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005],q;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9')
		{
			b[q]=a[i]-'0';
			q++;	
		}
	}
	for(int i=0;i<q;i++)
	{
		for(int j=i;j<q;j++)
		{
			if(b[i]<b[j])
			{
				swap(b[i],b[j]);
			}
		}
	}
	for(int i=0;i<q;i++)
	{
		cout<<b[i];
	}
	return 0;
}
