#include <bits/stdc++.h>
using namespace std;
#define int long long
int tongq[100];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string st;
	cin>>st;
	for(int i=0;i<st.size();i++){
		if(st[i]>='0'&&st[i]<='9'){
			tongq[st[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<tongq[i];j++){
			cout<<i;
		}
	}
	return 0;
}
