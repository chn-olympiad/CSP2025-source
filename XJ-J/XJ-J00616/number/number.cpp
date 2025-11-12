#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	getline(cin,s);
	int as[10];
	for(int i=0;i<s.size();i++){
		for(int j=0;j<10;j++){
			if(s[i]-32==j){
				as[j]++;
			}
		}
	}
	for(int i=0;i<10;i++){
		if(as[i]!=0){
			for(int j=1;j<=as[i];j++){
				cout<<i;
			}
		}
	}
    return 0;
}
