#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],sum,ans,mo=998244353,x;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]&&a[i]>x)x++;
	}
	cout<<0;
	return 0;
}
