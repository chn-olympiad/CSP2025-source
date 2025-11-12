#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int y=0,x;
	char sum = 47;
	for(int i = 0;i<=s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			y++;
		}
	}
	while(y--){
		sum = 47;
		for(int i = 0;i <= s.size();i++){
			if(s[i] >= '0' && s[i] <= '9'){
				if(s[i] > sum){
					sum = s[i];
					x=i;
				}
			}
	    }
	    s[x] = ' ';
	    cout << sum;
	}
	return 0;
} 
