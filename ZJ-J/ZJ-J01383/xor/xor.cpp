#include<bits/stdc++.h>
using namespace std;
long long N,K,a[500005],Ans;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&N,&K);
	for(register int i=1; i<=N; i++)scanf("%lld",&a[i]);
	if(K==0) {
		for(register int i=1; i<=N; i++) {
			if(a[i]==0)Ans++;
			else if(a[i]==a[i+1])Ans++,i++;
		}
	} else if(K==1) {
		for(register int i=1; i<=N; i++) {
			if(a[i]==1)Ans++;
			else if((a[i]^a[i+1])==1)Ans++,i++;
		}
	}
	cout<<Ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
