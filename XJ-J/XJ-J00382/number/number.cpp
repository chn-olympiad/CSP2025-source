#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> temp;
bool cmp(int q,int h){
	return q > h;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i=0;i<s.size();i++){
    	if(s[i] <= '9' && s[i] >= '0'){
    		temp.push_back(s[i] - '0');
		}
	} 
	sort(temp.begin(),temp.end(),cmp);
	string ans;
	for(int i=0;i<temp.size();i++){
		ans += temp[i] + '0';
	}
	cout << ans;
    return 0;
}
