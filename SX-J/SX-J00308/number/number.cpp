#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a;
unsigned ll tong[100],t;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]<='9'&&a[i]>='0')
		{
			tong[a[i]-'0']++;
//			t++;
		}
	}
//	for(int i=9;i>=0;i--){
//	cout<<tong[i]<<" ";
//	}
//cout<<t<<endl;
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=tong[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}