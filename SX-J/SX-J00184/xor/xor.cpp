#include<bits/stdc++.h>
using namespace std;
int a[1000005];
string s[1000005];
string ss[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)sum++;
	}
	cout<<sum;

	return 0;
}