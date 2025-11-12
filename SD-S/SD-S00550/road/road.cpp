#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,p;
	cin>>n>>m>>p;
	ll arr[m+1][4];
	ll s[m+1];
	for(int i=1;i<=m;i++){
		cin>>arr[i][1]>>arr[i][2]>>s[i];
	}
	sort(s+1,s+m+1);
	ll num=0;
	for(int i=1;i<m;i++){
		num+=s[i];
	}
	cout<<num<<endl;
	return 0;
}

