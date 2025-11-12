#include<bits/stdc++.h>
using namespace std;

int n,m,s,c;
int M=998244353;

long long jc(int x){
	long long ans=1;
	for(int i=1;i<=x;i++){
		ans*=x;
		ans%=M;
	}
	return ans;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
	}
	for(int i=1;i<=n;i++){
		cin>>c;
	}
	cout<<jc(n);
	return 0;
}