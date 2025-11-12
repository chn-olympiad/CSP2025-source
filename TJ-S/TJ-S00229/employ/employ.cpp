#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	char a;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a=='1')cnt++;
	}if(m==1){
		cout<<n*cnt;
		return 0;
	}else if(cnt==n){
		int num=1;
		for(int i=1;i<=n;i++){num*=i;}
		cout<<num%998244353;
		return 0;
	}cout<<n*m;
	return 0;
}//998244353

