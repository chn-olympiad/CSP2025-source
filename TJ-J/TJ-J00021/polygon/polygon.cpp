#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int n;
vector<int> arr;
vector<bool> vis;//dfs
set<vector<int>> ans;

int ML(vector<int> index){
    int Max = INT_MIN;
    for(int ind : index){
        Max = max(Max , arr[ind]);
    }
    return Max;
}

void dfs(int num , int sum , vector<int> use){
    if(num > n){
        return;
    }

    if(num >= 3){
        if(sum > ML(use) * 2){
            sort(use.begin() , use.end());
            ans.insert(use);
        }
    }

    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            use.push_back(i);
            vis[i] = true;
            dfs(num + 1 , sum + arr[i] , use);
            use.pop_back();
            vis[i] = false;
        }
    }

}

int main(){
    //11:26
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

    cin >> n;

    arr.resize(n + 1);
    vis.resize(n + 1 , false);
    bool sp_1 = true;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
        sp_1 = (sp_1 && arr[i] == 1);
    }

    if(sp_1){
        long long ans = 0;
        for(int len = 3;len <= n;len++){
            ans += (n - len + 1);
        }
        cout << ans % mod << endl;
    }
    else if(n <= 10){
        vector<int> use;
        for(int i = 1;i <= n;i++){
            use.push_back(i);
            vis[i] = true;
            dfs(1 , arr[i] , use);
            use.pop_back();
            vis[i] = false;
        }
        cout << ans.size() % mod << endl;
    }
}
