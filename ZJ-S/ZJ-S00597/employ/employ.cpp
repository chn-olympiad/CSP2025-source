#include <bits/stdc++.h>
using namespace std;
int n,m;
long long md=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char c;
	int x;
	for (int i=1;i<=n;i++)
		cin>>c;
	for (int i=1;i<=n;i++)
		cin>>x;
	long long ans=1;
	for (int i=2;i<=n;i++)
		ans=ans*i%md;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
