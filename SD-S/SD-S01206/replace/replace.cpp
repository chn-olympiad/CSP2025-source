#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e3+10;
const int mod=1313131;
int n,q;
const int P=13; 
string s[N],s2[N];
int len[N];
int p[N];
int hash[N][N]
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>q;
	int maxx=-1;
	for(int i=1;i<=n;i++){;
		cin>>s[i]>>s2[i];
		len[i]=s[i].size();
		maxx=max(len[i],maxx);
	//	cout<<len[i]<<endl;
	}
	p[0]=1;
	for(int i=1;i<=maxx;i++){
		p[i]=p[i-1]*P%mod;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=len[i];j++)
		{
			hash[i][j]=hash[i][j-1]*p[j-1]+(s[i][j-1]-'a'+1);
		}
	}
	while(q--){
		
	}
	return 0;
}

