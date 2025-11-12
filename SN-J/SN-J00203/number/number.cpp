#include<bits/stdc++.h>
using namespace std;
int main(){
	int d;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i = 0 ; s != "0" ; i++){
		d = i;
	}
	for(int i = 0 ; i < d - 1 ; i++){
		for(int j = 0 ; j < d - i ; j++){
			if(s[j] < s[j+1]){
				swap(s[j],s[j+1]);
			}
		}
	}
	for(int i = 0 ; i < d ; i++){
		if("0" <= (s[i]) <= "9"){
			cout<<s[i];	
		}
	}
	return 0;	
}

