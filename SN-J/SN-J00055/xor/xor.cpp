#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FI(x) freopen(x".in","r",stdin)
#define FO(x) freopen(x".out","w",stdout)
int a[1000000],n,k;
signed main(){
	//×¢ÒâÌæ»»ºÍ×¢ÊÍ
	FI("xor");
	FO("xor");
	int c=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			c=1;
		}
	}
	if(c==0){
		cout<<1;
	}
	return 0;
}
