#include<bits/stdc++.h>
using namespace std;
int s[505],b[505],f[505][505],cnt;
const int p=998244353;
long long ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		s[i+1]=s[i];
		if(a[i]=='0'){
			s[i+1]++;
			b[i]++;
		}
	}
	
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x==0)cnt++;
	}
	if(m==n&&s[a.size()]>0){
		cout<<0;
		return 0;
	}
	ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=p;
	}
	cout<<ans;
	return 0;
	return 0;
}//employ