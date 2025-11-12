#include<bits/stdc++.h>
using namespace std;
const int N1=1e5+10,N=210,M=110;
int n;
struct p {
	int d1,d2,d3;
}a[N1];
int f[N][M][M][M];
bool cmp(p x,p y) {
	return x.d1>y.d1;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		bool q=1;
		cin>>n;
		for(int i=1;i<=n;i++) {
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			if(a[i].d2!=0 || a[i].d3!=0) q=0;
		}
		if(q) {
			sort(a+1,a+n+1,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++) ans+=(long long)a[i].d1;
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++) {
			for(int x=0;x<=n/2;x++) {
				for(int y=0;y<=n/2;y++) {
					for(int z=0;z<=n/2;z++){
						f[i][x][y][z]=0;
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++) {
			for(int x=0;x<=n/2;x++) {
				for(int y=0;y<=n/2 && x+y<=i;y++) {
					int z=i-x-y;
					if(z>n/2) continue;
					if(x==0 && y==0 && z==0) continue;
					if(x==0 && y==0) f[i][x][y][z]=f[i-1][x][y][z-1]+a[i].d3;
					else {
						if(x==0 && z==0) f[i][x][y][z]=f[i-1][x][y-1][z]+a[i].d2;
						else {
							if(y==0 && z==0) f[i][x][y][z]=f[i-1][x-1][y][z]+a[i].d1;
							else {
								if(x==0) f[i][x][y][z]=max(f[i-1][x][y-1][z]+a[i].d2,f[i-1][x][y][z-1]+a[i].d3);
								else {
									if(y==0) f[i][x][y][z]=max(f[i-1][x-1][y][z]+a[i].d1,f[i-1][x][y][z-1]+a[i].d3);
									else {
										if(z==0) f[i][x][y][z]=max(f[i-1][x-1][y][z]+a[i].d1,f[i-1][x][y-1][z]+a[i].d2);
										else f[i][x][y][z]=max(f[i-1][x-1][y][z]+a[i].d1,max(f[i-1][x][y-1][z]+a[i].d2,f[i-1][x][y][z-1]+a[i].d3));
									}
								}
							}
						}
					}
					ans=max(ans,f[i][x][y][z]);
				}
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
