#include<bits/stdc++.h>
using namespace std;
long long int i,k=0,b[1000000];
string a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		b[++k]=a[i]-'0';
		
	}
	sort(b+1,b+1+k,greater<long long int>());
	for(i=1;i<=k;i++)
	{
		cout<<b[i];
	}
	
	return 0;
}
