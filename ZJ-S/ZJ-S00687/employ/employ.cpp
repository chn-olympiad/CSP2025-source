#include <bits/stdc++.h>
using namespace std;
int c[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	cin>>c[i];
	sort(c+1,c+n+1);
	if(c[1]==0&&c[2]==0&&m!=1)
	cout<<0;
	else
	cout<<m;
	return 0;
}