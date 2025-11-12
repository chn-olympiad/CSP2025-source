#include<bits/stdc++.h>
using namespace std;
int dp[2010][2010],n,k,a[2010];
inline int red(){
	char c=getchar();int x=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x*=10;x+=c-'0';c=getchar();
	}
	return x;
}
bool yh(int l,int r){
	int ans=a[l];
	for(int i=l+1;i<=r;i++)ans^=a[i];
	if(ans==k)return 1;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	n=red(),k=red();
	for(int i=1;i<=n;i++){
		a[i]=red();
		dp[i][1]=a[i]==k?1:0;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int l=j,r=i+j-1;//i:qu jian long  j:qu jian start	
			for(int e=1;e<=r-l;e++){
				dp[j][i]=max(dp[j][i],dp[j][e]+dp[j+e][i-e]);
			}
			if(dp[j][i]==0)dp[j][i]+=yh(l,r);
		}
	}
	cout<<dp[1][n];
	return 0;	
}
