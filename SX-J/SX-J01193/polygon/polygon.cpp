#include<bits/stdc++.h>
using namespace std;
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<3){
		cout<<0;
		return 0;
	}
	int sum=0,maxn=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(sum>max*2) cout<<1;
	else cout<<0;
	return 0;
}
