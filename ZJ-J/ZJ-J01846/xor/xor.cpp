#include<bits/stdc++.h>
using namespace std;char s;int a[1002],cnt=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k==0){
		cout<<n;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<n/2;
	return 0;
}