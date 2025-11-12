#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
using namespace std;

const int N=1e6+10,MOD=998224353;
int n,m,c[N];
ll a[N];



int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	a[0]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		a[i]=a[i-1]*i%MOD;
	}
	cout<<a[n]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


















//_________________________________________________________

