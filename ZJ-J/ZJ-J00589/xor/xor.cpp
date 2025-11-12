#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005],sum[500005],ans=1;
struct node{
	int l,r;
}b[500005];
bool cmp(node x,node y){
	return x.l<y.l;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) sum[i]=a[i];
		else sum[i]=sum[i-1]^a[i];
		if(a[i]==k){
			b[ans]=(node){i,i};
			ans++;
		}
		if(sum[i]==k){
			b[ans]=(node){1,i};
			ans++;
		}
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			if((sum[i]^sum[j])==k){
				b[ans]=(node){i+1,j};
				ans++;
			}
		}
	}
	sort(b+1,b+ans,cmp);
	int p=0,cnt=0;
	for(int i=1;i<ans;i++){
		if(b[i].l>p){
			cnt++;
			p=b[i].r;
		}
	}
	cout<<cnt<<endl;
	return 0;
}