#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
int dif[505];
int cnt,n,m,ans[505];
struct node{
	int peo;
	bool r=1;
}c[505];
bool cmp(node x,node y){
	return x.peo<=y.peo;
}
void solve(){
	int x=1;
	for(int i=1;i<=n;i++){
		for(int j=x;j<=n;j++){
			if(c[j].r){
				if(!dif[i]){
					c[j].peo=0;
					for(int k=1;k<=n;k++){
						c[k].peo--;
						if(c[k].peo<0){
							c[k].r=0;
							x++;
							cnt--;
							for(int g=k;g<=n;g++){
								ans[g]--;
							}
						}
					}	
				}
			else{
				m--;
				c[j].r=0;
				for(int g=j;g<=n;g++){
					ans[g]--;
				}
			}  
		}
		}	
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int u;
	ll ans1=1,ert=998244353;
	cnt=n;
	scanf("%d",&u);
	for(int i=n;i>=1;i--){
		dif[i]=u%10;
		u=u/10;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i].peo;
		c[i].peo++;
		ans[i]=n;
	}
	sort(c+1,c+m+1,cmp);
	solve();
	for(int i=1;i<=n;i++){
		if(ans[i]) ans1*=ans[i];
		ans1%=ert;
	}
	cout<<ans1;
	return 0;
}