#include<bits/stdc++.h>
using namespace std;
char s[1002000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>(s+1);
	sort(s+1,s+1001000+1);
	for(int i=1001000;;i--){
		if(s[i]<='z'&&s[i]>='a') continue;
		if(s[i]<'10'&&s[i]>='0') cout<<s[i];
		if(i==1) break;
	}
	return 0;
} 

