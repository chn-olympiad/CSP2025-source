#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e4+10;
int t,n,a[MAXN][5],maxn=-1,flag[5]= {0},ans,p[MAXN];

int main() {
	freopen("club.in","w",stdin);
	freopen("club.out","r",stdout);
	cin>>t;
	int w,w2;
	while(t--) {
		cin>>n;
		ans=0;
		for(int i=1; i<=n; i++) {
		
			for(int j=1; j<=3; j++) {
				flag[j]=0;
				cin>>a[i][j];
				if(a[i][j]>=maxn) {
					if(flag[j]<=n/2) {
						maxn=a[i][j];
						w=j;
					} else {
						flag[j]--;
						maxn=-10086;
						a[i][j]=-2;
						for(int x=1; x<=n; x++) {
							for(int y=1; y<=3; y++) {
								if(a[x][y]>=maxn && flag[y]<=n/2) {
									maxn=a[x][y];
									w=y;
									continue;
								}
							}
						}
					}
				}
				flag[w]+=1;
			}
			
			ans+=a[i][w];
//			if(a[i][1]==0&&a[i][3]==0){
//					ans-=					
//			}
			
		}
		cout<<ans;
	}
	return 0;
}





