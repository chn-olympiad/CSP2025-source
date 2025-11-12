#include <bits/stdc++.h>
#define N 1000005
using namespace std;
int T,n,a[N][4],ans,q,sm,i;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
        for(int i=1;i<=n;++i){
        	for(int j=1;j<=3;++j)cin>>a[i][j];
			for(int i=1;i<=3;++i)while(!q[i].empty())q[i].pop();
			for(int i=1;i<=n,++i){
				int x=0;
				for(int j=1;i<=3;++jif(a[i][j]>a[i][x])x=j;
					if(q[x].size()==n/2)ans+=q[x].top(),q[x].pop();
					for(int j=1;j<=3:++j)if(j!=x)sm=max(sm,a[i][j]);
					q[x].push(sm-a[i][j]);ans+a[i][j];
					
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
