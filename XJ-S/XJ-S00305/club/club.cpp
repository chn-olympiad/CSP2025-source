#include <bits/stdc++.h>
using namespace std;
int t;
int maxn[100005];
int k[100005];
int g[100005];
long long ans;
int a[100005];
int b[100005];
int c[100005];
int x,y,z;
bool vis[100005][3];
bool cmp(int a,int b){
	return a<b;
}
struct Node{
	int a,b,c;
}q[100005];
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int z=1;z<=t;z++){
		ans=0;
		int n;
		cin>>n;
		x=n,y=n,z=n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			maxn[i]=a[i];
			if(b[i]>c[i]){
				z--;
				if(b[i]>maxn[i]){
					maxn[i]=b[i];
					x--;
					if(a[i]>c[i]){
						k[i]=a[i];
					}else{
						k[i]=c[i];
					}
					vis[i][2]=1;
				}else{
					y--;
					vis[i][1]=1;
					k[i]=b[i];
				}
			}else{
				y--;
				if(c[i]>maxn[i]){
					maxn[i]=c[i];
					x--;
					if(a[i]>b[i]){
						k[i]=a[i];
					}else{
						k[i]=c[i];
					}
					vis[i][3]=1;
				}else{
					z--;
					k[i]=c[i];
					vis[i][1]=1;
				}
			}
		} 
		for(int i=0;i<n;i++){
			ans+=maxn[i];
		}
		if(x>n/2){
	    	for(int i=0;i<n;i++){
	    		if(vis[i][1]==0){
	    			a[i]=200000;
				}else{
					g[i]=maxn[i]-k[i];
				}
			}
			sort(g,g+n+1,cmp);
			for(int i=1;i<=x-n/2;i++){
				ans-=g[i];
			}
		}else if(y>n/2){
			for(int i=0;i<n;i++){
	    		if(vis[i][2]==0){
	    			b[i]=200000;
				}else{
					g[i]=maxn[i]-k[i];
				}
			}
			sort(g,g+n+1,cmp);
			for(int i=1;i<=y-n/2;i++){
				ans-=g[i];
			}
		}else if(z>n/2){
			for(int i=0;i<n;i++){
	    		if(vis[i][3]==0){
	    			a[i]=200000;
				}else{
					g[i]=maxn[i]-k[i];
				}
			}
			sort(g,g+n+1,cmp);
			for(int i=1;i<=z-n/2;i++){
				ans-=g[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 

