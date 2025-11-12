#include<bits/stdc++.h>
using namespace std;
int n, q;
string s1[200005], s2[200005], t1, t2;
int main()
{
    freopen("replace.in", "r", stdin);
//freopen("replace3.in", "r", stdin);
	freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i=0; i<n; ++i) cin >> s1[i] >> s2[i];
    for(int i=0; i<q; ++i)
    {
        int ans = 0;
        cin >> t1 >> t2;
        for(int j=0; j<n; ++j)
        {
            int p = t1.find(s1[j]);
            if(p != string::npos)
            {
                string tmp = t1.substr(0, p) + s2[j] + ((p+s1[j].size()>t1.size()-1)?"":t1.substr(p+s1[j].size(), t1.size()-(p+s1[j].size())));
                if(tmp == t2) ++ ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
