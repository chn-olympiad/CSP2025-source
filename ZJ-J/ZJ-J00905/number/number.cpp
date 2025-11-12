#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
    string str;
    cin>>str;
    vector<int> ans;
    for(int i=0; i<str.length(); i++){
        if(isdigit(str[i])) ans.push_back((int)str[i]-48);
    } sort(ans.begin(), ans.end(), greater<int>());
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i];
    } return 0;
}
