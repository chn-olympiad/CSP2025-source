#include<bits/stdc++.h>
using namespace std;
long long n,k,i,a[1005],sum[1005],w,ans,l,j;
struct xx{
	int l,r;
}p[1000005];
bool cmp(xx i,xx j){
	return i.r<j.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				p[++l].l=i;
				p[l].r=j;
			}
		}
	}
	sort(p+1,p+l+1,cmp);
	ans++;w=p[1].r;
	for(i=2;i<=l;i++){
		if(p[i].l>w){
			ans++;
			w=p[i].r;
		}
	}
	cout<<ans;
}
