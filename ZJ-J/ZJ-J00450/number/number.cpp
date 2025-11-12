#include <bits/stdc++.h>
using namespace std;
string str;
int f[16];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	//LL!
	cin>>str;
	for(int i=0;i<str.size();i++)
		if(str[i]>='0'&&str[i]<='9')
			f[str[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(f[i]){
			cout<<i;
			f[i]--;
		}
	return 0;
}