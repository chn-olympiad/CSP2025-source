// 王嘉豪 SN-S00467 西安高新第一中学 


#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n,q;
	string a[n+1][2];
	for(int i=0;i<=n;i++)
	{
		for(int j=1;j<=2;j++)
		{
			cin>>a[i][j];	
		}
	}
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=2;j++)
		{
			cin>>a[i][j];	
		}
	}
	return 0;
}
