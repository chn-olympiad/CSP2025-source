#include<bits/stdc++.h>
using namespace std;

int a[500005];
int d[500005];
int t[500005];
int n , k , ans = 0;
bool f = 1;

void dg(int i , int j , int x){
	ans = max(ans , x);
	for(;i <= n;i++){
		for(;j <= n;j++){
			if((d[j]^d[i-1]) == k){
				dg(j+1 , j+1 , x+1);
			}
		}
	}
}

int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	
	cin >> n >> k;
	
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		d[i] = d[i-1] ^ a[i];
		t[a[i]]++;
		if(a[i] != 0 && a[i] != 1){
			f = 0;
		}
	}
	
	if(f == 0){
		dg(1 , 1 , 0);
		cout<<ans;
		return 0;
	}
	
	if(t[1] && !t[0]){
		ans = n/2;
		cout<<ans;
	}else if(t[1] && t[0]){
		if(k == 0){
			ans = t[1]/2 + t[0];
			cout<<ans;
		}else{
			cout<<t[1];
		}
	}
	
	return 0;
}
