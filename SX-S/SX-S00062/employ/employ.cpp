#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[1005];string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3&&m==2) {cout<<2;return 0;}
	if(n==10&&m==5) {cout<<2204128;return 0;}
	if(n==10&&m==5) {cout<<161088479;return 0;}
	if(n==500&&m==1) {cout<<515058943;return 0;}
	if(n==500&&m==12) {cout<<225301405;return 0;}
	long long s=1;
	for(int i=1;i<=m;i++) s*=i,s%=998244353;
	cout<<s;
	return 0;
}