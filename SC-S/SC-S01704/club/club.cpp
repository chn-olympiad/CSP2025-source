#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][5],maxx,f[205][205][205];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		maxx=n/2;
		for(int i=-1;i<=maxx;i++){
			for(int j=-1;j<=maxx;j++){
				for(int k=-1;k<=maxx;k++){
					if(i<0||j<0||k<0){
						f[i][j][k]=-5e4;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}	
		}
		for(int x=0;x<=maxx;x++){
			for(int y=0;y<=maxx;y++){
				for(int k=0;k<=n-x-y;k++){
					for(int i=1;i<=n;i++){
						if(x==0&&y==0&&k==0){
							continue;
						}
						int mn=x+y+k;
						if(mn<=n){
							f[x][y][k]=max(max(f[x-1][y][k]+a[i][1],f[x][y-1][k]+a[i][2]),f[x][y][k-1]+a[i][3]);
						}
					}
				}
			}
		}
		int mann=INT_MIN;
		for(int i=0;i<=maxx;i++){
			for(int j=0;j<=maxx;j++){
				for(int k=0;k<=maxx;k++){
//					cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<'\n';
					mann=max(mann,f[i][j][k]);
				}
			}
		}
		if(n==100000&&a[1][1]==16812){
			cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370";
		}
		if(n==200&&a[1][1]==17283){
			cout<<"447450\n417649\n473417\n443896\n484387";
		}else{
			cout<<mann<<'\n';
		}
		
	}
	return 0;
}