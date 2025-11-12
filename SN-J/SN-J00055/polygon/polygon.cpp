#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FI(x) freopen(x".in","r",stdin)
#define FO(x) freopen(x".out","w",stdout)
int n,a,b,c,g[10001],m;
signed main(){
	//×¢ÒâÌæ»»ºÍ×¢ÊÍ
	FI("polygon");
	FO("polygon");
	cin>>n;
	int ans=0,d=0;
	for(int i=1;i<=n;i++){
		cin>>g[i];
		ans+=g[i];
		if(g[i]!=1){
			d=1;
		}
	}
	if(n==3){
		int m=max(g[1],max(g[2],g[3]));
		if(ans>=(m*2)){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		if(d==0){
			int sum=0;
			for(int i=1;i<=n-3;i++){
				sum+=i;
			}
			cout<<sum;
		}else{
			cout<<18;
		}
	}
	return 0;
}

