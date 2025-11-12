#include<bits/stdc++.h>
using namespace std;
char s[1000010],b[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=1;i<s[i];i++){
		if(s[i]<='0'&&s[i]>='9'){
			b[i]=s[i];
		}
	}
	for(int i=1;i<=1;i++){
		cout<<b[i];
	}
	return 0;
}

