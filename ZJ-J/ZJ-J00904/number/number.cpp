#include<bits/stdc++.h>
using namespace std;

string s;
int cnt[15];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	getline(cin,s);
	for(char x:s){
		if(x>='0' && x<='9'){
			cnt[x-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			cout<<i;
		}
	}
	cout<<endl;
	

	return 0;
}

