#include<bits/stdc++.h>
using namespace std;
int a[550];
int b[550];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	for(int j=1;j<=n;j++){
		int lq=0,dx=0;
		for(int i=1;i<=n;i++){
			if(a[i]<=0){
				dx++;
				b[i+1]-=dx;
				continue;
			}
			if(s[i]=='1')lq++;
			else dx++;
			b[i+1]-=dx;
		}
		if(lq>=m)ans++;
		
		a[0]=a[n];
		for(int i=n;i>=1;i--){
			a[i]=a[i-1];
		}
		for(int i=1;i<=n;i++){
			b[i]=a[i];
		}
		
	}
	
	
	cout<<ans%998244353;
	return 0;
}

