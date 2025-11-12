#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,base=13331,mod=1e9+7;
int n,q,Hsh1[N],Hsh2[N],L[N],p[N];
char a[N],b[N];
vector<int> hsh1[N],hsh2[N];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	p[0]=1;
	for(int i=1;i<N;i++) p[i]=p[i-1]*base%mod;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		int len=strlen(a);
		hsh1[i].resize(len+1);
		hsh2[i].resize(len+1);
		for(int j=0;j<len;j++)
		{
			hsh1[i][j+1]=((hsh1[i][j]*base%mod)+(a[j]-'a'))%mod;
			hsh2[i][j+1]=((hsh2[i][j]*base%mod)+(b[j]-'a'))%mod;			
		}
		L[i]=len;
	}
	while(q--)
	{
		int res=0;
		string t1,t2;cin>>t1>>t2;
		if(t1==t2) res++;
		int len=t1.size();
		for(int i=0;i<len;i++) 
		{
			Hsh1[i+1]=((Hsh1[i]*base%mod)+t1[i]-'a')%mod;
			Hsh2[i+1]=((Hsh2[i]*base%mod)+t2[i]-'a')%mod;				
		}
		for(int l=1;l<=len;l++)
		{
			for(int j=1;j<=n;j++)
			{
				int r=l+L[j]-1;
				if(r>len) continue;
				int x=Hsh1[l-1],xx=Hsh2[l-1];
				int y=(Hsh1[r]-Hsh1[l-1]*p[r-l+1]%mod+mod)%mod;
				int yy=(Hsh2[r]-Hsh2[l-1]*p[r-l+1]%mod+mod)%mod;
				int z=(Hsh1[len]-Hsh1[r]*p[len-r]%mod+mod)%mod;
				int zz=(Hsh2[len]-Hsh2[r]*p[len-r]%mod+mod)%mod;
				if(x==xx&&z==zz&&y==hsh1[j][L[j]]&&yy==hsh2[j][L[j]]) res++;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
//4 2
//xabcx xadex
//ab cd
//bc de
//aa bb
//xabcx xadex
//aaaa bbbb


//2 1
//xabcx xadex
//bc de
//xabcx xadex
