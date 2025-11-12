#include <bits/stdc++.h>
using namespace std;

struct block{
    int start_;
    int end_;
};

bool cmp(const block& a, const block& b){
    return a.end_ < b.end_;
}

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, num;
    cin >> n >> num;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++){
        dp[i][i] = a[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            dp[i][j] = dp[i][j-1];
            dp[i][j] ^= a[j];
        }
    }
    vector<block> blocks;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            if (dp[i][j] == num){
                blocks.push_back({i,j});
                break;
            }
        }
    }
    sort(blocks.begin(), blocks.end(), cmp);
    vector<block> chose_blocks;
    for (int i = 0; i < blocks.size(); i++){
        if (chose_blocks.empty()){
            chose_blocks.push_back(blocks[i]);
        }
        else if (blocks[i].start_ > chose_blocks.back().end_){
            chose_blocks.push_back(blocks[i]);
        }
    }
    cout << chose_blocks.size() << "\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

