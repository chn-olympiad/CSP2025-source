#include<bits/stdc++.h>
using namespace std;
int js[3]={0,0,0},cs[100005],dc=0,n,maxn=0;
int main(){ 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int g;
	cin>>g;
	while(g--){
		int a[100005][3],ans=0;
		cin>>n;
		memset(a,0,sizeof(a));
		memset(cs,0,sizeof(cs));
		for(int i=0;i<n;i++){
			for(int u=0;u<3;u++){
				cin>>a[i][u];
				maxn=max(maxn,a[i][u]);
			}
		}
		for(int i=0;i<3;i++){
			for(int y=maxn;y>=0;y--){
				for(int oo=0;oo<n;oo++){
					if((a[oo][i]==y&&js[i]<n/2)&&cs[oo]!=6){
						ans+=a[oo][i];
						cs[oo]=6;
						js[i]++;
					}
				}
				
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
