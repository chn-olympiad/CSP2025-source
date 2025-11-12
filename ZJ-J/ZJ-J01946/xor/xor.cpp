#include<bits/stdc++.h>
#define ll long long
//#define ls(x) (x<<1)
//#define rs(x) (x<<1|1)
using namespace std;
const int N=500010,M=(1<<20)+5;
int n,k,ans;
int a[N];
int dp[N];
//int s[N];
//int f[M];
//int mx[N];
int w[N];
//inline int build(int u,int l,int r){
//	int v;
//	if(l==r){
//		v=a[l];
//	}else{
//		int mid=(l+r)>>1,v;
//		v=build(ls(u),l,mid) xor build(rs(u),mid+1,r);
//	}
//	if(v==k)
//		g.push_back((nn){l,r});
//	return v;
//}
//inline bool cmp(const nn x,const nn y){
//	if(x.l!=y.l) return x.l<y.l;
//	return x.r<y.r;
//}
//inline void bl(){
//	f[1]=(a[1]==k);
//	if(f[1])dp[1]=1;
//	for(int i=2;i<=n;i++){
//		for(int j=1;j<=i-1;j++){
//			if(f[j]){
//				dp[i]=max(dp[i],dp[j]+1)
//			}
//		}
//	}
//}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	cout<<(1<<20);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int r=1;r<=n;++r){
		int v=0;
		for(int l=r;l;--l){
			v^=a[l];
			if(v==k){
				w[r]=l;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(w[i]&&dp[w[i]-1]+1>dp[i])dp[i]=dp[w[i]-1]+1;
	}
//	for(int i=1;i<=n;i++){
//		int v=k^a[i];
//		if(a[i]==k){
//			dp[i]=dp[i-1]+1;
//		}else if(f[v]){
//			dp[i]=dp[f[v]-1]+1;
//		}
//		dp[i]=max(dp[i-1],dp[i]);
//		f[a[i]]=i;
//	}
//	ans=mx[n];
//	bl();
//	build(1,1,n);
//	sort(g.begin(),g.end(),cmp);
//	for(int i=0;i<(int)g.size();++i){
//		int l=g[i].l,r=g[i].r;
//		//...
////		cout<<l<<" "<<r<<'\n';
//		//...
//		dp[r]=max(dp[r],dp[l-1]+1);
//	}
//	for(int i=1;i<=n;++i)ans=max(ans,dp[i]);
//	printf("%d",ans);
	printf("%d",dp[n]);
	return 0;
}
