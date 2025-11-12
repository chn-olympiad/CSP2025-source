#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,s=3,maxn=-1,sum=0,h=0;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	if(maxn*2<sum){
		h++;
	}
    cout<<h;
    return 0;
}
