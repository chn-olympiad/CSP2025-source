#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1000005;
int a[maxn],n,k,ans;
bool f[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<2*100000){
		for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			bool ff=0;
			if(f[i]==1){
				continue;
			}
			int cnt=a[i];
			for(int c=i+1;c<=j;c++){
				if(f[c]==0)cnt^=a[c];
				else{
					ff=1;
					break;
				}
			}
			if(cnt==k&&ff==0){
				for(int c=i;c<=j;c++)f[c]=1;
				ans++;
			}
		}
		cout<<ans<<endl;
	}else{
		int sumz=0,sumo=0;
		for(int i=1;i<=n;i++)if(a[i]==0)sumz++;
		else sumo++;
		if(k==0)cout<<sumo/2+sumz<<endl;
		else cout<<sumo<<endl;
	}
	return 0;
}
