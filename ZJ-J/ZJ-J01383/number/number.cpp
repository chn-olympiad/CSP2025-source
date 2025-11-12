#include<bits/stdc++.h>
using namespace std;
string S;
long long Len,T[9178];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>S;
	Len=S.length();
	for(register int i=0; i<Len; i++) {
		if(isdigit(S[i])) {
			T[S[i]-'0']++;
		}
	}
	for(register int i=9; i>=0; i--) {
		while(T[i]) {
			printf("%lld",i);
			T[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
