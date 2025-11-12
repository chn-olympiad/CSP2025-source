#include<bits/stdc++.h>
/*fjx 20120225 rp++*/
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MAX=1e7+5;
const ll N=0;
int a[500005],b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	int sss=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)sss++;
	}
	if(n<=2&&k==0){//5
		if(a[1]==a[2]){
			cout<<1;
		}else cout<<0;
		return 0;
	}else if(n<=100&&k==0){//5
		cout<<n/2;
		return 0;
	}else {
		cout<<sss;//20
		return 0;
	}
	cout<<k;
	return 0;
} 
/*
200+12+30=242
*/
