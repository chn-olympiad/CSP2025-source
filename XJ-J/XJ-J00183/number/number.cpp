#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+5;
char s[N];
int a[15];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>(s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++){
		if(s[i]>='0' and s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
