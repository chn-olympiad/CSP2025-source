#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,len='z';
long long a[len];
char s[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s);
	int slen=strlen(s);
	for(int i=0;i<slen;i++){
		a[s[i]]++;
	}
	for(int i='9';i>='0';i--){
		while(a[i]--) printf("%c",i);
	}
	return 0;
}
