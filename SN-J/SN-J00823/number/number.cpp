#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string str;
    cin >> str;
    vector<int> num;
    for (int i = 0; i < str.length(); i++){
        if (isdigit(str[i])){
            num.push_back(str[i]-'0');
        }
    }
    sort(num.begin(), num.end());
    for (int i = num.size()-1; i >= 0; i--){
        cout << num[i];
    }
    cout << "\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

