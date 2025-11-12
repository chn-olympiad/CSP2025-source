#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
long long a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	long long k;
	cin>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k)ans++;
	}
	cout<<ans;
	return 0;
}
