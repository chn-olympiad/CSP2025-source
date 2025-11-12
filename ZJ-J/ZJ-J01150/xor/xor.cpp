#include<bits/stdc++.h>
using namespace std;
long long n,k,s[500005],q[500005],cnt=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
		if(i>1)
			q[i]=q[i-1]^s[i];
		else
			q[i]=s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long x;
			if(i==j){
				x=s[j];
			}else{
				if(i>1){
					x=q[j]^q[i-1];
				}else{
					x=q[j];
				}
			}
			if(x==k){
				cnt++;
				i=j+1;
				j=i;
			}
		}
	}
	printf("%lld",cnt);
	return 0;
}