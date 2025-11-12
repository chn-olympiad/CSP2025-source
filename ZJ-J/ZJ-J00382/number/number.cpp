#include<bits/stdc++.h>
//#define int long long

using namespace std;

string str;
int f[15];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>str;
	for(int i=0;i<str.size();i++)
		if(str[i]>='0'&&str[i]<='9'){
			int x=str[i]-48;
			f[x]++;
		}
	for(int i=9;i>=0;i--){
		while(f[i]){
			f[i]--;
			cout<<i;
		}
	}
	return 0;
}
