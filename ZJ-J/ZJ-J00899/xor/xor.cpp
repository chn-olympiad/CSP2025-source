#include<bits/stdc++.h>
using namespace std;
int n,ans,t,p;
long long k,a[1000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		p=0;
		for(int j=i;j>t;j--){
			p=p^a[j];
			if(p==k){
				ans++;
				t=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}