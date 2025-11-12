#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q;
string s1[N], s2[N], t1, t2;
int a[5][N];
struct sdf{
    int val;
    vector<int>a1, a2, b1, b2;
}t[N][5];
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; ++ i){
        cin >> s1[i] >> s2[i];
        int len = s1[i].size();
        for(int j = 0; j < len; ++ j){
            if(s1[i][j] == 'b'){
                a[1][i] = j;
                break;
            }
        }
        for(int j = 0; j < len; ++ j){
            if(s2[i][j] == 'b'){
                a[2][i] = j;
                break;
            }
        }
        a[3][i] = a[1][i] - a[2][i];
        if(a[3][i] < 0){
            t[-a[3][i]][1].val ++;
            t[-a[3][i]][1].a1.push_back(a[1][i]);
            t[-a[3][i]][1].a2.push_back(a[2][i]);
            t[-a[3][i]][1].b1.push_back(len);
        } 
        else{
            t[a[3][i]][2].val ++;
            t[a[3][i]][2].a1.push_back(a[1][i]);
            t[a[3][i]][2].a2.push_back(a[2][i]);
            t[a[3][i]][2].b1.push_back(len);
        } 
    }
    while(q --){
        cin >> t1 >> t2;
        int len = t1.size(), x, y;
        for(int i = 0; i < len; ++ i){
            if(t1[i] == 'b'){
                x = i;
                break;
            }
        }
        for(int i = 0; i < len; ++ i){
            if(t2[i] == 'b'){
                y = i;
                break;
            }
        }
        int z = x - y;
        if(z < 0){
            int val1 = t[-z][1].val;
            for(int i = 0; i < t[-z][1].a1.size(); ++ i){
                int xx = t[-z][1].a1[i];
                if(x - xx < 0|| x + t[-z][1].b1[i] - xx - 1 >= len) val1 --;
            }
            cout << val1 << endl;
        } 
        else{
            int val1 = t[z][2].val;
            for(int i = 0; i < t[z][2].a1.size(); ++ i){
                int xx = t[z][2].a1[i];
                if(x - xx < 0|| x + t[z][2].b1[i] - xx - 1 >= len) val1 --;
            }
            cout << val1 << endl;
        }
    }
    return 0;
}