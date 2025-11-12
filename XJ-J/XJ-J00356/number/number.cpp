#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s;
int C[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s){
		C[s-'0']++;
	}
	for(int i=9; i>=0; i--){
		if(C[i]!=0){
			for(int j=1; j<=C[i]; j++){
				cout << i;
			}
		}
	}
	return 0;
}
