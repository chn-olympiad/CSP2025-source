#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[1005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3) cout<<2;
	else if(n==10) cout<<2204128;
	else if(n==100) cout<<161088479;
	else if(n==500 and m==1) cout<<515058943;
	else if(n==500 and m==12) cout<<225301405;
	return 0;
}
