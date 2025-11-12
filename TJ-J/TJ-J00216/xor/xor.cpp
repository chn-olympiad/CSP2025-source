#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,ans=0,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long l=0;
	for(int i=1;i<=n;i++){
		int c=0;
		for(int j=i;j>l;j--){
			c^=a[j];
			if(c==k){
				l=i;
				ans++;
				break;
			}
		}
	}
	printf("%lld\n",ans);
}
/*
1 2 3 4

*/
