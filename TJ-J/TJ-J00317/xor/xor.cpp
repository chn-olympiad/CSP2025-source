#include <bits/stdc++.h>
using namespace std;
int n,k,a[500010],s[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int sum=0,f=0;
	for (int i=1;i<=n;i++){
		f^=a[i];
		if (f==k){
			f=0;
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
