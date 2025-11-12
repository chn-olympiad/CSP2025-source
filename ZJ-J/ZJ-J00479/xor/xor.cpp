#include<bits/stdc++.h>
using namespace std;
bool tong[2000005];
int n,k,a[500005],pre[500005],ans;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++)scanf("%d",&a[i]),pre[i]=pre[i-1]^a[i];
	int l=0;
	tong[0]=1;
	for(int i=1; i<=n; i++) {
		if(tong[pre[i]^k]) {
			ans++;
			for(int j=l;j<i;j++)tong[pre[j]]=0;
			l=i;
		}
		tong[pre[i]]=1;
	}
	cout<<ans;
	return 0;
}
