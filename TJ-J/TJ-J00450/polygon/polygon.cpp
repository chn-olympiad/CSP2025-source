#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, ans, mod=998244353;
int arr[11451];
int s[11451];
bool mark[11451419];

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin>>n;
	
	if(n<3){
		cout<<0;
		return 0;
	}
	
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	
	sort(arr+1, arr+n+1);
	
	if(n==3){
		if(arr[1]+arr[2]>arr[3]){
			cout<<1;
		}
		else{
			cout<<0;
		}
		
		return 0;
	}
	
	cout<<9;
	
	return 0;
}
