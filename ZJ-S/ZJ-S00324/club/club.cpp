#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,aa,bb,cc,ans;
struct node{
	int x,y,z,cha,maxn;
}f[N];
bool cmp(node x,node y){
	return x.cha>y.cha;
}
int find(int x,int y,int z){
	int ret;
	ret=2*(max( x,max(y,z) ))+min(x,min(y,z))-x-y-z;
	return ret;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		aa=0,bb=0,cc=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>f[i].x>>f[i].y>>f[i].z;
			if(f[i].x>=f[i].y){
				if(f[i].x>=f[i].z){
					f[i].maxn=1;
				}
				else{
					f[i].maxn=3;
				}
			}
			else{
				if(f[i].y>=f[i].z){
					f[i].maxn=2;
				}
				else{
					f[i].maxn=3;
				}
			}
			f[i].cha=find(f[i].x,f[i].y,f[i].z);
		}
		sort(f+1,f+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(f[i].maxn==1){
				if(aa<n/2){
					ans+=f[i].x;
					aa++;
				}
				else{
					if(f[i].y>f[i].z) ans+=f[i].y;
					else ans+=f[i].z;
				}
			}
			else if(f[i].maxn==2){
				if(bb<n/2){
					ans+=f[i].y;
					bb++;
				}
				else{
					if(f[i].x>f[i].z) ans+=f[i].x;
					else ans+=f[i].z;
				}
			}
			else{
				if(cc<n/2){
					ans+=f[i].z;
					cc++;
				}
				else{
					if(f[i].x>f[i].y) ans+=f[i].x;
					else ans+=f[i].y;
				}
			}	
		}
		cout<<ans<<'\n';
	}
	return 0;
}
