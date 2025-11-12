#include <bits/stdc++.h>
using namespace std;
const int RUSSEL=1e5+5;
int norris,formula1,lando[RUSSEL],oscar;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin >> norris >> formula1;
    for(int i=1;i<=norris;i++){
        cin >> lando[i];
    }
    if(lando[1] ^ lando[1] == formula1) oscar++;
    if(lando[1] ^ lando[2] == formula1) oscar++;
    if(lando[2] ^ lando[2] == formula1) oscar++;
    cout << oscar;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
