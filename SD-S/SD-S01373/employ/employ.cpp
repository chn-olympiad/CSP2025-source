#include<bits/stdc++.h>
using namespace std;
int t[510];
long long bj[510]={0};
long long fact(int y){
	if(bj[y]!=0)return bj[y];
	else{
		long long h=1;
		for(int i=2;i<=y;i++){h*=i,h%=998244353;}
		bj[y]=h;
		return h;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string p;
	cin>>p;
	int s;
	for(int i=0;i<n;i++){
		cin>>s;
		t[s]++;
	}
	for(int i=2;i<n;i++){
		t[i]+=t[i-1];
	}
	int k=t[0];
	long long ans=(fact(n)*fact(k))%998244353;
	for(int i=1;i+t[i]<=m;i++){
		ans+=((fact(n)*fact(k-i))%998244353)*fact(i);
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}

