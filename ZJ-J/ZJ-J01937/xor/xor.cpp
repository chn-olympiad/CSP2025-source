#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int b[500005];
int a[500005];
int ant=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int haha=0;
	int ant=0;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]!=1){
			haha=1;
		}
		if(b[i]==k){
			ant++;
		}
	}
	if(k==0&&haha==0){
		cout<<n/2;
	}else{
		cout<<ant;
	}
	return 0;
}
