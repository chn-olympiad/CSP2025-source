#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],ans,anss,ansa,an;
bool f = true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(long long i = 0;i<n;i++){
		cin>>a[i];
		if(a[i]>=2) f = false;
		if(a[i] == 1) an++;
	}
	if(f&&m == 1){
		cout<<an;
		return 0;
	}
	if(f&&m == 0){
		cout<<n-an;
		return 0;
	}
	for(long long k = 0;k<n;k++){
		anss = 0,ans = 0;
		for(long long i = k;i<n;i++){
			anss^=a[i];
			if(anss == m){
				ans++;
				anss = 0;
			}
		}
		ansa = max(ansa,ans);
		cout<<ans<<" ";
	}
	cout<<ansa;
}
