#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],s[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]&a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]&a[i]==m){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
