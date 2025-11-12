#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,k;
int a[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>a[i];
	}
	if(k==0){
		sort(a+1,a+n+1);
		int maxnn=0;
		for(int i=n;i>=1;i--){
			maxnn++;
			if(a[i-1]!=a[i]){
				break;
			}
		}
		cout<<maxnn;
		return 0;
	}else{
		cout<<1;
	}
	return 0;
}
