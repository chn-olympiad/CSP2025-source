#include<bits/stdc++.h>
using namespace std;
int a[500001],x[500001],v[1500000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,k,t=0,ans=0;
	for(int i=1;i<1500000;i++){
		v[i]--;
	}
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[i]=x[i-1]^a[i];
		if(v[k^x[i]]>=t){
			t=i;
			ans++;
		}
		v[x[i]]=i;
	}
	cout<<ans;
	return 0;
}
