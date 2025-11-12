#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int b[22]={};
int a[N],n,k,t;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			t++;
		}
	}
	cout<<t;
	return 0;
}
