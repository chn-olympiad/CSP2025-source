#include<bits/stdc++.h>
using namespace std;
int used[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str;
	cin>>str;
	int leng=str.length();
	for (int i=0;i<leng;i++){
		if (str[i]<='9'&&str[i]>='0'){
			used[str[i]-'0']++;
		}
	}
	for (int i=9;i>=0;i--){
		if (used[i]){
			for (int j=0;j<used[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
