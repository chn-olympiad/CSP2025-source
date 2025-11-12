#include<bits/stdc++.h>
using namespace std;
long long a[2000000000000]
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	if(a[i]^1==k)
    	cout<<a[i];
	}
	return 0;
}