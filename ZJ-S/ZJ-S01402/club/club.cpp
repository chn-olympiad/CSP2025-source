#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int t,n,aa[N][5],b[N],c[N],cnt,s,fl,ff,ans,t1,t2,t3,e[N],g[N],f[N];
struct zj{
	int x,y,z;
}a[N];
bool cmp(zj a,zj b){
	if(max(a.x,max(a.y,a.z))!=max(b.x,max(b.y,b.z)))return max(a.x,max(a.y,a.z))>max(b.x,max(b.y,b.z));
	else if(a.x+a.y+a.z-max(a.x,max(a.y,a.z))-min(a.x,min(a.y,a.z))!=b.x+b.y+b.z-max(b.x,max(b.y,b.z))-min(b.x,min(b.y,b.z)))return a.x+a.y+a.z-max(a.x,max(a.y,a.z))-min(a.x,min(a.y,a.z))>b.x+b.y+b.z-max(b.x,max(b.y,b.z))-min(b.x,min(b.y,b.z));
	else if(min(a.x,min(a.y,a.z))!=min(b.x,min(b.y,b.z)))return min(a.x,min(a.y,a.z))>min(b.x,min(b.y,b.z));
}
void dfs(int d,int p,int q,int r){
	if(d>n){
		s=0;
		for(int i=1;i<=n;i++)s+=aa[i][b[i]];
		ans=max(ans,s);
		return ;
	}else{
		for(int i=1;i<=3;i++){
			if(i==1&&p==n/2)continue;
			if(i==2&&q==n/2)continue;
			if(i==3&&r==n/2)continue;
			b[d]=i;
			if(i==1)dfs(d+1,p+1,q,r);
			else if(i==2)dfs(d+1,p,q+1,r);
			else dfs(d+1,p,q,r+1);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		fl=ff=1;
		cnt=ans=t1=t2=t3=0;
		if(n<=20){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin>>aa[i][j];
				}
			}
			dfs(1,0,0,0);
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0)fl=0;
			if(a[i].z!=0)ff=0;
		}
		if(fl&&ff){
			for(int i=1;i<=n;i++)c[++cnt]=a[i].x;
			sort(c+1,c+n+1);
			for(int i=n;i>=n/2+1;i--)ans+=c[i];
			cout<<ans<<'\n';
			continue;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			int cl,tr,id;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				cl=1;tr=1e9;
				if(t1==n/2){
					for(int j=1;j<=t1;j++){
						if(a[e[j]].x-a[e[j]].y>=0&&a[e[j]].x-a[e[j]].y<tr&&t2<n/2){
							id=e[j];
							tr=a[e[j]].x-a[e[j]].y;
							cl=2;
						}
						if(a[e[j]].x-a[e[j]].z>=0&&a[e[j]].x-a[e[j]].z<tr&&t3<n/2){
							id=e[j];
							tr=a[e[j]].x-a[e[j]].z;
							cl=3;
						}
					}
					if(a[i].x-tr>=0){
						if(cl==2){
							e[id]=i;
							f[++t2]=id;
						}else{
							e[id]=i;
							g[++t3]=id;
						}
					}
				}else{
					e[++t1]=i;
				}
			}else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				cl=2;tr=1e9;
				if(t2==n/2){
					for(int j=1;j<=t2;j++){
						if(a[f[j]].y-a[f[j]].x>=0&&a[f[j]].y-a[e[j]].x<tr&&t1<n/2){
							id=f[j];
							tr=a[f[j]].y-a[f[j]].x;
							cl=1;
						}
						if(a[f[j]].y-a[f[j]].z>=0&&a[f[j]].y-a[f[j]].z<tr&&t3<n/2){
							id=f[j];
							tr=a[f[j]].y-a[f[j]].z;
							cl=3;
						}
					}
					if(a[i].y-tr>=0){
						if(cl==1){
							f[id]=i;
							e[++t1]=id;
						}else{
							f[id]=i;
							g[++t3]=id;
						}
					}
				}else{
					f[++t2]=i;
				}
			}else if(a[i].z>=a[i].x&&a[i].y<=a[i].z){
				cl=3;tr=1e9;
				if(t3==n/2){
					for(int j=1;j<=t3;j++){
						if(a[g[j]].z-a[g[j]].x>=0&&a[g[j]].z-a[g[j]].x<tr&&t1<n/2){
							id=g[j];
							tr=a[g[j]].z-a[g[j]].x;
							cl=1;
						}
						if(a[g[j]].z-a[g[j]].y>=0&&a[g[j]].z-a[g[j]].y<tr&&t2<n/2){
							id=g[j];
							tr=a[g[j]].z-a[g[j]].y;
							cl=2;
						}
					}
					if(a[i].z-tr>=0){
						if(cl==1){
							g[id]=i;
							e[++t1]=id;
						}else{
							g[id]=i;
							f[++t2]=id;
						}
					}
				}else{
					g[++t3]=i;
				}
			}
		}
		for(int i=1;i<=t1;i++)ans+=a[e[i]].x;
		for(int i=1;i<=t2;i++)ans+=a[f[i]].y;
		for(int i=1;i<=t3;i++)ans+=a[g[i]].z;
		cout<<ans<<'\n';
	}
	return 0;
} 
