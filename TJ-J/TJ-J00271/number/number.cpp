#include<bits/stdc++.h> 
using namespace std;
string s,t;
int main(){
	cin >> s;
		for(int i = 0 ;i < s.size();i++){
			if(s[i] <=57 && s[i] >= 48){
				t += s[i];
		}	}
		sort (t.begin(),t.end());
		reverse(t.begin(),t.end());
	
	cout << t;
	return 0;
	
}


