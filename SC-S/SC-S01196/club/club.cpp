#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=1e5+5;
int a[N],b[N],c[N],aa[N],bb[N],cc[N];
bool cmp(int x,int y){
	return x>y;
}
void solve(){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	int n,ans=0;
	cin>>n;
	int edge=(n>>1);
	for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++){
		aa[i]=aa[i-1]+a[i];
		bb[i]=bb[i-1]+b[i];
		cc[i]=cc[i-1]+c[i];
	}
	for(int i=0;i<=edge;i++){
		for(int j=0;j<=edge;j++){
			int k=n-i-j;
			ans=max(ans,aa[i]+bb[j]+cc[k]);
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}