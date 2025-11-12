#include <bits/stdc++.h>
using namespace std;
string s;
priority_queue<int,vector<int>,less<int> > nums;
long long ans;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio;
    cin.tie(0); cout.tie(0);

    cin >> s;
    //记录s中所有的数字
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])){
            nums.push(s[i] - '0');
        }
    }
    //输出答案（从大到小输出）
    while(!nums.empty()){
        cout << nums.top();
        nums.pop();
    }
}