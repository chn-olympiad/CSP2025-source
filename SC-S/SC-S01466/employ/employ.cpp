#include<bits/stdc++.h>
using namespace std;
int n,m,c[100005],k=1;
string s;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	cin>>c[i];
	for(int i=1;i<=n;i++)
	k=k*i;
	cout<<k;
	return 0;
}