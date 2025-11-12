#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=2e5+10;
int a[N][4],n,ct[4],ans;
priority_queue < int > Q[4];

inline void work(){
	cin>>n;for(int i=1;i<=n;++i) cin>>a[i][0]>>a[i][1]>>a[i][2];
	for(int i=1;i<=n;++i){
		int mx=max(max(a[i][0],a[i][1]),a[i][2]);ans+=mx;
		if(a[i][0]==mx){++ct[0];Q[0].push(max(a[i][1],a[i][2])-a[i][0]);}
		else if(a[i][1]==mx){++ct[1];Q[1].push(max(a[i][2],a[i][0])-a[i][1]);}
		else if(a[i][2]==mx){++ct[2];Q[2].push(max(a[i][1],a[i][0])-a[i][2]);}
	}
	int z=max(ct[0],max(ct[1],ct[2]));
	if(z>(n>>1)){
		int c=z-(n>>1),op=0;
		if(z==ct[0]) op=0;
		if(z==ct[1]) op=1;
		if(z==ct[2]) op=2;
		for(int i=1;i<=c;++i){
			ans+=Q[op].top();Q[op].pop();
		}
	}
	cout<<ans<<'\n';
	ans=ct[0]=ct[1]=ct[2]=0;
	while(!Q[0].empty()) Q[0].pop();
	while(!Q[1].empty()) Q[1].pop();
	while(!Q[2].empty()) Q[2].pop();
}

int main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;cin>>T;while(T--) work();
	return 0;
}