#include<bits/stdc++.h>
#include<string>
using namespace std;
long long n,k,x,sum,s[500001],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans=i;
			for(int l=i+1;l<=j;l++){
				ans^=s[l];
			}
			if(ans==k){
				sum++;
			}
		}
	}
	printf("%lld",sum);
	return 0;
}