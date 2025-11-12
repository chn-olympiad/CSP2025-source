#include<bits/stdc++.h>
using namespace std;

long long n,k,a[500005],b[500005],dp[500005],i,j,s,sum,u;
bool v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	v=1;
	for(i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
		if(a[i]>1){
			v=0;
		}
		else{
			if(a[i]==1){
				s++;
				sum++;
				if(sum%2==0){
					u++;
				}
			}
			else{
				u++;
				sum=0;
			}
		}
	}
	if(v==1&&n>5000){
		if(k==1){
			cout<<s;
		}	
		else{
			if(k==0){
				cout<<u;
			}
			else{
				cout<<"0";
			}
		}
		return 0;
	}
	b[0]=0;
	dp[0]=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
//			cout<<(b[i]^b[j-1])<<" "<<i<<" "<<j<<"\n";
			if((b[i]^b[j-1])==k){
				dp[i]=max(dp[i],dp[j-1]+1);
			}
			else{
				dp[i]=max(dp[i],dp[j-1]);
			}
		}
//		cout<<"\n";
	}
	cout<<dp[n];
	return 0;
}
/*
#Shang4Shan3Ruo6Shui4
*/