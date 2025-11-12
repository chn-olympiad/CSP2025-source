#include<bits/stdc++.h>
using namespace std;
int n,m,w[505];
const int mod = 998244353;
bool a[505];
long long A[505];
long long forA(int n){
	A[1]=1;
	for(int i=1;i<=n;i++){
		A[i]=A[i-1]*i;
		A[i]%=mod;
	}
}
bool vis[20];
int sech(int now,int pa){
	long long ret=0;
	if(now==n+1){return (pa>=m);}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(now-pa-1<w[i]&&a[now]) ret+=sech(now+1,pa+1);
			else ret+=sech(now+1,pa);
			ret%=mod;
			vis[i]=0;
		}
	}
	ret%=mod;
	return ret;
}
void cas1(){
	int rem1=0;
	for(int i=1;i<=n;i++){
		if(!a[i]){rem1=i;break;}
	}
	if(rem1<m){
		long long aa=A[n];
		cout<<aa;
	}else cout<<0;
}
void cas2(){
	int rem1=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0) rem1=1;
	} 
	for(int i=1;i<=n;i++){
		if(w[i]==0) rem1=1;
	}
	if(!rem1) cout<<A[n];
	else cout<<0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
string ac;cin>>ac;ac=" "+ac;
	for(int i=1;i<=n;i++){
		
		a[i]=ac[i]-'0';
	}
	
	bool k1=1;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		if(w[i]!=1) k1=0;
	}
	sort(w+1,w+1+n);
	if(k1){
		cas1();
	}else if(n<=18){
		cout<<sech(1,0);
	}
	if(m==n||m==1){
		cas2();
	}
	return 0;
}//m==1没有可能。
//小罗尼世界第一可爱 
/*
3 2
101
1 1 2

*/

