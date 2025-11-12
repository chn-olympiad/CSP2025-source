#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m, cnt, tot;
ll arr[114];

bool cmp(ll a, ll b){
	return a>b;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin>>n>>m;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>arr[++cnt];
		}
	}
	
	ll k = arr[1];
	sort(arr+1, arr+cnt+1, cmp);
	
	for(int i=1; i<=cnt; i++){
		if(arr[i] == k){
			tot = i;
			break;
		}
	}
	
	if((tot/n+1)%2 == 1){
		cout<<(tot%n==0 ? tot/n : tot/n+1)<<" "<<(tot%n==0 ? n : tot%n);
	}
	else{
		cout<<(tot%n==0 ? tot/n : tot/n+1)<<" "<<n-(tot%n==0 ? 1 : tot%n)+1;
	}
	
	return 0;
}
