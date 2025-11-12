#include<bits/stdc++.h>
using namespace std;
int main()

{
	
	freopen("number.in","r",stdin);
	freopen("nmuber.out","w",stdout);
	string n;
		cin>>n;
	int a[n.size()];
	int p=0;

	for(int i=0;i<n.size();i++)
	{
		if(int(n[i])>=48&&int(n[i])<=58)
		{
			a[p]=int(n[i])-48;
			
			p++;
		}
	}
	for(int i=0;i<p;i++)
	{
		int max=-1;
		int t=0;
		for(int j=0;j<p;j++)
		{
			
			if(a[j]>max)
			{max=a[j]; 
				t=j;
			}
		 } 
		cout<<max;
		a[t]=-1;
	 } 

	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
