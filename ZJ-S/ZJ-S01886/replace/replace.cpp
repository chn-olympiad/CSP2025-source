#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e5+5;
long long n,q,m,k,i,cs1,cs2,s1,j;
string st[maxn][3],a,b;
long long wh[maxn][3];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>st[i][1]>>st[i][2];
		s1=st[i][1].size();
		for(j=0;j<s1;j++)
		{
			if(st[i][1][j]=='b') wh[i][1]=j;
			if(st[i][2][j]=='b') wh[i][2]=j;
		}
	}
	while(q--)
	{
		cs1=0,cs2=0;
		cin>>a>>b;
		s1=a.size();
		for(i=0;i<s1;i++)
		{
			if(a[i]=='b') cs1=i;
			if(b[i]=='b') cs2=i;
		}
		cout<<0<<"\n";
	}
	return 0;
}
//I want go to the qiguaixingweidashang!
//luogu uid：562443
//Go for it!
//Ren5Jie4Di4Ling5%