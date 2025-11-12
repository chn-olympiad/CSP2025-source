#include<bits/stdc++.h>
using namespace std;
struct ly{
	long long a,b,c,maxx;
}p[6][100001];
long long i,j,n[6],u[6][3]={0},t,ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>n[i];
		for(j=1;j<=n[i];j++){
			cin>>p[i][n[i]].a>>p[i][n[i]].b>>p[i][n[i]].c;
			for(int e=1;e<=3;e++){
				if(p[i][n[i]].a>p[i][n[i]].b&&p[i][n[i]].a>p[i][n[i]].c&&n[i]/2>u[i][1]+1){
					p[i][n[i]].maxx=p[i][n[i]].a;
					u[i][1]++;
				}
				if(p[i][n[i]].b>p[i][n[i]].a&&p[i][n[i]].b>p[i][n[i]].c&&n[i]/2>u[i][2]+1){
					p[i][n[i]].maxx=p[i][n[i]].b;
					u[i][2]++;
				}
				if(p[i][n[i]].c>p[i][n[i]].a&&p[i][n[i]].c>p[i][n[i]].b&&n[i]/2>u[i][3]+1){
					p[i][n[i]].maxx=p[i][n[i]].c;
					u[i][3]++;
				}
			}
		}
	}
	for(i=1;i<=t;i++){
		ans=0;
		for(j=1;j<=n[i];j++){
			ans+=p[i][n[i]].maxx;
		}
		cout<<ans<<endl;
	}
	return 0;
}