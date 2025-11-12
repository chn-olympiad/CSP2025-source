#include <bits/stdc++.h>

using namespace std;

bool cmp(int x,int y){
    return x>y;
}
int main()
{   
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int>x;
    for(int i=0;i<s.size();i++ ){
    	char c=s[i];
        if(c>='0'&&c<='9'){
            x.push_back(c-'0');
        }
    }
    sort(x.begin(),x.end(),cmp);
    for(int i=0;i<x.size();i++){
        cout<<x[i];
    }
    cout  << endl;
    return 0;
}

