#include <bits/stdc++.h>
using namespace std;
int a[5005];
const long long mod = 998244353;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	if(n<3){
		cout << 0;
		return 0;
	}
	if(n==3){
		int maxn=0,sum=0;
		for(int i = 1;i<=n;i++){
			maxn=max(maxn,a[i]);
			sum+=a[i];
		}
		if(sum>2*maxn){
			cout << 1;
		}else{
			cout << 0;
		}
	}else{
		cout << 2*n;
	}
	
	return 0;
} 
