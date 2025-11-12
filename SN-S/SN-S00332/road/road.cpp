#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,fa[1000005];
struct node{
	int x,y,z;
}b[1000005],d[1000005];
int qwq[11][10004],a[11];

bool cmp(node x,node y){
	return x.z<y.z;
}

int find(int x){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>b[i].x>>b[i].y>>b[i].z;
	}
	bool v=1;
	for(int i=1;i<=k;i++){
		cin>>a[i];
		if(a[i]!=0)v=0;
		for(int j=1;j<=n;j++){
			cin>>qwq[i][j];
		}
	}
	
	if(v){
		for(int i=1;i<=n+n*k;i++)fa[i]=i;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				m++;
				b[m].x=n+i;
				b[m].y=j;
				b[m].z=qwq[i][j];
			}
		}
		
		sort(b+1,b+m+1,cmp);
		int tot=0,s=0;
		for(int i=1;i<=m;i++){
			int u=b[i].x,v=b[i].y;
			if(find(u)!=find(v)){
				fa[find(u)]=find(v);
				tot++;
				b[tot].x=u;
				b[tot].y=v;
				b[tot].z=b[i].z;
				s+=b[i].z;
			}
		}
		
		cout<<s;
	}
	else{
		sort(b+1,b+m+1,cmp);
		int tot=0,s=0;
		for(int i=1;i<=m;i++){
			int u=b[i].x,v=b[i].y;
			if(find(u)!=find(v)){
				fa[find(u)]=find(v);
				tot++;
				b[tot].x=u;
				b[tot].y=v;
				b[tot].z=b[i].z;
				s+=b[i].z;
			}
		}
		
		int ans=s;
		for(int i=0;i<(1<<k);i++){
			int cnt=tot,ans1=0,num=0;
			for(int i=1;i<=tot;i++){
				d[i].x=b[i].x;
				d[i].y=b[i].y;
				d[i].z=b[i].z;
			}
			for(int j=0;j<k;j++){
				if((i>>j)&1){
					num++;
					ans1+=a[j+1];
					for(int o=1;o<=n;o++){
						cnt++;
						d[cnt].x=o;
						d[cnt].y=n+j+1;
						d[cnt].z=qwq[j+1][o];
					}
				}
			}
			
			for(int i=1;i<=n+num*n;i++)fa[i]=i;
			sort(d+1,d+cnt+1,cmp);
			for(int i=1;i<=cnt;i++){
				int u=d[i].x,v=d[i].y;
				if(find(u)!=find(v)){
					fa[find(u)]=find(v);
					ans1+=d[i].z;
				}
			}
			ans=min(ans,ans1);
			//cout<<ans1<<" ";
		}
		cout<<ans;
	}
	
	return 0;
}
