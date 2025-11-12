#include<bits/stdc++.h>
using namespace std;



const int maxn=100005;
struct node{
	int a[4];
}e[maxn];
int vis[maxn];


int n;
int a[maxn],b[maxn],c[maxn];
int ans,x,y,z,fx,fy,fz;
node q[maxn];
bool cmp(node v,node u){
	if(v.a[1]==u.a[1]){
		if(v.a[2]==u.a[2])return v.a[3]>u.a[3];
		return v.a[2]>u.a[2];
	}
	return v.a[1]>u.a[1];
}
bool cmp1(node v,node u){
	if(v.a[2]==u.a[2])return v.a[3]>u.a[3];
	return v.a[2]>u.a[2];
}
void init(){
	for(int i=1;i<=n;i++){
		q[i].a[1]=q[i].a[2]=q[i].a[3]=0;
	}
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		x=y=z=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>e[i].a[j];
			}
		}
//		sort(e+1,e+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(e[i].a[1]>=e[i].a[2]&&e[i].a[1]>=e[i].a[3]){
				ans+=e[i].a[1];
				x++;
				vis[i]=1;
			}else if(e[i].a[2]>=e[i].a[1]&&e[i].a[2]>=e[i].a[3]){
				ans+=e[i].a[2];
				y++;
				vis[i]=2;
			}else if(e[i].a[3]>=e[i].a[1]&&e[i].a[3]>=e[i].a[2]){
				ans+=e[i].a[3];
				z++;
				vis[i]=3;
			}
		}
		if(x>y&&x>z){
			

		if(x>n/2){
			for(int i=1;i<=n;i++){
				if(vis[i]==1){
					q[i].a[1]=i,q[i].a[2]=e[i].a[1]-e[i].a[2],q[i].a[3]=e[i].a[1]-e[i].a[3];
				}
			}
			sort(q+1,q+n+1,cmp1);
			fx=x;
			for(int i=x;i>=1;i--){
				x--;
				if(q[i].a[2]<q[i].a[3]){
					y++;
					ans-=q[i].a[2];
				}else{
					z++;
					ans-=q[i].a[3];
				}
				if(x<=n/2)break;
			}
		}
		init();
		if(y>n/2){
			for(int i=1;i<=n;i++){
				if(vis[i]==2){
					q[i].a[1]=i,q[i].a[2]=e[i].a[2]-e[i].a[3];
				}
			}
			sort(q+1,q+n+1,cmp1);
			for(int i=y;i>=1;i--){
				y--;
				z++;
				ans-=q[i].a[2];
				if(y<=n/2)break;
			}
		}
		init();
		if(z>n/2){
			for(int i=1;i<=n;i++){
				if(vis[i]==3){
					q[i].a[1]=i,q[i].a[2]=e[i].a[3]-e[i].a[2];
				}
			}
			sort(q+1,q+n+1,cmp1);
			for(int i=z;i>=1;i--){
				z--;
				y++;
				ans-=q[i].a[2];
				if(z<=n/2)break;
			}
		}
		}
		
		else if(z>x&&z>y){
			

		if(z>n/2){
			for(int i=1;i<=n;i++){
				if(vis[i]==3){
					q[i].a[1]=i,q[i].a[2]=e[i].a[3]-e[i].a[1],q[i].a[3]=e[i].a[3]-e[i].a[2];
				}
			}
			sort(q+1,q+n+1,cmp1);
			for(int i=z;i>=1;i--){
				z--;
				if(q[i].a[2]<q[i].a[3]){
					x++;
					ans-=q[i].a[2];
				}else{
					y++;
					ans-=q[i].a[3];
				}
				if(z<=n/2)break;
			}
		}
		init();
		if(y>n/2){
			for(int i=1;i<=n;i++){
				if(vis[i]==2){
					q[i].a[1]=i,q[i].a[2]=e[i].a[2]-e[i].a[1];
				}
			}
			sort(q+1,q+n+1,cmp1);
			for(int i=y;i>=1;i--){
				y--;
				x++;
				ans-=q[i].a[2];
				if(y<=n/2)break;
			}
		}
		init();
		if(x>n/2){
			for(int i=1;i<=n;i++){
				if(vis[i]==1){
					q[i].a[1]=i,q[i].a[2]=e[i].a[1]-e[i].a[2];
				}
			}
			sort(q+1,q+n+1,cmp1);
			for(int i=x;i>=1;i--){
				x--;
				y++;
				ans-=q[i].a[2];
				if(x<=n/2)break;
			}
		}
		}
		
		if(y>x&&y>z){
			

		if(y>n/2){
			for(int i=1;i<=n;i++){
				if(vis[i]==2){
					q[i].a[1]=i,q[i].a[2]=e[i].a[2]-e[i].a[1],q[i].a[3]=e[i].a[2]-e[i].a[3];
				}
			}
			sort(q+1,q+n+1,cmp1);
			for(int i=y;i>=1;i--){
				y--;
				if(q[i].a[2]<q[i].a[3]){
					x++;
					ans-=q[i].a[2];
				}else{
					z++;
					ans-=q[i].a[3];
				}
				if(y<=n/2)break;
			}
		}
		init();
		if(x>n/2){
			for(int i=1;i<=n;i++){
				if(vis[i]==1){
					q[i].a[1]=i,q[i].a[2]=e[i].a[1]-e[i].a[3];
				}
			}
			sort(q+1,q+n+1,cmp1);
			for(int i=x;i>=1;i--){
				x--;
				z++;
				ans-=q[i].a[2];
				if(x<=n/2)break;
			}
		}
		init();
		if(z>n/2){
			for(int i=1;i<=n;i++){
				if(vis[i]==3){
					q[i].a[1]=i,q[i].a[2]=e[i].a[3]-e[i].a[1];
				}
			}
			sort(q+1,q+n+1,cmp1);
			for(int i=z;i>=1;i--){
				z--;
				x++;
				ans-=q[i].a[2];
				if(z<=n/2)break;
			}
		}
		}
		
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}
/*
1
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522
*/