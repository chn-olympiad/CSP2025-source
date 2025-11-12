#include<bits/stdc++.h>
using namespace std;
struct node{
	int i;
	int x;
	int y;
	int z;
};
bool cmp(node a,node b){
	if(a.x>b.x){
		return true;
	}else if(a.x==b.x){
		if(a.y>b.y){
			return true;
		}else if(a.y==b.y){
			if(a.z>b.z){
				return true;
			}
		}
	}
	return false;
}
int T,ans,c[4],n;
node a[100005],b[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		memset(c,0,sizeof(c));
		cin>>n;
//		for(int i=1;i<=n;i++)b[i].i=b[i].x=b[i].y=b[i].z=-1;
		for(int i=1;i<=n;i++){	                  
			cin>>a[i].x>>a[i].y>>a[i].z;
			b[i].i=i;
			int x=a[i].x,y=a[i].y,z=a[i].z;
			if(x>=y && x>=z && y>=z){b[i].x=x;b[i].y=y;b[i].z=z;
			}
			if(x>=y && x>=z && y<=z){b[i].x=x;b[i].y=z;b[i].z=y;
			}
			if(x>=y && x<=z){b[i].x=z;b[i].y=x;b[i].z=y;
			}
			if(x<=y && x>=z){b[i].x=y;b[i].y=x;b[i].z=z;
			}
			if(x<=y && x<=z && y>=z){b[i].x=y;b[i].y=z;b[i].z=x;
			}
			if(x<=y && x<=z && y<=z){b[i].x=z;b[i].y=y;b[i].z=x;
			}
		}
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=b[b[i].i].x;
		}
//		cout<<"\n";
//		for(int i=1;i<=n;i++){
//			cout<<b[i].x<<" "<<b[i].y<<" "<<b[i].z<<" "<<b[i].i<<"\n";
//		}
//		cout<<"\n";
//		for(int i=1;i<=n;i++){
////			cout<<b[i].i<<"\n";
//			int X=a[b[i].i].x,Y=a[b[i].i].y,Z=a[b[i].i].z;
//			int u,v,w;
//			if(X>=Y && X>=Z && Y>=Z){w=X;v=Y;u=Z;
//			}
//			else if(X>=Y && X>=Z && Y<=Z){w=X;v=Z;u=Y;
//			}
//			else if(X>=Y && X<=Z){w=Z;v=X;u=Y;
//			}
//			else if(X<=Y && X>=Z){w=Y;v=X;u=Z;
//			}
//			else if(X<=Y && X<=Z && Y>=Z){w=Y;v=Z;u=X;
//			}
//			else if(X<=Y && X<=Z && Y<=Z){w=Z;v=Y;u=X;
//			}
////			cout<<"\n";
////			cout<<u<<" "<<v<<" "<<w<<"\n";
//			if(w==X && c[1]<n/2){
//				c[1]++;
//				ans+=w;
//			}
//			else if(w==Y && c[2]<n/2){
//				c[2]++;
//				ans+=w;
//			}
//			else if(w==Z && c[3]<n/2){
//				c[3]++;
//				ans+=w;
//			}
//			else if(v==X && c[1]<n/2){
//				c[1]++;
//				ans+=v;
//			}
//			else if(v==Y && c[2]<n/2){
//				c[2]++;
//				ans+=v;
//			}
//			else if(v==Z && c[3]<n/2){
//				c[3]++;
//				ans+=v;
//			}
//			else if(u==X && c[1]<n/2){
//				c[1]++;
//				ans+=u;
//			}
//			else if(u==Y && c[2]<n/2){
//				c[2]++;
//				ans+=u;
//			}
//			else if(u==Z && c[3]<n/2){
//				c[3]++;
//				ans+=u;
//			}
//		}
		cout<<ans<<"\n";
	}
	return 0;
}
		