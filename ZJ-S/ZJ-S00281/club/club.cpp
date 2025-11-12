#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef pair<int, int> PII;
int t,n,a[N][3];
int sum[3];
long long ans=0;
int choose(int x,int k,int past=-1){
    int key;
    if(k==1) key=max(a[x][0],max(a[x][1],a[x][2]));
    else if(k==2) key = min(max(a[x][0], a[x][1]), min(max(a[x][0], a[x][2]), max(a[x][1], a[x][2])));
    else key = min(a[x][0], min(a[x][1], a[x][2]));
    if(a[x][0]==key&&past!=0) return 0;
    if(a[x][1]==key&&past!=1) return 1;
    return 2;
}
void clear(){
    sum[0] = sum[1] = sum[2] = 0;
    for(int i=1;i<=n;++i){
        a[i][0]=a[i][1]=a[i][2]=0;
    }
    // for (int i = 1; i <= 3;++ i){
    //     while (!q[i].empty())
    //         q[i].pop();
    // }
    ans = 0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        priority_queue<PII,vector<PII>,greater<PII> > q[3];
        scanf("%d",&n);
        // cout << n << '\n';
        for(int i=1;i<=n;++i) scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        for(int i=1;i<=n;++i){
            int j = choose(i, 1);
            int d1 = a[i][j] - a[i][choose(i,2,j)];
            // if(sum[j]>n/2)
            //     cout<<"Noooooooo!"<<'\n';
            if (sum[j] >= n / 2){
                int d0 = q[j].top().first;
                if (d0 < d1){
                    auto f = q[j].top();
                    q[j].pop();
                    sum[j] -= 1;
                    int x = f.second;
                    int id = choose(x, 2, j);
                    ans-=d0;
                    f.first = a[x][choose(x,2)]-a[x][choose(x,3)];
                    q[id].push(f);
                    sum[id] += 1;
                    // cout << "j:" << j << " id:" << id << '\n';
                }else{
                    j = choose(i,2,j);
                }
            }
            q[j].push({d1,i});
            ans += a[i][j];
            sum[j] += 1;
        }
        // cout <<n<<' '<< sum[0] << ' ' << sum[1] << ' ' << sum[2]<<'\n';
        printf("%d\n",ans);
        clear();
    }


    return 0;
}
