#include <bits/stdc++.h>
using namespace std;
int b[15];
string st;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>st;
	int len=st.size();
	for (int i=0;i<len;i++){
		if (st[i]>='0'&&st[i]<='9'){
			int ch=st[i]-'0';
			b[ch]++;
		}
	}
	for (int i=9;i>=0;i--)for (int j=1;j<=b[i];j++)cout<<i;
	return 0;
}