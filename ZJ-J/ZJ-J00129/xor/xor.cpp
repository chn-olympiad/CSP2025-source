#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],sum[N];
struct ljy{
	int l,r;
}node[N];
int p=0;
bool cmp(ljy x,ljy y){
	if(x.r!=y.r)return x.r<y.r;
	return x.l>y.l;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	int f=0,f2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(a[i]!=1)f=1;
		if(a[i]!=0&&a[i]!=1)f2=1;
	}
	if(f==0&&k==0){
		cout<<n;
		return 0;
	}
	if(f2==0){
		if(k==1){
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)sum++;
			}
			cout<<sum;
			return 0;
		}
		else{
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0)sum++;
			}
			int sum2=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					if(a[i+1]!=1)continue;
					while(a[i+1]==1)i++;
					sum2++;
				}
			}
			cout<<sum+sum2;
			return 0;
		}
	}
	for(int x=1;x<=n;x++){
		for(int y=x;y<=n;y++){
			if(abs(sum[y]^sum[x-1])==k){
				node[++p].l=x;
				node[p].r=y;
			}
		}
	}
	sort(node+1,node+p+1,cmp);
	int ans=0;
	int mxr=0;
	for(int i=1;i<=p;i++){
		if(node[i].l>mxr){
			ans++;
			mxr=max(mxr,node[i].r);
		}
	}
	cout<<ans;
	return 0;
}

