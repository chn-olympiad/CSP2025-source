#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[610],pl[610];
string s;
main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)pl[i]=i;
	do{
		int sum=0,zbc=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||zbc>=a[pl[i]])zbc++;
			else sum++;
		}
		ans+=(sum>=m);
	}while(next_permutation(pl+1,pl+1+n));
	cout<<ans;
}
