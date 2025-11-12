#include<bits/stdc++.h>
using namespace std;
const long long N=4e3+5,M=1e7+50,L=5e6,D=2e5+5;
long long n,q,ans,mx,nw;
string s1[N],s2[N],s,o,l;
string l1,l2;
long long f[M];
struct node{
	long long x;
};
vector<node> vec[D];
inline void solve(){
	cin>>n>>q;
//	if(n<=100&&q<=20){
	for(int i=1;i<=n;i++){
		cin>>s1[i];
		cin>>s2[i];
	}
		for(int i=1;i<=q;i++){
		cin>>s>>l;
		ans=0;
		for(int j=1;j<=n;j++){
			long long p=s.find(s1[j]);
			if(p==-1) continue;
			o=s;
			for(int k=p;k<p+s1[j].size();k++){
				o[k]=s2[j][k-p];
			}
			if(o==l) ans++;
		}
		cout<<ans<<'\n';
	}
	return ;
//	}
/*	for(int i=1;i<=n;i++){
		cin>>l1>>l2;
		long long u=l1.find('b')-l2.find('b')+L;
		if(!f[u]) f[u]=++nw;
		vec[f[u]].push_back()
	}*/
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}

