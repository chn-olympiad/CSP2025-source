#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("employ3.in","r",stdin);
freopen("employ.out","w",stdout);
int n,m;
cin>>n>>m;
int q=0;
long long ans=1;
for(int i=0;i<n;i++){
	char a;
	cin>>a;
	int b=a-'0';
	if(b){
		q++;
	}
}
for(int i=1;i<=q;i++){
	ans*=i;
//	cout<<ans;
	ans%=998244353;
}
for(int i=m;i<=q;i++){
	ans*=i;
//	cout<<ans;
	ans%=998244353;
}

cout<<ans;
return 0;
}

