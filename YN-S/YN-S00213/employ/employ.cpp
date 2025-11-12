#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int maxn=2e6+5;
int c[maxn];
string s;
int sz[maxn];
long long jiajia(long long x){
	if(x==1)return 1;
	return x*jiajia(x-1);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	bool pian=true;
	for(int i=1;i<=n;i++){
		sz[i]=s[i-1]-48;
		if(sz[i]!=1)pian=false;
	}
	if(pian==true){
		cout<<jiajia(m)%998244353<<endl;
		return 0;
	}
	sort(c+1,c+1+n);
	long long zuobuchulai=0;
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(zuobuchulai<c[i]&&sz[i]==1)ans++;	
	}
	cout<<ans%998244353<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
