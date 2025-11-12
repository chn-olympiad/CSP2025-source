#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[1000];
	int cnt=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(k==0 && a[i]==0) cnt++;
	}
	cout<<cnt;
}