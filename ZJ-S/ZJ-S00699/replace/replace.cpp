#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int n,Q;
map<string,string> q;
string x,y;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(int i=1; i<=n; i++){
		cin>>x>>y;
		q[x]=y;
	}
	for(int i=1; i<=Q; i++){
		cin>>x>>y;
		ll ans=0;
		if(x.size()!=y.size()){
			cout<<0<<'\n';
			continue;
		}
		if(q[x]==y) ans++;
		x=" "+x;
		y=" "+y;
		int N=x.size()-1;
		for(int l=1; l<N; l++)
			if(q[x.substr(1,l)]==y.substr(1,l)&&x.substr(l+1,N-l)==y.substr(l+1,N-l)) ans++;
		for(int r=N; r>1; r--)
			if(q[x.substr(r,N-r+1)]==y.substr(r,N-r+1)&&x.substr(1,r-1)==y.substr(1,r-1)) ans++;
		for(int l=2; l<=N-1; l++){
			if(x.substr(1,l-1)!=y.substr(1,l-1)) break;
			for(int r=l; r<=N-1; r++)
				if(q[x.substr(l,r-l+1)]==y.substr(l,r-l+1)&&x.substr(r+1,N-r)==y.substr(r+1,N-r)) ans++;
		}
		cout<<ans<<'\n'; 
	}
	return 0;
}

