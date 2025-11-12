#include<iostream>
using namespace std;
int n,m;
int mod=998244353; 
char a[1000000];
int c[100000];
int nd[100000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		nd[i]=a[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	
}
