#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
#define fi first
#define se second
#define mp make_pair
#define vector basic_string
#define debug1(x) cerr<<(#x)<<"="<<(x)<<" "
#define debug2(x) cerr<<(#x)<<"="<<(x)<<"\n"

signed main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    for(int i=1;;i++){
        cout<<"Case "<<i<<":\n";
        system("./gen > data.in");
        system("./code1 < data.in > data.out");
        system("./code < data.in > data.ans");
        if(system("diff -Z data.out data.ans"))break;
    }
    return 0;
}
/*
g++ -std=c++14 -Wall -Wextra -Wshadow -Wconversion -fsanitize=address,undefined
*/