#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int>a;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            a.push_back(s[i]-48);
        }
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<a.size();i++){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
