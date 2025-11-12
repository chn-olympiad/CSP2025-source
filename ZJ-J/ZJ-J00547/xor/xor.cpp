#include<bits/stdc++.h>
using namespace std;
long long int a[500010],ans[500010];
int use[16];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long int n,k,cnt=0,m=0;
	cin>>n>>k;
	//long long int cnt=0,m=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==1) cnt++;
		if(a[i]==0) m++;
	}if(k==1) cout<<cnt;
	else if(k==0) cout<<m+cnt/2;
	else if(k>=2) cout<<n-m-cnt;
	return 0;
}
