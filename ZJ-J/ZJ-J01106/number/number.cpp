#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int> numbers;
    for(size_t i=0;i<s.size();i++){
        const char c = s[i];
        if('0' <= c && c<='9'){
            numbers.push_back(c-'0');
        }
    }
    sort(numbers.begin(), numbers.end(), greater<int>());
    for(size_t i=0;i<numbers.size();i++){
        cout<<numbers[i];
    }
    return 0;
}