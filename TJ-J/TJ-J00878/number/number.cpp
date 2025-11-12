#include <bits/stdc++.h>
using namespace std;
long long a[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,0,sizeof(a));
	cin >> s;
	for(long long i = 0;s[i];i++){
		if(s[i]<='9'and s[i]>='0'){
			a[s[i]-'0']++;
		}
	}
	int c = 9;
	while(c>=0){
		if(!a[c]) c--;
		while(a[c]>0){
			cout << c;
			a[c]--;
		}
	}
	return 0;
}
