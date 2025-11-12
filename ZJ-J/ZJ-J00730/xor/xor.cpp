#include<bits/stdc++.h>
using namespace std;
int n,k,flag=1,ans,f[100005],q[100005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>f[1];
	q[0]=0;
	q[1]=f[1];
	for(int i=2;i<=n;i++){
		cin>>f[i];
		q[i]=f[i]^q[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=flag;j<=i;j++){
			if((q[i]^q[j-1])==k){
				ans++;
				flag=i+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
