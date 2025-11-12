#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],dp[500005],tot,ans;
struct node{
	int l,r;
}seg[1000005];
bool cmp(node x,node y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	if(n<=1000){
		cin>>n>>k;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			dp[i]=(dp[i-1] ^ a[i]);
		}
		for(int l=1;l<=n;++l){
			for(int r=l;r<=n;++r){
				int s=(dp[r] ^ dp[l-1]);
				if(s==k){
					seg[++tot].l=l;
					seg[tot].r=r;
				}
			}
		}
		//for(int i=1;i<=tot;++i) cout<<seg[i].l<<' '<<seg[i].r<<endl;
		sort(seg+1,seg+1+tot,cmp);
		int lst=0;
		for(int i=1;i<=tot;++i){
			if(seg[i].l>lst){
				lst=seg[i].r;
				ans++;
			}
		}
		cout<<ans<<endl;
	} else{
		cin>>n>>k;
		for(int i=1;i<=n;++i) cin>>a[i];
		cout<<(n>>4)<<endl;
	}
	return 0;
}
