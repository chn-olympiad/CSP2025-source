#include<bits/stdc++.h>
using namespace std;
long long f[110];
string st,st1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,st);
	for(int i=0;i<st.size();i++){
		if(st[i]>='0'&&st[i]<='9')f[int(st[i]-'0')]++;
	}
	for(int i=9;i>=0;i--){
		while(f[i])f[i]--,cout<<i;
	}
	return 0;
}
