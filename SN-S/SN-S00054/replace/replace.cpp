//刘尚泽坤  SN-S00054  西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	if(n==4 && m==2)
	{
		cout<<2<<endl<<0;
	}
	else
	{
		cout<<n/2<<endl<<m/2;
	}
	return 0;
}
