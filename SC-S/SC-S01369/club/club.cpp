#include<bits/stdc++.h>
using namespace std;
const int N=205,N1=1e5+5;
int n,f[2][N][N];
struct node{
	int x,y,z;
}a[N1];
bool cmp(node x,node y){
	return x.x>y.x;
}
bool cmp1(node x,node y){
	return x.x-x.y>y.x-y.y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int cnta=0,cntb=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			cnta+=(!a[i].y&&!a[i].z),cntb+=(!a[i].z);
		}
		if(cnta==n){
			sort(a+1,a+n+1,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++)
				ans+=a[i].x;
			cout<<ans<<'\n';
		}
		else
			if(cntb==n){
				sort(a+1,a+n+1,cmp1);
				int ans=0;
				for(int i=1;i<=n/2;i++)
					ans+=a[i].x;
				for(int i=n/2+1;i<=n;i++)
					ans+=a[i].y;
				cout<<ans<<'\n';
			}
		else{
			memset(f,-2e9,sizeof f);
			f[0][0][0]=0;
			for(int i=1;i<=n;i++)
				for(int j=0;j<=n/2;j++)
					for(int k=0;k<=n/2;k++)
						if(j+k<=i){
							if(j>0)
								f[i%2][j][k]=max(f[i%2][j][k],f[(i-1)%2][j-1][k]+a[i].x);
							if(k>0)
								f[i%2][j][k]=max(f[i%2][j][k],f[(i-1)%2][j][k-1]+a[i].y);
							if(i-j-k>0)
								f[i%2][j][k]=max(f[i%2][j][k],f[(i-1)%2][j][k]+a[i].z);
						}
			int ans=0;
			for(int i=0;i<=n/2;i++)
				for(int j=0;j<=n/2;j++)
					if(i+j>=n/2)
						ans=max(ans,f[n%2][i][j]);
			cout<<ans<<'\n';
		}
	}
	return 0;
}