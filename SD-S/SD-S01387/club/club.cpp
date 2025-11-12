#include<bits/stdc++.h>
using namespace std;
long long t,n,a[110000][10],f[220][220][220],m;
priority_queue<long long>q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		long long l=1,r=1;
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
				if(a[i][j]&&j==2){
					l=0;
				}
				if(a[i][j]&&j==3){
					r=0;
				}
			}
		}
		for(long long i=0;i<=n/2;i++){
			for(long long j=0;j<=n/2;j++){
				for(long long k=0;k<=min(n-i-j,n/2);k++){
					f[i][j][k]=0;
				}
			}
		}
		m=0;
		
////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if(r){
			for(long long x=1;x<=n;x++){
				for(long long i=min(x,n/2);i>=0;i--){
					long long j=min(x-i,n/2);
					long long k=x-i-j;
					if(k>n/2){
						continue;
					}
					if(i){
						f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[x][1]);
					}
					if(j){
						f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+a[x][2]);
					}
					m=max(m,f[i][j][k]);
				}
			}
			printf("%lld\n",m);
			continue;
		}
		
////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if(l==r&&r){
			while(!q.empty()){
				q.pop();
			}
			for(long long i=1;i<=n;i++){
				q.push(a[i][1]);
			}
			for(long long i=1;i<=n/2;i++){
				m+=q.top();
				q.pop();
			}
			printf("%lld\n",m);
			continue;
		}
		
////////////////////////////////////////////////////////////////////////////////////////////////////////////
		for(long long x=1;x<=n;x++){
			for(long long i=min(x,n/2);i>=0;i--){
				for(long long j=min(x-i,n/2);j>=0;j--){
					long long k=x-i-j;
					if(k>n/2){
						continue;
					}
					if(i){
						f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[x][1]);
					}
					if(j){
						f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+a[x][2]);
					}
					if(k){
						f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+a[x][3]);
					}
//						printf("%lld %lld %lld %lld: %lld\n",x,i,j,k,f[i][j][k]);
					m=max(m,f[i][j][k]);
				}
			}
		}
		printf("%lld\n",m);
		
////////////////////////////////////////////////////////////////////////////////////////////////////////////
	}
	return 0;
} 
