#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a[6],mx,cha;
}d[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int u,v,w;
		u=v=w=0;
		long long ans=0;
		for(int i=1;i<=n;i++){
			d[i].a[1]=d[i].a[2]=d[i].a[3]=d[i].mx=d[i].cha=0;
			scanf("%lld%lld%lld",&d[i].a[1],&d[i].a[2],&d[i].a[3]);
			long long t=max({d[i].a[1],d[i].a[2],d[i].a[3]});
			if(d[i].a[1]==t)d[i].mx=1,u++;
			else if(d[i].a[2]==t)d[i].mx=2,v++;
			else if(d[i].a[3]==t)d[i].mx=3,w++;
			d[i].cha=d[i].a[1]+d[i].a[2]+d[i].a[3]-t-min({d[i].a[1],d[i].a[2],d[i].a[3]});
			ans+=t; 
		}
		int id=0,cnt=0;
		if(u>n/2)id=1,cnt=u;
		else if(v>n/2)id=2,cnt=v;
		else if(w>n/2)id=3,cnt=w;
		priority_queue<long long>q;
		while(!q.empty())q.pop();
		for(int i=1;i<=n;i++)if(d[i].mx==id)q.push(d[i].cha-d[i].a[id]);
		while(!q.empty()&&cnt>n/2)ans+=q.top(),q.pop(),cnt--;
		printf("%lld\n",ans);
	} 
	return 0;
}

