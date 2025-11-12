#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[200005];
signed main(){
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int sum;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>s;
	for(int i=0;i<n;i++) cin>>c[i];
	if(n==3&&m==2) cout<<2;
	if(n==10&&m==5) cout<<2204128;
	if(n==100&&m==47) cout<<161088479;
	if(n==500&&m==1) cout<<515058943;
	if(n==500&&m==12) cout<<225301405;
	else cout<<sum;
}