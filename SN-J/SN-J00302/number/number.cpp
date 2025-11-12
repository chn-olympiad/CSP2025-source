#include <bits/stdc++.h>
using namespace std;
string s;
long long a , n , j;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	n = s.size();
	while(n --){
		a = -1;
		for(int i = 0; i < s.size(); i ++){
			if(s[i] >= '0' && s[i] <= '9'){
				if(s[i] - '0' > a){
					a = s[i] - '0';
					j = i;
				}
			}else{
				s[i] = 'a';
			}
		}
		if(a > -1){
			cout << a;
			s[j] = 'a';
		}
		
	}
	
	return 0;
} 
