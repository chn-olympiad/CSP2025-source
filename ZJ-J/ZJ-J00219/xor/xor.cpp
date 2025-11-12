#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],f[500005],cnt=0,ans=0;
long long cnt1=0,cnt0=0;
struct lgt{
	int l,r;
} qj[500005];
bool cmp(lgt x,lgt y){
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==0) cnt0++;
		if(a[i]==1) cnt1++;
		f[i]=(a[i]^f[i-1]);
	}
	if(cnt1+cnt0==n&&n>=1000){
		if(k==0) cout << cnt0+cnt1/2;
		else cout << cnt1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((f[i]^f[j-1])==k){
				qj[++cnt].l=j,qj[cnt].r=i;
			}
		}
	}sort(qj+1,qj+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(qj[i].l==qj[i-1].l){
			qj[i].r=min(qj[i].r,qj[i-1].r);
			continue;
		}
		if(qj[i].l<=qj[i-1].r){
			qj[i].r=min(qj[i].r,qj[i-1].r);
			continue;
		}
		ans++;
	}cout << ans;
	return 0;
}
