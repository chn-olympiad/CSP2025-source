#include<bits/stdc++.h>
const int slen=1e5+10;
using namespace std;
struct info{
  int x,y,z,maxv,wz,minv,wz2;
}a[slen];
bool cmp(info a,info b){
  return a.maxv>b.maxv;
}
bool cmp1(info a,info b){
  return a.minv>b.minv;
}
int f[4],n,ans,vis[slen];
int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  int t;
  scanf("%d",&t);
  for(int o=1;o<=t;o++){
  	scanf("%d",&n);ans=0;
  	memset(a,0,sizeof(a));memset(f,0,sizeof(0));memset(vis,0,sizeof(vis));
  	for(int i=1;i<=n;i++){
  	  int x,y,z,maxv;
  	  scanf("%d%d%d",&x,&y,&z);
  	  a[i].x=x;a[i].y=y;a[i].z=z;
  	  maxv=max(x,max(y,z));a[i].maxv=maxv;
  	  if(maxv==x) {a[i].minv=max(y,z);a[i].wz2=1;f[1]++;if(a[i].minv==y)a[i].wz=2;else a[i].wz=3;}
  	  if(maxv==y) {a[i].minv=max(x,z);a[i].wz2=2;f[2]++;if(a[i].minv==x)a[i].wz=1;else a[i].wz=3;}
  	  if(maxv==z) {a[i].minv=max(y,x);a[i].wz2=3;f[3]++;if(a[i].minv==y)a[i].wz=2;else a[i].wz=1;}
	}
	bool flag=1;
	for(int i=1;i<=n;i++) if(a[i].y!=0||a[i].z!=0) flag=0;
	if(flag){
	  sort(a+1,a+n+1,cmp);
	  for(int i=1;i<=n/2;i++) ans+=a[i].maxv;
	  cout<<ans<<endl;continue;
	}
	if(f[1]<=n/2&&f[2]<=n/2&&f[3]<=n/2){
	  for(int i=1;i<=n;i++) ans+=a[i].maxv;
	  cout<<ans<<endl;continue;
	} 
	else{
	  int x=0;
	  for(int i=1;i<=3;i++) if(f[i]>n/2) x=i;
	  memset(f,0,sizeof(0));
	  for(int i=1;i<=n;i++){
	  	int tt=0;memset(vis,0,sizeof(vis));
	  	memset(f,0,sizeof(f));
	  	for(int j=i;j<=i+n/2;j++){
	  	  tt+=a[j].maxv;
	  	  vis[j]=1;
	  	  f[a[j].wz2]++;
		}
		for(int j=1;j<=n;j++){
		  if(vis[j]==1) continue;
		  if(f[j]<n/2) {tt+=a[j].maxv,f[a[j].wz2]++;}
		  else {tt+=a[j].minv,f[a[j].wz]++;}
		}
		ans=max(ans,tt);
	  }
	  cout<<ans<<endl;continue;
	}
  }
  return 0;
}