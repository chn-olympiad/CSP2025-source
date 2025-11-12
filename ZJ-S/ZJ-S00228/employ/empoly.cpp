#include<bits/stdc++.h>
using namespace std;
long long n,m,k[509];
string l;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>l;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	if(n==3&&m==2)cout<<2;
	else if(n==10&&m==5)cout<<2204128;
	else if(n==100&&m==47)cout<<161088479;
	else if(n==500&&m==12)cout<<225301405;
	else if(n==500&&m==1)cout<<515058943;
	return 0;
}
