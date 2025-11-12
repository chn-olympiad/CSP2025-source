#include<bits/stdc++.h>
using namespace std;
int t;
int a[100005][5];
int b[500005],c[5],d[5][100005],e[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio;
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int sum;
	cin>>t;
	int n;
	while(t--){
		int sum=0;
		cin>>n;
		if(n!=2){
			for(int i=1;i<=n;i++){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
				b[a[i][1]]=1;
				b[a[i][2]]=2;
				b[a[i][3]]=3;
				sort(a[i]+1,a[i]+4,cmp);
				d[1][i]=a[i][1],d[2][i]=a[i][2],d[3][i]=a[i][3];
				e[d[1][i]]=i,e[d[2][i]]=i;
			}
			for(int i=1;i<=n;i++){
				if(c[1]<=n/2&&c[2]<=n/2&&c[3]<=n/2){
					sum+=a[i][1]; 
					c[b[a[i][1]]]++;
				}
				else{
					sum=0;
					sort(d[1]+1,d[1]+n+1,cmp);
					sort(d[2]+1,d[2]+n+1,cmp);
					for(int j=1;j<=n/2;j++){
						if(e[d[1][j]]==e[d[2][j]]&&d[2][j]!=d[2][j+1]){
							sum+=max(d[1][j]+d[2][n/2+1],d[2][j]+d[1][n/2+1]);
							d[2][n/2+1]=d[2][n/2+2],d[1][n/2+1]=d[1][n/2+1];
						}
						if(e[d[1][j]]==e[d[2][j]]&&d[2][j]==d[2][j+1]){
							if(d[1][j]>=d[2][j]){
								sum+=d[1][j];
								sum+=d[2][n/2+1];
								d[2][n/2+1]=d[2][n/2+2],d[1][n/2+1]=d[1][n/2+1];
							}
							else{
								sum+=d[2][j];
								sum+=d[1][n/2+1];
								d[2][n/2+1]=d[2][n/2+2],d[1][n/2+1]=d[1][n/2+1];
							}
						}
						if(e[d[1][j]]!=e[d[2][j]]){
							sum+=d[1][j];
							sum+=d[2][j];
						}
					}
			    }
			}
			cout<<sum<<"\n";
			sum=0;
		}
		else{
			sum=0;
			for(int i=1;i<=n;i++){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
			}
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j&&a[1][i]+a[2][j]>=sum){
						sum=a[1][i]+a[2][j];
					}
				}
			}
			cout<<sum<<"\n";
		}
	}
	return 0;
}