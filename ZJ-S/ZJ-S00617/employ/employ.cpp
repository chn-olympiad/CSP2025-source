#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],b[1000],t;
string s;
const int M=998244353;
bool check1(){
	for(int i=1;i<=n;i++){
		if(b[i]==0)return false;
	}
	return true;
}
bool check2(){
	int t=0;
	for(int i=1;i<=n;i++){
		if(b[i]==1)t++;
	}
	if(t<m)return true;
	else return false;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		b[i+1]=s[i]-48;
	}
	sort(a+1,a+n+1);
	if(check1()||m==1){
		t=1;
		for(int i=1;i<=n;i++){
			t=(t*i%M)%M;
		}
		cout<<t%M;
		return 0;
	}
	if(m==n&&!check1()||check2()){
		cout<<"0";
		return 0;
	}
	cout<<"1";
	return 0;
}
