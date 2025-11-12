#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000],ans=0;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int y=n;
	cin>>s;
	for(int i=0;i<y;i++){
	    cin>>a[i];
	    ans+=n*(n-1)/2;
	}
	cout<<ans%998244353;
	return 0;
}
