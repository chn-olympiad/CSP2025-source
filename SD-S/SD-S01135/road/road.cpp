#include<bits/stdc++.h>
using namespace std;
struct my {
	long long qi,wei,quan;
	bool operator <(const my &k) const {
		return quan>k.quan;
	}
};
struct mm{
	long long ki[10003];
	long long ben;
};
mm vv[20];
priority_queue<my>qu1;
long long n,m,k;
long long ans,b,c,v;
long long fa[10003];
long long findd (long long a) {
	if(fa[a]==a) return a;
	else return findd(fa[a]);
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1; i<=m; i++) {
		cin>>b>>c>>v;
		qu1.push({b,c,v});
	}
	for(int i=1; i<=n-1; i++) {
		bool flag=0;
		while (!flag) {
			my bb=qu1.top();
			qu1.pop();
			if(findd(bb.qi)!=findd(bb.wei)) {
				fa[findd(bb.wei)]=findd(bb.qi);
				flag=1;
				ans+=bb.quan;
			}
		}
	}
	for(int i=1; i<=k; i++) {
		cin>>vv[i].ben;
		for(int j=1; j<=n; j++) {
			cin>>vv[i].ki[j];
		}
	}
	
	cout<<ans;
	return 0;
}

