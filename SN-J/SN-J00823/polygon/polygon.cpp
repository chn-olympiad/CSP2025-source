#include <bits/stdc++.h>
using namespace std;

struct Node{
    vector<int> l;
    int k;
};

vector<int> long_;
/*
int bfs(int k){
    int ans = 0;
    queue<Node> bfs_queue;
    vector<int> temp(1, 0);
    bfs_queue.push({temp, k});
    while (!bfs_queue.empty()){
        Node current = bfs_queue.front();
        bfs_queue.pop();
        if (current.k == 0){
            int t = 0;
            int maxn = INT_MIN;
            vector<int> t2(current.l.size());
            for (int i = 0; i < current.l.size(); i++){
                t2[i] = long_[current.l[i]];
            }
            for (int i = 0; i < t2.size(); i++){
                t += t2[i];
                maxn = max(maxn, t2[i]);
            }
            if (t > 2*maxn){
                ans++;
            }
            continue;
        }
        for (int i = current.l.back()+1; i < long_.size(); i++){
            Node new_;
            new_.k = current.k-1;
            vector<int> t = current.l;
            t.push_back(i);
            new_.l = t;
            bfs_queue.push(new_);
        }
    }
    return ans % 998244353;
}
*/
int result = 0;

void dfs(vector<int> l, int k){
    if (k == 0){
        int t;
        int maxn = 0;
        for (int i = 0; i < l.size(); i++){
            t += long_[l[i]];
            maxn = max(maxn, long_[l[i]]);
        }
        if (t > maxn*2){
            result++;
        }
    }
    if (l.empty()){
        for (int i = 0; i < long_.size(); i++){
            vector<int> temp = long_;
            temp.push_back(i);
            dfs(temp, k-1);
        }
    }
    else{
    for (int i = l.back(); i < long_.size(); i++){
        vector<int> temp = long_;
        temp.push_back(i);
        dfs(temp, k-1);
    }
    }
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    long_.resize(n);
    for (int i = 0; i < n; i++){
        cin >> long_[i];
    }
    if (n < 3){
        cout << 0 << "\n";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    int ans = 0;
    for (int i = 3; i <= n; i++){
        vector<int> temp(0);

    }
    cout << result << "\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

