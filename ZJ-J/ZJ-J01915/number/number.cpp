#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<1000005;i++){
		if(!isdigit(s[i]))s[i]=0;
	}
	sort(s,s+1000005,greater<char>());
	cout<<s;
	return 0;
}
