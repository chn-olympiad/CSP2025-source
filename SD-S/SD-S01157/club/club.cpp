#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
int n,ans=-1,c[4];
struct node{
	int s[4];
}st[maxn];
bool cmp(node x,node y){
	if(x.s[1]<y.s[1])return x.s[1]>y.s[1];
	else{
		if(x.s[2]<y.s[2])return x.s[2]>y.s[2];
	}
}
int solve(int now,int nid,int cnt){
	if(now==n)return cnt;
	int maxx=-1,id;
	for(int i=1;i<=3;i++){
		if(st[now+1].s[i]+st[now].s[nid]>=maxx&&c[i]<n/2){
			maxx=st[now+1].s[i]+st[now].s[nid];
			id=i;
		}
	}
	cnt+=st[now+1].s[id],c[id]++;
	solve(now+1,id,cnt);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		ans=-1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>st[i].s[1]>>st[i].s[2]>>st[i].s[3];
		}
		sort(st+1,st+n+1,cmp);
		st[0].s[1]=st[0].s[2]=st[0].s[3]=0;
		for(int i=1;i<=3;i++){
			c[i]=1;
			for(int j=1;j<=3;j++){
				if(j!=i)c[j]=0;
			}
			int sum=solve(1,i,st[1].s[i]);
			ans=max(ans,sum);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

