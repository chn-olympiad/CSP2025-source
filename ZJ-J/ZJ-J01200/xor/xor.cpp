#include <bits/stdc++.h>
using namespace std;
long long n,k,i,x,ma,ans,a[500010],b[500010],f[2000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<=n;i++) b[i]=b[i-1]^a[i];
	for (i=1;i<=200000;i++) f[i]=-2;
	f[0]=0;ma=-1;
	for (i=1;i<=n;i++){
		x=k^b[i];
		if (f[x]>=ma){
			f[x]=-2;ma=i;
			ans++;
		}
		f[b[i]]=i;
	}
	cout<<ans;
	return 0;
}
