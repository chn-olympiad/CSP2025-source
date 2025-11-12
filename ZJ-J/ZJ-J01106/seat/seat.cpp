#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,target = -1;
    cin>>n>>m;
    vector<int> score;
    for(int i=1;i<=n*m;i++){
        int x;
        cin>>x;
        score.push_back(x);
        if(i == 1){
            target = x;
        }
    }
    sort(score.begin(), score.end(), greater<int>());

    bool flag = false; // f 为往下 t 为往上
    int px = 1, py = 1;
    for(int i=0;i<n*m;i++){
        if(score[i] == target){
            cout<<px<<" "<<py<<endl;
        }
        if(!flag){
            if(py == n){
                flag = true;
                px++;
            }
            else{
                py++;
            }
        }else{
            if(py == 1){
                flag = false;
                px++;
            }else{
                py--;
            }
        }
    }
    return 0;
}