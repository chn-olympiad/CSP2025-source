#include<bits/stdc++.h>
using namespace std;
char s;
string a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s){
		if('0'<=s&&s<='9')
			a[s-'0']+=s;
	}
	for(int i=9;i>=0;i--)
		cout<<a[i];
	printf("\n");
	return 0;
}
