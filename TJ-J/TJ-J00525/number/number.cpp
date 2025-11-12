#include<bits/stdc++.h>
using namespace std;
string na;
long long a[10000000],b;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>na;
	for(int i=0;i<na.size();i++)
	{
		if(na[i]>='0'&&na[i]<='9') 
		{
			a[b]=na[i]-'0';
			b++;
		}
	}
	sort(a,a+b);
	for(int i=b-1;i>=0;i--) 
	{
		cout<<a[i];
	}
	
	return 0;
}	
	

