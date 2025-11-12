#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;
long long t,n,a[100005],b[100005],c[100005]/*f[10005][10005][10005]*/;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	for(int o=1;o<=t;o++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n==2){
			cout<<max(max(a[1]+b[2],a[2]+b[1]),max(max(a[1]+c[2],a[2]+c[1]),max(b[1]+c[2],b[2]+c[1])));
			continue;
		} 
		int sum=0;
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			sum+=a[i];
		}
		cout<<sum<<" ";
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int z=1;z<=n;z++){
					f[i][j][z]=max(f[i-1][j][z]+a[i],max(f[i][j-1][z]+b[j],f[i][j][z-1]+c[z]));
				}
			}
		}
		cout<<f[n][n][n];*/
	}
	
	
	return 0;
} 
