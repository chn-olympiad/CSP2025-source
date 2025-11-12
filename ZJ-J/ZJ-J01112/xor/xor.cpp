#include<bits/stdc++.h>
using namespace std;
long long k,n,x,a[500005],s[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(long long i=n;i;i--){
		x=0;
		s[i]=s[i+1];
		for(int j=i;j<=n&&s[j+1]==s[i];j++){
			x^=a[j];
			if(x==k){
				s[i]++;
				break;
			}
		}
	}
	printf("%lld",s[1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}