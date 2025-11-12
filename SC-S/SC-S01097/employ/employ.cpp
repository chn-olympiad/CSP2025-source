#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long c[N]; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	    cin>>c[i];
	long long sum=1;
	for(long long i=1;i<=n;i++)
		sum=(sum*i)%998244353;
	cout<<sum;
} 