#includ<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a,b,c;
	cin>>n;
	if(n==3) cin>>a>>b>>c;
	else
	{
		cout<<a%998244353;
		return 0;
	}
	if(a+b<c&&a+c<b&&b+c<a) cout<<1;
	else cout<<0;
}
