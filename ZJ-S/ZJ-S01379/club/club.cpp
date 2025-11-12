#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,op,z,TTT,cnt[4];
struct node{
	int mx,mn,gg,k;
}a[100005];
bool cmp(node a,node b){
	if(a.k==op&&b.k!=op)return 1;
	if(a.k!=op&&b.k==op)return 0;
	return a.gg<b.gg;
}
signed main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	cin>>TTT;
	while(TTT--){
		cin>>n;int ans=0;
		z=n/2;memset(cnt,0,sizeof cnt);
		for(int i=1,u,v,w;i<=n;i++){
			cin>>u>>v>>w;
			if(u>=v&&v>=w)a[i].k=1,a[i].mx=u,a[i].mn=2,a[i].gg=u-v;
			else if(u>=w&&w>=v)a[i].k=1,a[i].mx=u,a[i].mn=3,a[i].gg=u-w;
			else if(v>=u&&u>=w)a[i].k=2,a[i].mx=v,a[i].mn=1,a[i].gg=v-u;
			else if(v>=w&&w>=u)a[i].k=2,a[i].mx=v,a[i].mn=3,a[i].gg=v-w;
			else if(w>=u&&u>=v)a[i].k=3,a[i].mx=w,a[i].mn=1,a[i].gg=w-u;
			else if(w>=v&&v>=u)a[i].k=3,a[i].mx=w,a[i].mn=2,a[i].gg=w-v;
		}
		for(int i=1;i<=n;i++)ans+=a[i].mx,cnt[a[i].k]++;
		int ccc=max(cnt[1],max(cnt[2],cnt[3]));
		for(int i=1;i<=3;i++)if(cnt[i]==ccc){
			op=i;break;
		}
		ccc-=z;
		if(ccc<=0){cout<<ans<<'\n';continue;}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=ccc;i++)ans-=a[i].gg;
		cout<<ans<<'\n';
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
