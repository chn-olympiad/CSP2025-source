#include<bits/stdc++.h>
using namespace std;
int a[5010],q;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxx=-1;
	long long ans;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&q);
		a[q]++;
		if(q>maxx)maxx=q;
	}
	if(maxx==1){
		cout<<n-2;
		return 0;
	}
}
