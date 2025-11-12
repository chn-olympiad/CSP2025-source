#include<bits/stdc++.h>
using namespace std;
int n,a[5010],b[5010],ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+b[i];
	}
	for(int i=n;i>=1;i--){
		if(b[i-1]>a[i]) ans++;
	}
	cout<<ans;
}