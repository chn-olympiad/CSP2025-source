#include<bits/stdc++.h>
using namespace std;
struct v{
	int l,r;
};
bool cmp(v x,v y){
	if(x.r<y.r) return 1;
	else return 0;
}
int n,k,leng=0;
long long a[600000];
long long cm[600000];
v s[600000];
int dp[600000]={0};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			s[++leng].l=i;
			s[leng].r=i;
		}
		cm[i]=a[i];
		for(int j=i+1;j<=n;j++){
			cm[j]=cm[j-1] xor a[j];
			if(cm[j]==k){
				s[++leng].l=i;
				s[leng].r=j;
			} 
		}
	}
	sort(s+1,s+leng,cmp);
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=1;j<=leng;j++){
			if(s[j].r<=i){
				dp[i]=max(dp[i],dp[s[j].l-1]+1);
			}	
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
