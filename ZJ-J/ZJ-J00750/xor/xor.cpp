#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],ans,f[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	int v = 0;
	for(int i = 1;i <= n;i++){
		if(a[i] == k){
			ans++;
			v = 0;
			continue;
		}
		f[++v] = a[i];
		for(int j = 1;j < v;j++){
			f[j] = f[j] ^ a[i];
			if(f[j] == k){
				ans++;
				v = 0;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}