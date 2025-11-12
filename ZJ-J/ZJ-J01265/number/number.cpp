#include <bits/stdc++.h>
using namespace std;
const int NB=1e6+5;
int nlen,mp[13];
char ch[NB];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>ch;
	int nlen=strlen(ch);
	for(int i=0;i<nlen;i++) {
		if(ch[i]>='0' && ch[i]<='9') mp[ch[i]-'0']++;
	}
	for(int i=9;i>=0;i--) {
		for(int j=1;j<=mp[i];j++) cout<<i;
	}
	return 0;
}
