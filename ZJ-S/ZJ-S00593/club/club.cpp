#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll a[N][4],vis[N],ct[11];
struct node{
	ll f1,f2,g1,g2,id;
}b[N];
bool cmp(node x,node y){
	return x.f1-x.f2>y.f1-y.f2;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=3;i++) ct[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++) b[i].id=i;
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				b[i].f1=a[i][1];
				b[i].f2=max(a[i][2],a[i][3]);
				b[i].g1=1;
				if(a[i][2]>a[i][3]) b[i].g2=2;
				else b[i].g2=3;
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				b[i].f1=a[i][2];
				b[i].f2=max(a[i][1],a[i][3]);
				b[i].g1=2;
				if(a[i][1]>a[i][3]) b[i].g2=1;
				else b[i].g2=3;
			}else{
				b[i].f1=a[i][3];
				b[i].f2=max(a[i][1],a[i][2]);
				b[i].g1=3;
				if(a[i][1]>a[i][2]) b[i].g2=1;
				else b[i].g2=2;
			}
		}
		ll sum=0;
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(ct[b[i].g1]<n/2){
				sum+=b[i].f1;
				ct[b[i].g1]++;
			}else{
				sum+=b[i].f2;
				ct[b[i].g2]++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
