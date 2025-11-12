#include <bits/stdc++.h>
using namespace std;
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > qa,qb,qc;
struct node{
    int dat,id;
}a[100005][4];
bool cmp(node x,node y){
    return x.dat > y.dat;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        while(qa.size()){
            qa.pop();
        }
        while(qb.size()){
            qb.pop();
        }
        while(qc.size()){
            qc.pop();
        }
        for(int i = 1;i <= n;i++){
            cin >> a[i][1].dat >> a[i][2].dat >> a[i][3].dat;
            a[i][1].id = 1;
            a[i][2].id = 2;
            a[i][3].id = 3;
            sort(a[i] + 1,a[i] + 3 + 1,cmp);
        }
        long long ans = 0;
        for(int i = 1;i <= n;i++){
            ans += a[i][1].dat;
            if(a[i][1].id == 1){
                if(qa.size() < n / 2){
                    qa.push({a[i][1].dat - a[i][2].dat,i});
                }else{
                    int x = qa.top().second;
                    if(a[x][1].dat - a[x][2].dat < a[i][1].dat - a[i][2].dat){
                        qa.pop();
                        qa.push({a[i][1].dat - a[i][2].dat,i});
                        ans -= a[x][1].dat - a[x][2].dat;
                        if(a[x][2].id == 2){
                            qb.push({a[x][1].dat - a[x][2].dat,x});
                        }else{
                            qc.push({a[x][1].dat - a[x][2].dat,x});
                        }
                    }else{
                        ans -= a[i][1].dat - a[i][2].dat;
                        if(a[i][2].id == 2){
                            qb.push({a[i][1].dat - a[i][2].dat,i});
                        }else{
                            qc.push({a[i][1].dat - a[i][2].dat,i});
                        }
                    }
                }
            }else if(a[i][1].id == 2){
                if(qb.size() < n / 2){
                    qb.push({a[i][1].dat - a[i][2].dat,i});
                }else{
                    int x = qb.top().second;
                    if(a[x][1].dat - a[x][2].dat < a[i][1].dat - a[i][2].dat){
                        qb.pop();
                        qb.push({a[i][1].dat - a[i][2].dat,i});
                        ans -= a[x][1].dat - a[x][2].dat;
                        if(a[x][2].id == 1){
                            qa.push({a[x][1].dat - a[x][2].dat,x});
                        }else{
                            qc.push({a[x][1].dat - a[x][2].dat,x});
                        }

                    }else{
                        ans -= a[i][1].dat - a[i][2].dat;
                        if(a[i][2].id == 1){
                            qa.push({a[i][1].dat - a[i][2].dat,i});
                        }else{
                            qc.push({a[i][1].dat - a[i][2].dat,i});
                        }
                    }
                }
            }else{
                if(qc.size() < n / 2){
                    qc.push({a[i][1].dat - a[i][2].dat,i});
                }else{
                    int x = qc.top().second;
                    if(a[x][1].dat - a[x][2].dat < a[i][1].dat - a[i][2].dat){
                        qc.pop();
                        qc.push({a[i][1].dat - a[i][2].dat,i});
                        ans -= a[x][1].dat - a[x][2].dat;
                        if(a[x][2].id == 1){
                            qa.push({a[x][1].dat - a[x][2].dat,x});
                        }else{
                            qb.push({a[x][1].dat - a[x][2].dat,x});
                        }

                    }else{
                        ans -= a[i][1].dat - a[i][2].dat;
                        if(a[i][2].id == 1){
                            qa.push({a[i][1].dat - a[i][2].dat,i});
                        }else{
                            qb.push({a[i][1].dat - a[i][2].dat,i});
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }




    return 0;
}