#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,p,q,a[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	p=n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!a[i])p--;
	}
	cout<<p<<endl;
	q=1;
	for(long long i=1;i<=p;i++)
		q=q*i%mod;
	cout<<q<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
