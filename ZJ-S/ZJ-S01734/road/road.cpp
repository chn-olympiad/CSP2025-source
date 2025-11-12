#include<bits/stdc++.h>
using namespace std;
int n,m,k,p,q,d,sum;
struct st{
	int b,e,p;
};st a[1000010];
int b[12][10011];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>p>>q>>d;
		if(p!=q){
			a[i].b=min(p,q);a[i].e=max(p,q);a[i].p=min(a[i].p,d);
		}
	}
	if(k==0){//solve:c2c.p->min&&c2c's rd->OK,->num.of_rd->min;
		
	}
	else {
		for(int i=1;i<=k;i++){
			cin>>b[i][1];
			sum+=b[i][1];
			for(int j=2;j<=n+1;j++){
				cin>>b[i][j];
			}	
		}
		if(sum==0){
			cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
