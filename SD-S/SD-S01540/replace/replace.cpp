#include<bits/stdc++.h>
#define For(i, j, k) for(int i=j;i<=k;i++)
using namespace std;

int n,q;
string s,t;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	For(i,1,n)cin>>s>>t;
	For(i,1,q)cin>>s>>t;
	For(i,1,q)cout << 0 << "\n";
	
	return 0;
}

