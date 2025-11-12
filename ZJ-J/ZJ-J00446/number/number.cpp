#include <bits/stdc++.h>
using namespace std;
#define ll long long
char s[1000005];
ll n;
ll c[25];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n = strlen(s+1);
	for(ll i = 1;i <= n;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			c[s[i] - '0']++;
		}
	}
	for(ll i = 9;i >= 0;i--){
		for(ll j = 1;j <= c[i];j++){
			printf("%lld",i);
		}
	}
	return 0;
} 
