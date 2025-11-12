#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll numcnt[10];
string as;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(numcnt,0,sizeof numcnt);
	cin>>as;
	ll len=as.length();
	for(ll i=0;i<len;++i)
		if(as[i]>='0'&&as[i]<='9')
			++numcnt[as[i]-'0'];
	for(ll i=9;i>=0;--i)
		for(ll j=0;j<numcnt[i];++j)
			printf("%lld",i);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
