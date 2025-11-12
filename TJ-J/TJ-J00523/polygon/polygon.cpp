#include<bits/stdc++.h>
using namespace std;
int n,a[6666],d,sum,cnt,dp[6666];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}	
	for(int i=3;i<=n;i++){
		for(int k=0;k<n;k++){
			sum=0;
			d=-1;
			for(int j=k;j<=k+i;j++){
				d=max(d,a[j]);
				sum+=a[j];
			}
			if(sum>d*2){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
