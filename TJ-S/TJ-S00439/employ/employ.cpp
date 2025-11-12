#include <bits/stdc++.h>
#include <iostream> 
using namespace std;
long long int M=998244353;
int n,m;
int dol;
string s;
int a[610];
int main(){
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	dol=1;
	for(int i=2;i<=n;i++)
	{
		dol*=i;
		dol%=M; 
	}
	cout<<dol<<endl;
	return 0;
}
