#include <bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int m,q=0;;
	m=n.size();
	int a[m+1];
	for(int i=0;i<m;i++)
	{
		int p=n[i];
		if((p<58)&&(p>47))
		{
			a[q]=p-48;
			q++;
		}
	}
	q--;
	for(int i=1;i<=q;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]<a[j])
			{	
				int b;
				b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
	}
	if(a[q]==0)
		cout<<0;
	for(int i=q;i>=0;i--)
		cout<<a[i];
	return 0;
}
