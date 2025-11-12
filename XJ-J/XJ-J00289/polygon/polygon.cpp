#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt,maxx=-1;
	cin>>n;
	if(n==3){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			cnt+=a[i];
			maxx=max(a[i],maxx);
		}
		if(cnt>maxx*2){
			cout<<1<<endl;
			return 0;
		}	
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
		maxx=max(a[i],maxx);
	}
	cout<<n-1;
	return 0;
}
