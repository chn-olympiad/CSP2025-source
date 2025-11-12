#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5;
int n,m,al=1;
int c[N];
char s[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0)
			al*=c[i];
	}
	cout<<al;
	return 0;
}
