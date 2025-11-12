#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin >> s;
    int n=s.size();
    vector<int> a(n,0);
    for(int i=0;i<n;++i){
        a[i]=s[i]-'0';
    }
    sort(a.begin(),a.end(),greater<int>());
    for(int i=0;i<n;++i){
        if(a[i]<=9 && a[i]>=0) cout<<a[i];
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
