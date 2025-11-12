#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[500001],x;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		a[i]=(a[i-1]^x);
	}
	for(int i=1;i<=n;i++){
		int t=i-1;
		while(t>=0 and (a[t]^a[i])!=m) t--;
		if(t>=0) b[i]=max(b[i-1],b[t]+1);
		else b[i]=b[i-1];
	}
	printf("%d",b[n]);
	return 0;
}
