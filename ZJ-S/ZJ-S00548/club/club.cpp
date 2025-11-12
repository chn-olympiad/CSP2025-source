#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,aa[1000010],b[1000010],c[1000010],ma;
struct no {
	int t,tt,ttt,x,y,z,a,b,c;
}a[1000010];
bool cmp(no q,no w){
	if(q.t<w.t) return 0;
	else if(q.t==w.t&&q.tt<w.tt) return 0;
	else if(q.t==w.t&&q.tt==w.tt&&q.ttt<w.ttt) return 0;
	return 1;
}
void dfs(int x,int y,int z,int ans,int t){
	if(t==n+1){
		ma=max(ma,ans);return ;
	}
	if(x==n/2){
		dfs(x,y+1,z,ans+b[t],t+1);
		dfs(x,y,z+1,ans+c[t],t+1);
		return ;
	}
	if(y==n/2){
		dfs(x+1,y,z,ans+aa[t],t+1);
		dfs(x,y,z+1,ans+c[t],t+1);
		return ;
	}
	if(z==n/2){
		dfs(x+1,y,z,ans+aa[t],t+1);
		dfs(x,y+1,z,ans+b[t],t+1);
		return ;
	}
	dfs(x+1,y,z,ans+aa[t],t+1);
	dfs(x,y+1,z,ans+b[t],t+1);
	dfs(x,y,z+1,ans+c[t],t+1);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;int k=n/2;
		if(n<=30){
			ma=0;
			for(int i=1;i<=n;i++)
				cin>>aa[i]>>b[i]>>c[i];
			dfs(0,0,0,0,1);
			cout<<ma<<"\n";continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>a[i].y&&a[i].x>a[i].z){//x>y,z
				a[i].t=a[i].x-max(a[i].y,a[i].z);
				a[i].a=1;
				if(a[i].y>=a[i].z){//x>y>z
					a[i].tt=a[i].y-a[i].z;a[i].b=2;
					a[i].ttt=a[i].z;a[i].c=3;
				}
				else if(a[i].y<a[i].z){//x>z>y
					a[i].tt=a[i].z-a[i].y;a[i].c=2;
					a[i].ttt=a[i].z;a[i].b=3;
				}
			}else if(a[i].y>a[i].x&&a[i].y>a[i].z){//y>x,z
				a[i].b=1;
				a[i].t=a[i].y-max(a[i].x,a[i].z);
				if(a[i].x>=a[i].z){//y>x>z
					a[i].tt=a[i].x-a[i].z;a[i].c=3;
					a[i].ttt=a[i].z;a[i].a=2;
				}
				else if(a[i].x<a[i].z){//y>z>x
					a[i].tt=a[i].z-a[i].x;a[i].a=3;
					a[i].ttt=a[i].x;a[i].c=2;
				}
			}else if(a[i].z>a[i].y&&a[i].z>a[i].x){//z>y,x
				a[i].c=1;
				a[i].tt=a[i].z-max(a[i].x,a[i].y);
				if(a[i].y>=a[i].x){//z>y>x
					a[i].tt=a[i].y-a[i].x;a[i].a=3;
					a[i].ttt=a[i].x;a[i].b=2;
				}
				else if(a[i].y<a[i].x){//z>x>y
					a[i].tt=a[i].x-a[i].y;a[i].b=3;
					a[i].ttt=a[i].y;a[i].a=2;
				}
			}
		}
		sort(a+1,a+n+1,cmp);
		int ans=0,A=0,B=0,C=0;
		for(int i=1;i<=n;i++){
			
			if(a[i].a==1){
				if(A<n/2) ans+=a[i].x,A++;
				else {
					if(a[i].b==2&&B<=n/2) ans+=a[i].y;
					else ans+=a[i].z,C++;
				}
			}
			if(a[i].b==1){
				if(B<n/2) ans+=a[i].y,B++;
				else {
					if(a[i].a==2&&A<=n/2) ans+=a[i].x,A++;
					else ans+=a[i].z,C++;
				}
			}
			if(a[i].c==1){
				if(C<n/2) ans+=a[i].z;
				else {
					if(a[i].b==2&&B<=n/2) ans+=a[i].y,B++;
					else ans+=a[i].x,A++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
