#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005],s[500005];
int v[1050000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int j=0;
	for(int i=0;i<=n;i++){
		if(v[k^s[i]]){
			ans++;
			while(j<i){
				v[s[j++]]--;
			}
		}
		v[s[i]]++;
	}
	cout<<ans;
	return 0;
}
