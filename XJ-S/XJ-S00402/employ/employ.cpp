#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string a;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,q,p;
	long long int cnt=0;
	cin>>n>>q>>a;
	for(int i=1;i<=q;i++)
	{
		cin>>p;
		if(i==1)	cnt=p;
		else if(p!=0)	cnt*=p;
		cnt%=998244353;	
	}
	cout<<cnt;
	return 0;
}
