#include<bits/stdc++.h>
using namespace std;

int n,m,x,ans=1;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> x;
	for(int i=2;i<=n*m;i++){
		int tmp;
		cin >> tmp;
		if(x<tmp) ans++;
	}

	cout << (ans-1)/n+1 << ' ';
	if(ans%n){
		if(((ans-1)/n+1)&1) cout << ans%n;
		else cout << n+1-ans%n;
	}
	else{
		if(((ans-1)/n+1)&1) cout << n;
		else cout << 1;
	}
	
	return 0;
} 
