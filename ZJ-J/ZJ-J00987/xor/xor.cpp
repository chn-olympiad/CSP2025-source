#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-f;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
int n,k,a[N],dp[N];
int check(int l,int r){
//	if(l==r)return a[l];
	int t=a[l];
	for(int i=l+1;i<=r;i++){
		t=(t^a[i]);
	}
	return t;
}
int pianfen,reta,retb;
bool hebing[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=1&&pianfen==0)pianfen=1;
		if(a[i]>1)pianfen=-1;
		if(a[i]==1)reta++;
		if(a[i-1]==1&&a[i]==1&&hebing[i-1]==false){
			retb++;
			hebing[i-1]=hebing[i]=true;
		}
	}
//	cout<<pianfen;
	if(pianfen!=-1){
		if(pianfen==0){
			if(k==1){
				cout<<n;
			}else{
				cout<<n/2;
			}
		}else{
			if(k==1)cout<<reta;
			else cout<<retb+n-reta;
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
//	if(k==0){
//		cout<<n;
//		fclose(stdin);
//		fclose(stdout);
//		return 0;
//	}
//	a[n+1]=a[n+2]=a[n+3]=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i]=max(dp[i],dp[j]);
			if(check(j,i)==k){
//				printf("%d %d: %d to ",j,i,dp[i]);
				dp[i]=max(dp[i],dp[j]+1);
//				printf("%d\n",dp[i]);
			}
		}
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

