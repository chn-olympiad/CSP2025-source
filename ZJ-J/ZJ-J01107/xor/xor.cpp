#include<bits/stdc++.h>
using namespace std;
int n,k,a[50005][100],tot[100],g[1005],dp[10005],b[10005];
int sum[10005];
int qq,pp;
bool f;
int yh(int x,int y){
	int f,f1,vv[105],cc[105],qq1,qq2;
	memset(vv,0,sizeof vv);
	memset(cc,0,sizeof cc);
	qq1=0,qq2=0;
	f=0,f1=0;
	if(x==0){
		vv[++qq1]=0;
		f=1;
	} 
	if(y==0){
		cc[++qq2]=0;
		f1=1; 
	}
	
	if(!f){
		while(x!=0){
			vv[++qq1]=x%2;
			x/=2;
		}
	}
	if(!f1){
		while(y!=0){
			cc[++qq2]=y%2;
			y/=2;
		}
	}
	int h=min(qq1,qq2);
	for(int i=1;i<=h;i++){
		if(vv[i]==0&&cc[i]==0) g[i]=0;
		else if(vv[i]==0&&cc[i]==1) g[i]=1;
		else if(vv[i]==1&&cc[i]==0) g[i]=1;
		else g[i]=0;
	}
	long long ans=0;
	for(int i=max(qq1,qq2);i>h;i--){
		if(qq1>qq2) ans=ans*2+vv[i];
		else if(qq2>qq1) ans=ans*2+cc[i];
	}
	for(int i=h;i>=1;i--){
		ans=ans*2+g[i];
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	f=0;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		b[i]=x;
		if(x!=1) f=1;
		if(x==0){
			tot[i]=1;
			a[i][tot[i]]=0;
			continue;
		}
		while(x!=0){
			tot[i]++;
			a[i][tot[i]]=x%2;
			x/=2;
		}
	}
	if(!f){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int p=0;
		for(int lz=1;lz<=i;lz++) p=max(p,tot[lz]);
		for(int t=1;t<=p;t++){
			int tot1=0,tot2=0;
			for(int j=1;j<=i;j++){
				if(tot[j]<t) continue;
				if(a[j][t]==0) tot1++;
				else tot2++;
			}
			if(tot2%2==0) g[t]=0;
			else g[t]=1;
		}
		for(int t=p;t>=1;t--) sum[i]=sum[i]*2+g[t];
	}
	sum[0]=0;
	for(int i=1;i<=n;i++)
		if(sum[i]==k) dp[i]=1;
	for(int r=1;r<=n;r++){
		for(int l=1;l<=r;l++){
			if(r==l&&b[r]==k){
				dp[r]=max(dp[r],dp[l-1]+1);
				continue;
			}
			if(yh(sum[r],sum[l-1])==k) dp[r]=max(dp[r],dp[l-1]+1);
			else dp[l]=max(dp[l],dp[l-1]);
		}
	}
	cout<<dp[n];
	return 0;
}
