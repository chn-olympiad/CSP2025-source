#include<bits/stdc++.h>
using namespace std;
int f(int n)
{
	if(n==1)return 1;
	return (f(n-1)*n)%998244353;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n;
    cin>>n;
    cout<<f(n);
    return 0;
}
