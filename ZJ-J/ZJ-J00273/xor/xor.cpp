#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000005],t,ans=0,r;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
    	cin>>t; a[i]=a[i-1]^t;
	}
	//得到前缀异或  help 我真不会 
	//for(long long i=1;i<=n;i++) cout<<a[i]<<endl;
	for(long long i=1;i<=n;i++){
		if(i<=r) continue;
		for(long long j=i;j<=n;j++){
			long long t=a[j]^a[i-1];
			//cout<<i<<' '<<j<<' '<<a[j]<<' '<<a[i-1]<<' '<<t<<endl;
			if(t==k){
				ans++;
				r=max(r,j);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
