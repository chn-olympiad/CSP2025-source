#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,m,k;
int u[N],v[N],w[N],f[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i]; 
	}
	for(int j=1;j<=2*n;j++){
		cin>>f[j];
	}
	if(m==n-1){
		cout<<n-1<<'\n';
		return 0£» 
	}
	for(int i=1;i<=n;i++){
			px(x[i].a,x[i].b,x[i].c);
			cnt=max(x[i].a,x[i].b,x[i].c);
			if(cnt==x[i].a&&cnt==x[i].b&&cnt==x[i].c){
				cnt3++;
			}else{
				if(cnt==x[i].a){
					cnt1++;
					break;
				}
				if(cnt==x[i].b){
					cnt2++;
					break;
				}
				if(cnt==x[i].c){
					cnt3++;
					break;
				}
			}
			ans=ans+cnt;
		}
		if(spe(cnt1==true)&&spe(cnt1==true)&&spe(cnt1==true)){
			cout<<ans<<'\n';
		}
	return 0;
}
