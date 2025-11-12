#include<bits/stdc++.h>
using namespace std;
string a;
long long b[1000005],k;
int main()
{
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[k]=a[i]-'0';
			//cout<<b[k];
			k++;
		}
	}
	sort(b,b+k+1);
	for(int i=k;i>=1;i--)
	{
	cout<<b[i];
	}
	return 0;
	//cout<<a.size();
} 
//do gei dian fen ba!!!
