//SN-J00721  Õı •ø≠ 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int v[12];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			v[(int)(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=v[i];j++){
			cout<<i;
		}
	}
	return 0;
}

