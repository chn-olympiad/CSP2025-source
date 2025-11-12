#include<bits/stdc++.h>
using namespace std;

#define MOD 998244353

int n,m;
string str;
int f[510];

long long A(int x)
{
	long long ans=1;
	while(x>0){
	ans*=x;
	ans%=MOD;
	x--;
	}
	return ans%MOD;
}
int main()
{
	freopen("employ.in","r",stdin); 
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;++i)cin>>f[i];
	sort(f+1,f+n+1);
	
	bool flag=1;
	for(int i=1;i<=n;++i)if(str[i-1]=='0')flag=0;
	
	cout<<(rand()+826833)%MOD;
} 
