#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    vector<int>n;
    for(char i:s){
        if(isdigit(i))n.push_back(i-'0');
        }
    sort(n.begin(),n.end());
    reverse(n.begin(),n.end());
    for(int i:n)cout<<i;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
