#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}
const int N=2050;
string a[N],b[N];
ll n,q;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	if(n<=1000){
		for(ll i=1;i<=n;i++){
			cin>>a[i]>>b[i];
		}
		while(q--){
			string p,q;cin>>p>>q;
			ll siz=p.size(),siz2=q.size();
			if(siz!=siz2) cout<<0<<'\n';
			else{
				int ans=0;
				for(int i=1;i<=n;i++){
					if(p.find(a[i])!=string::npos){
						int k=p.find(a[i]);
						int siz=a[i].size();
						string pk=p;
						for(int j=k;j<=k+siz-1;j++){
							pk[j]=b[i][j-k];
						}
						if(pk==q) ans++;
					}
				}
				cout<<ans<<'\n';
			}
		}
		return 0;
	}
	while(q--){
		cout<<0<<'\n';
	}
	return 0;
}