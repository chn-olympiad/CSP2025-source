#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
struct node{
	int l,r;
}t[N];
struct edge{
	int l,r;
};
int n,k,cnt,ans;
int a[N]; 
edge f[N][2];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int x=a[i];
		if(x==k)t[++cnt].l=i,t[cnt].r=i;
		else{
			for(int j=i+1;j<=n;j++){
			    x=(x^a[j]);
			    if(x==k){
			    	t[++cnt].l=i,t[cnt].r=j;
				}
			}
		}
	}
	f[1][0].l=0,f[1][0].r=0;
	f[1][1].l=1,f[1][1].r=t[1].r;
	for(int i=2;i<=cnt;i++){
		int fa=-1,ff=0,sa=-1,ss=0;
		for(int j=i-1;j>=1;j--){
			if(fa<f[j][0].l)fa=f[j][0].l,ff=j;
			if(fa<f[j][1].l)fa=f[j][1].l,ff=-j;
			if(sa<f[j][0].l&&t[i].l>f[j][0].r)sa=f[j][0].l,ss=j;
			if(sa<f[j][1].l&&t[i].l>f[j][1].r)sa=f[j][1].l,ss=-j;
		}
		if(sa==-1){
			f[i][1].l=1;
			f[i][1].r=t[i].r;
		}
		else {
			if(ss>0)f[i][1].l=f[ss][0].l+1;
			else f[i][1].l=f[-ss][1].l+1;
			f[i][1].r=t[i].r;
		}
		if(ff>0){
			f[i][0]=f[ff][0];
		}
		else f[i][0]=f[-ff][1];
		ans=max({f[i][0].l,f[i][1].l,ans});
	}
	cout<<ans;
	return 0;
}