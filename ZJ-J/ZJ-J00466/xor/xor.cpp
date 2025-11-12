#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500010],b[500010],ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=(b[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((b[i-1]^b[j])==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

