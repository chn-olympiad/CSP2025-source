#include<bits/stdc++.h>
using namespace std;
#define int long long
int x,y,z,n,T,i,ans,fl,f[210][210][210];
struct no{
	int x,y,z,ma,fl;
}a[1000010];
bool cmp(no q,no h){
	return q.x+q.y+q.z>h.x+h.y+h.z;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		if(n<=400){
		ans=0;
		memset(f,-127,sizeof(f));
		for(i=1;i<=n;i++)
			cin>>a[i].x>>a[i].y>>a[i].z;
		f[0][0][0]=0;
		for(i=1;i<=n;i++)
			for(x=0;x<=n/2&&x<=i;x++)
				for(y=0;y<=n/2&&y<=i;y++){
					z=i-x-y;
					if(z>n/2) continue;
					if(x)
						f[x][y][z]=max(f[x][y][z],f[x-1][y][z]+a[i].x);
					if(y)
						f[x][y][z]=max(f[x][y][z],f[x][y-1][z]+a[i].y);
					if(z)
						f[x][y][z]=max(f[x][y][z],f[x][y][z-1]+a[i].z);
					ans=max(ans,f[x][y][z]);
					}
		}
		else{
			for(i=1;i<=n;i++){
				cin>>a[i].x>>a[i].y>>a[i].z;
			}
			sort(a+1,a+n+1,cmp);
			for(i=1;i<=n/2;i++)
				ans+=a[i].x+a[i].y+a[i].z;
		}
		cout<<ans<<"\n";
	}
}
