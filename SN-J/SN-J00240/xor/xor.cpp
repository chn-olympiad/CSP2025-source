#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500001],num=0,b[500001];
int x(int l,int r){
	long long cnt=0;
	for(int i=l;i<=r;i++){
		cnt^=a[i];
	}return cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=b[i-1];
		for(int j=num+1;j<=i;j++){
			if(x(j,i)==k){
				b[i]=b[i-1]+1;
				num=i;
				break;
			}
		}
	}cout << b[n];
	return 0;
}
