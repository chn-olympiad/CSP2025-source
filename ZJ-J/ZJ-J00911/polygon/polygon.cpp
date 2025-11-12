#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10000];
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin>>n;
	if (n<3){
		cout<<0;
		return 0;
	}
	int sum=0;
	for (int i=1; i<=n; i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1, a+1+n);
	if (n==3){
		if (a[n]*2<sum) cout<<1;
		else cout<<0;
	}
	else{
		int cnt=0;
		for (int i=1; i<=n; i++)
			if (a[i]==1) cnt++;
		int edges=cnt-2;
		int ans=0;
		while (edges){
			for (int i=1; i<=edges; i++)
				for (int j=edges; j>=1; j--) ans=(ans+i*j)%998244353;
			edges--;
//			cout<<"awa"<<endl;
		}	
		cout<<ans;
	}
	return 0;
}