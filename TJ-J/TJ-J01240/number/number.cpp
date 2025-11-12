#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s,nums;
	cin >> s;

	for(int i=0;i<s.length();i++){
		char c=s[i];
		if(isdigit(c)){
			nums+=c; 
		} 
	}
	sort(nums.begin(),nums.end(), greater<char>());
	cout << nums << endl;
	return 0;
}
