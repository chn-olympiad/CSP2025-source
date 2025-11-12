//SN-J00466  shiyihao  jinkaierzhong
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int> a;
    int n=0;
    for(int i=0;i<s.length();i++){
        switch(s[i]){
    case '1':
        a.push_back(1);
        n++;
        break;
    case '2':
        a.push_back(2);
        n++;
        break;
    case '3':
        a.push_back(3);
        n++;
        break;
    case '4':
        a.push_back(4);
        n++;
        break;
    case '5':
        a.push_back(5);
        n++;
        break;
    case '6':
        a.push_back(6);
        n++;
        break;
    case '7':
        a.push_back(7);
        n++;
        break;
    case '8':
        a.push_back(8);
        n++;
        break;
    case '9':
        a.push_back(9);
        n++;
        break;
    case '0':
        a.push_back(0);
        n++;
        break;
        }
    }
    int m[n];
    for(int i=0;i<n;i++){
        m[i]=a[i];
    }
    sort(m,m+n);
    for(int i=n-1;i>=0;i--){
        cout<<m[i];
    }
    return 0;
}

