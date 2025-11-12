#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s,a;
	cin>>s;
	for(int i = 1;i<=s.size();i++){
		if(s == s.size()-1){
			a = s;
		}
		s = s.size()-1;
	}
	cout<<a;
	return 0;
}