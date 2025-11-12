#include<bits/stdc++.h>
using namespace std;
int a[5005];
int b[5005][5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int maa=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maa=max(maa,a[i]);
	}
	if(maa==1){
		long long ans=0;
		b[1][1]=1;
		for(int i=2;i<=n+1;i++){
			for(int j=1;j<=i;j++){
				b[i][j]=b[i-1][j-1]+b[i-1][j];
				b[i][j]%=998244353;
			}
		}
		for(int i=3;i<=n;i++){
			ans+=b[n+1][i+1];
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
    int sum=1;
    int ans=0;
    for(;sum<pow(2,n);sum++){
    	int i=1;
    	int s=0;
    	int ma=0;
    	int su=sum;
    	while(su>0){
    		if((su&1)==1){
    			s+=a[i];
    			ma=max(ma,a[i]);
			}
			su=su>>1;
			i++;
		}
		if(ma*2<s){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}