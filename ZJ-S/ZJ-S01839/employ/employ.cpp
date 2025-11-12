#include<bits/stdc++.h>
using namespace std;
int c[501];
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
	}
	int tn=n;
	for(int i=1;i<=tn;i++) {
		if(c[i]==0) n--;
	}
	long long ans=1;
	for(int i=0;i<m;i++){
		ans*=(n-i);
		ans%=998244353;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

