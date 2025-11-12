#include<bits/stdc++.h>
using namespace std;
const int M=5e5;
int n,a[M];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int c=a[1];
	for(int i=2;i<=n;i++){
		if(c|a[i]){
			c=c|a[i];
		}
	}
	cout>>c;
	return 0;
}
