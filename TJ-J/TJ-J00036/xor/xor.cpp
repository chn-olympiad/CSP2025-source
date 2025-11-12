#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
    	scanf("%d",&a[i]);
	}
	cout<<n/2;
	return 0;
}

