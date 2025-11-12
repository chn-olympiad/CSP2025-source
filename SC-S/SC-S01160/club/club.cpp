#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
int siz[4];
int t;
int n;
int hafn;
struct node{
	int d[4],mnum,w,id;
}num[maxn];

bool cmp(node x,node y){
	return x.mnum>y.mnum;
}
int vis[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		memset(siz,0,sizeof(siz));
		memset(num,0,sizeof(num));
		memset(vis,0,sizeof(vis));
		
		int ans=0;
		cin>>n;
		hafn=n/2;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			
			if(a>=b&&a>=c){
				num[i].d[1]=a;
				num[i].d[2]=b;
				num[i].d[3]=c;
				num[i].mnum=max({a,b,c});
				num[i].w=1;
				num[i].id=i;
			}else if(b>=a&&b>=c){
				num[i].d[1]=a;
				num[i].d[2]=b;
				num[i].d[3]=c;
				num[i].mnum=max({a,b,c});
				num[i].w=2;
				num[i].id=i;
			}else{
				num[i].d[1]=a;
				num[i].d[2]=b;
				num[i].d[3]=c;
				num[i].mnum=max({a,b,c});
				num[i].w=3;
				num[i].id=i;
			}
			
		}
		
		sort(num+1,num+1+n,cmp);
		priority_queue<pair<int,int>,vector<pair<int,int>>>q[3];
		for(int i=1;i<=n;i++){
			if(siz[num[i].w]<hafn){
				siz[num[i].w]++;
				ans+=num[i].mnum;
				for(int j=1;j<=3;j++){
					if(j==num[i].w)continue;
					
					q[num[i].w-1].push({num[i].d[j]-num[i].mnum,num[i].id});
				}
			}else{
				while(vis[q[num[i].w-1].top().second]){
					q[num[i].w-1].pop();
				}
				int mmax=0;
				for(int j=1;j<=3;j++){
					if(j==num[i].w)continue;
					mmax=max(mmax,num[i].d[j]);
				}
				if(q[num[i].w-1].top().first+num[i].mnum>mmax){
					ans+=q[num[i].w-1].top().first+num[i].mnum;
					vis[q[num[i].w-1].top().second]=1;
					for(int j=1;j<=3;j++){
						if(j==num[i].w)continue;
						q[num[i].w-1].push({num[i].d[j]-num[i].mnum,num[i].id});
					}
				}else{
					
					ans+=mmax;
				}
			}
			
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
}