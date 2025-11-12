#include<bits/stdc++.h>
#define int long long
using namespace std;
string st;
int b[20];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>st;
	int len=st.size();
	for(int i=0;i<len;i++) if(st[i]>='0'&&st[i]<='9') b[(st[i]-'0')]++;
	for(int i=9;i>=0;i--){
		while(b[i]>0){
			cout<<i;
			b[i]--;
		}
	}
}
