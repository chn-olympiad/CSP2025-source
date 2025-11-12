#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],x[500005],f[500005],maxn[500005];
map<int,int> t;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++) scanf("%d",a+i),x[i]=x[i-1]^a[i];
	for (int i=1;i<=n;i++){
		if (t.count(k^x[i])) f[i]=maxn[t[(k^x[i])]]+1;
		maxn[i]=max(maxn[i-1],f[i]);
		t[x[i]]=i;
	}
	cout<<maxn[n]<<endl;
	return 0;
}

