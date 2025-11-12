#include<bits/stdc++.h>
using namespace std ;
int w[1043] ;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s ;
	cin >> s ;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			w[s[i]-'0']++ ;
		}
	}
	for(int i=9;i>=0;i--){
		while(w[i]){
			cout << i ;
			w[i]-- ;
		}
	}
	return 0;
}
