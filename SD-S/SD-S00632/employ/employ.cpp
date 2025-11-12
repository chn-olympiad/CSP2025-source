#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,c[N],cnt=0,sct=0;
bool s[N],f=1;
bool cmp(int a,int b){
	return a<b;
}
long long a(int x){
	long long res=1;
	for(int i=2;i<=x;i++){
		res*=i;
		res%=mod;
	}
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string st;
	cin>>st;
	for(int i=0;i<n;i++){
		s[i]=st[i]-'0';
		if(!s[i])f=0;
		else sct++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)cnt++;
	}
	sort(c+1,c+n+1,cmp);
	if(f){
		cout<<a(n,n);
		return 0;
	}
	if(m==n){
		if(!f&&!cnt)cout<<0;
		else cout<<a(n,n);
	}
	if(m==1){
		if(cnt<sct)cout<<a(n);
		else cout<<a(n)-a(n-sct);
	}
	return 0;
}

