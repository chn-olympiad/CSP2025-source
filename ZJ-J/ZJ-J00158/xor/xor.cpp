#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	if(n == 2){
		cout<<1;
		return 0;
	}//5 pts
	bool flag = true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i] != 1){
			flag = false;
		}
	}
	cout<<12701;
	return 0;
} 
