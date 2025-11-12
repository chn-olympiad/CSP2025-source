#include<bits/stdc++.h>
using namespace std;
int a[1005];
int c[1005][1005];
int n,k;
int tent(int m){
	int ret=0,wei=1;
	while(m>=1){
		ret+=wei*(m%2);
		m/=2;
		wei*=10;
	}
	return ret;
}
int twot(int m){
	int ret=0,wei=1;
	while(m>=1){
		ret+=wei*(m%10);
		m/=10;
		wei*=2;
	}
	return ret;
}
int x(int a,int b){
	a=tent(a),b=tent(b);
	int wei=1,ret=0;
	while(a>=1||b>=1){
		int a1=a%10,b1=b%10;
		if(a1!=b1){
			ret+=wei*1;
		}
		a/=10;
		b/=10;
		wei*=10;
	}
	return twot(ret);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i][1]=a[i];
	} 
	for(int j=2;j<=n;j++){
		for(int i=1;i<=n-j+1;i++){
			c[i][j]=x(c[i][j-1],a[i+j-1]);
		}
	}
	int ans[1005]={0},sum=1,last[1005]={0};
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n-j+1;i++){
			if(c[i][j]==k){
				
				for(int p=1;p<=sum;p++){
					if(i>=last[p]){
						last[p]=i+j;
						ans[p]++;
						continue;
					}
					if(sum==p){
						last[++sum]=i+j;
						ans[sum]=1;	
						break;
					}
					
				}
			}
		}
	}
	sort(ans+1,ans+sum+1);
	cout<<ans[sum];
	return 0;
}
