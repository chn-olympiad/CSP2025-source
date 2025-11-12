#include<bits/stdc++.h>
using namespace std;

string s;

signed main(){
	
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    
    cin >> s ;

    int n = s.size();
    s = ' ' + s;

    multiset<int,greater<int> > st;

    for(int i = 1; i <= n; i++){
        if(isdigit(s[i])){
            st.insert(s[i] - '0');
        }
    }

    for(auto it : st){
        cout << it;
    }

    return 0;
}
