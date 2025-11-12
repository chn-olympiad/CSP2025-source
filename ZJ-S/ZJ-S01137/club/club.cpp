#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
#define ll long long
const int MAXN=1e5+5;
ll T,n,anss,f1,x[MAXN],y[MAXN],z[MAXN];
int dfs(ll j,ll a,ll b,ll c){
	if(j>=n){
		return 0;
	}
	if(j==n-1){
		return max(x[j],max(y[j],z[j]));
	}
	ll ma=0;
	if(a<n/2){
		ma=max(ma,dfs(j+1,a+1,b,c)+x[j]);
	}
	if(b<n/2){
		ma=max(ma,dfs(j+1,a,b+1,c)+y[j]);
	}
	if(c<n/2){
		ma=max(ma,dfs(j+1,a,b,c+1)+z[j]);
	}
	return ma;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		f1=1;
		for(int i=0;i<n;i++){
			cin>>x[i]>>y[i]>>z[i];
			if(y[i]!=0||z[i]!=0){
				f1=0;
			}
		}
		if(f1){
			anss=0;
			for(int i=0;i<n;i++){
				anss+=x[i];
			}
		}else{
			anss=dfs(0,0,0,0);
		}
		cout<<anss<<"\n";
	}
	return 0;
}
