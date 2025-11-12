#include <bits/stdc++.h>;
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int s=0,maxa=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
		maxa=max(maxa,a[i]);
	}
	if(s>2*maxa) cout<<1;
	else cout<<0;
	return 0;
}
