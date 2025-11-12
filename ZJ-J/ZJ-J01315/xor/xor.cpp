#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],t[2000001],cnt,siz,dp[2000001];
void build(int p,int l,int r){
	if(l==r){
		t[p]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p]=t[p*2]^t[p*2+1];
}
int query(int p,int l,int r,int x,int y){
	if(l>=x&&r<=y){
		return t[p];
	}
	int ans=0,mid=(l+r)>>1;
	if(mid>=x){
		ans^=query(p*2,l,mid,x,y);
	}if(mid<y){
		ans^=query(p*2+1,mid+1,r,x,y);
	}
	return ans;
}
struct node{
	int l,r;
}ans[2000001];
bool cmp(node x,node y){
	if(x.l==y.l){
		return x.r<y.r;
	}
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	for(int i=1;i<=n;i++){
		for(int j=1;j+i-1<=n;j++){
			if(query(1,1,n,j,j+i-1)==k){
				siz++;
				ans[siz].l=j;
				ans[siz].r=j+i-1;
			}
		}
	}
	sort(ans+1,ans+siz+1,cmp);
	for(int i=1;i<=siz;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(ans[j].r<ans[i].l){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		cnt=max(cnt,dp[i]);
	}
	printf("%d",cnt);
	return 0;
}
