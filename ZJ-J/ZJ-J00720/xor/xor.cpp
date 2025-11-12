#include<bits/stdc++.h>
using namespace std;
int n,k,a[10010],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=a[i];
		if(a[i]==k)ans++;
		for(int j=i+1;j<=n;j++){
			if(a[j]==x)x=0;
			else x=1;
			if(k==x)ans++;
		}
	}
	cout<<ans;
	return 0;
}
