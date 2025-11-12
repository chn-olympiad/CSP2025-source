#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2;
int n,q,bi[200005],bj[200005],bk[200005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;int b1=0,b2=0,m=s1.size();
		for(int i=0;i<m;i++)if(s1[i]=='b'){b1=i;break;}
		for(int i=0;i<m;i++)if(s2[i]=='b'){b2=i;break;}
		bi[i]=b1,bj[i]=b2-b1,bk[i]=m-b1;
	}
	while(q--){
		cin>>s1>>s2;int b1=0,b2=0,ans=0,m=s1.size();
		for(int i=0;i<m;i++)if(s1[i]=='b'){b1=i;break;}
		for(int i=0;i<m;i++)if(s2[i]=='b'){b2=i;break;}
		for(int i=1;i<=n;i++){
			if(bi[i]<=b1&&b2-b1==bj[i]&&b1+bk[i]<=m)ans++;	
		}
		cout<<ans<<'\n';
	}
	return 0;
}