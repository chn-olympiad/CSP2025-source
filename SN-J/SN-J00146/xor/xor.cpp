#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FI(x) freopen(x".in","r",stdin)
#define FO(x) freopen(x".out","w",stdout)
int n,k,a[500005],onesum,zerosum,flag,oneliansum;

signed main(){
	FI("xor");
	FO("xor");
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			onesum++;
			if(flag==1) oneliansum++,flag=0;
			else flag=1;	
		}else if(a[i]==0) zerosum++,flag=0;
	}
	if(k==1) cout<<onesum;
	else if(k==0) cout<<zerosum+oneliansum;
	return 0;
}
