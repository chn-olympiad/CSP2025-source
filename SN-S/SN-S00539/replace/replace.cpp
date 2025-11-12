#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n,q;
    cin >> n >> q;
    unordered_map<string, string> dic;
    vector<string> mp_key(n);
    for (int i = 0; i < n; i++){
        string value;
        cin >> mp_key[i] >> value;
        dic[mp_key[i]] = value;
    }
    while (q--){
        string str1, str2;
        cin >> str1 >> str2;
        if (str1.length() != str2.length()){
            cout << "0\n";
            continue;
        }
        int ans = 0;
        for (const string key : mp_key){
            string value = dic[key];
            int len = key.length();
            for (int i = 0; i+len <= str1.length(); i++){
                string temp = str1.substr(i, len);
                if (temp == key){
                    string first = str1.substr(0, i);
                    string last = str1.substr(i+len);
                    if (first+value+last == str2){
                        ans++;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
