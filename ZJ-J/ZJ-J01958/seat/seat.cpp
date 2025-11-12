#include<bits/stdc++.h>
using namespace std;
int n,m;
int a,x,ans=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<n*m;i++){
		cin>>x;
		if(x>a)ans++;
	}
	cout<<(ans/n)+1<<' '<<ans%n;
	return 0;
}