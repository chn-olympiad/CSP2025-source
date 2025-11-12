#include<bits/stdc++.h>
#include<queue>
using namespace std;
int n , m , k , st , en , wi , ai , ci , sum;
//邻接链表
long long ans;
int kk[10020];
bool ifff[10020];
long long misaki[10020][10020];
bool iff[10020];
bool an;
struct node
{
    int start , end , wwi;
    friend bool operator < (node i , node j){
        return i.wwi > j.wwi || i.wwi == j.wwi && i.start > j.start;
    }
};

priority_queue <node> pq;
int main(){
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    cin >> n >> m >> k;
    for(int  i = 1 ; i <= m ; i++){
        cin >> st >> en >> wi;
        misaki[st][en] = wi;
        misaki[en][st] = wi;
        pq.push({st , en , wi});
        iff[st] = true;
        iff[en] = true;
    }
    int il = 1;

    for(int i = n + 1 ; i <= n ; i++){
        cin >> ci;
        for(int l = 1 ; l <= n - 1 ; l++){
            cin >> ai;
            misaki[i][l] = ai;
            misaki[l][i] = ai;
            iff[l] = true;
            pq.push({i , l , ai});
            if(ai != 0){
                an = true;
            }
        }
    }
    if(an == false){
        cout << '0' << '\n';
        return 0;
    }
    while(sum != n){
        node nd = pq.top();
        pq.pop();
        if(ifff[nd.start] == false && nd.start <= n || ifff[nd.end] == false && nd.end <= n){
            ans += nd.wwi;
            if(ifff[nd.start] == false && nd.start <= n){
                sum++;
            }
            else if(ifff[nd.end] == false && nd.end <= n){
                sum++;
            }
            ifff[nd.start] = true;
            ifff[nd.end] = true;
            
        }
        
    }
    cout << ans;
}
