/*防伪标识：十年OI一场空，不开long long见祖宗*/
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=5e6+10;
int n,q,lens[N];
long long ht[2],hs[2][N],b[M],base=131;
string s[2][N],t[2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=1;j++)
		{
			cin>>s[j][i];
			lens[i]=s[j][i].size();
			for(int k=0;k<lens[i];k++)
			{
				hs[j][i]=hs[j][i]*base+s[j][i][k];
			}
			//cout<<"***"<<hs[j][i]<<" ";
		}
		//cout<<"\n";
	}
	b[0]=1;
	for(int i=1;i<M;i++) b[i]=b[i-1]*base;
	while(q--)
	{
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size())
		{
			cout<<"0\n";
			continue;
		}
		int lent=t[0].size();
		ht[0]=ht[1]=0;
		for(int j=0;j<=1;j++)
		{
			for(int i=0;i<lent;i++)
			{
				ht[j]=ht[j]*base+t[j][i];
			}
		}
		//cout<<"////"<<ht[0]<<" "<<ht[1]<<"\n";
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int l=0;l+lens[i]<lent;l++)
			{
				//cout<<"----"<<b[lent-l-lens[i]]*hs[1][i]<<" "<<b[lent-l-lens[i]]*hs[0][i]<<"\n";
				if(ht[0]+b[lent-l-lens[i]]*hs[1][i]==ht[1]+b[lent-l-lens[i]]*hs[0][i])//
				{
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/
