#include<bits/stdc++.h>
using namespace std;
int T,n,sum[4],ans,b[4],vis[4];
struct node{
	int x,y,z,mx,md,mi;
}a[100005];
bool cmp(node p,node q){
	if(p.mx-p.md==q.mx-q.md)return p.mx>q.mx;
	return p.mx-p.md>q.mx-q.md;
}
void x(int i){
	sum[a[i].x]++;
	ans+=a[i].mx;
}
void y(int i){
	sum[a[i].y]++;
	ans+=a[i].md;
}
void z(int i){
	sum[a[i].z]++;
	ans+=a[i].mi;
}
void solve(){
	cin>>n;
	ans=0;
	sum[1]=0,sum[2]=0,sum[3]=0;
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		vis[1]=0,vis[2]=0,vis[3]=0;
		b[1]=x,b[2]=y,b[3]=z;
		a[i].mx=max(x,max(y,z));
		a[i].mi=min(x,min(y,z));
		a[i].md=x+y+z-a[i].mx-a[i].mi;
		for(int j=1;j<=3;j++){
			if(a[i].mx==b[j]){
				vis[j]=1;
				a[i].x=j;
				break;
			}
		}
		for(int j=1;j<=3;j++){
			if(a[i].md==b[j]&&!vis[j]){
				vis[j]=1;
				a[i].y=j;
				break;
			}
		}
		for(int j=1;j<=3;j++){
			if(a[i].mi==b[j]&&!vis[j]){
				vis[j]=1;
				a[i].z=j;
				break;
			}
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(sum[a[i].x]!=n/2){
			if(a[i].mx>a[i].md)x(i);
			else if(a[i].mx>a[i].mi){
				if(sum[a[i].x]>sum[a[i].y]){
					y(i);
				}
				else x(i);
			}
			else{
				if(sum[a[i].x]<sum[a[i].y]&&sum[a[i].x]<sum[a[i].z])x(i);
				else if(sum[a[i].y]<sum[a[i].x]&&sum[a[i].y]<sum[a[i].z])y(i);
				else z(i);
			}
		}
		else{
			if(a[i].md>a[i].mi){
				y(i);
			}
			else{
				if(sum[a[i].y]>sum[a[i].z]){
					z(i);
				}
				else y(i);
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)solve();
}
