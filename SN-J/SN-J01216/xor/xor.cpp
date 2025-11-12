#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[50005],ans[500005],cnt[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[i]=ans[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
			cnt[ans[j]-ans[i-1]]++;
	}
	cout<<cnt[k];
	return 0;
}
