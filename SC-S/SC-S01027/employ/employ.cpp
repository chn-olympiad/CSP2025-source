#include<bits/stdc++.h>
using namespace std;
long long m,n,cnt,sum,a[510];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>m>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i-1]==0||cnt==a[i]) cnt++;
		else sum++;
	}
	cout<<sum;
	return 0;
}