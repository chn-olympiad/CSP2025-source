#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) (x&(-x))

const int N=5e3+10,mod=998244353;

int dp[N],n,arr[N],maxa;

struct Tree{
	int l,r,sum;
}tre[N*4];

void build_tre(int x,int l,int r){
	//cout<<x<<' '<<l<<' '<<r<<endl;
	tre[x].l=l;
	tre[x].r=r;
	if(l==r){
		tre[x].sum=dp[l];
		return ;
	}
	int mid=(l+r)>>1;
	build_tre(x<<1,l,mid);
	build_tre((x<<1)+1,mid+1,r);
	tre[x].sum=tre[x<<1].sum+tre[(x<<1)+1].sum;
	return ;
}

void change(int x,int p,int val){
	if(tre[x].l==p && tre[x].r==p && tre[x].l==tre[x].r){
		tre[x].sum+=val;
		tre[x].sum%=mod;
		return ;
	}
	int mid=(tre[x].l+tre[x].r)>>1;
	if(p<=mid){
		change(x<<1,p,val);
	}else{
		change((x<<1)+1,p,val);
	}
	tre[x].sum=(tre[x<<1].sum+tre[(x<<1)+1].sum)%mod;
	return ;
}

int query(int x,int l,int r){
	if(tre[x].l>=l && tre[x].r<=r){
		return tre[x].sum;
	}
	int res=0,mid=(tre[x].l+tre[x].r)>>1;
	if(l<=mid){
		res+=query(x<<1,l,r);
		res%=mod;
	}
	if(r>mid){
		res+=query((x<<1)+1,l,r);
		res%=mod;
	}
	return res;
}
/*
void add(int x,int p){
	for(;x<=N;x+=lowbit(x)){
		tre[x]+=p;
	}
	return ;
}

int ask(int x){
	int res=0;
	for(;x>0;x-=lowbit(x)){
		res+=tre[x];
	}
	return res;
}
*/

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		maxa=max(maxa,arr[i]);
	}
	sort(arr+1,arr+1+n);
	dp[0]=1;
	build_tre(1,0,maxa+1);
	int ans=0;
	
	for(int i=1;i<=n;i++){
		ans+=query(1,arr[i]+1,maxa+1);
		int last=dp[maxa+1];
		dp[maxa+1]+=query(1,maxa+1-arr[i],maxa+1);
		dp[maxa+1]%=mod;
		change(1,maxa+1,dp[maxa+1]-last);
		for(int j=maxa;j>=1;j--){
			if(j-arr[i]<0)break;
			last=dp[j];
			dp[j]+=dp[j-arr[i]];
			dp[j]%=mod;
			change(1,j,dp[j]-last);
		}
		ans%=mod;
	}
	cout<<ans;
	
	return 0;
}
