#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[100005][5];
int t[100005],cntt[5],ans,cg[100005];

int q[5][100005];

void dg(int c,int sum){
    if (c == 1+n){
        ans = max(ans,sum);
        //for (int i = 1;i<=n;i++){
        //    cout<<t[i]<<" ";
        //}
        //cout<<"ans"<<sum<<endl;
        return ;
    }
    for (int i = 1;i<=3;i++){
        if(cntt[i]>=(n/2))continue;
        t[c] = i;
        cntt[i] ++ ;
        dg(c+1,sum+a[c][i]);
        cntt[i]--;
    }
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;

    while (T--){
        cin>>n;
        ans = 0;
        int tp = 0;
        for (int i = 1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if (a[i][2] == 0 && a[i][3] == 0)tp++;
        }

        if (n<=10){
                //chushihua!!!!!!!!!!!!!!!!
            memset(cntt,0,sizeof(cntt));
            ans = 0;
            dg(1,0);
            cout<<ans<<endl;
        }
        else if (tp == n){
            for (int i = 1;i<=n;i++){
                ans += a[i][1];
            }
            cout<<ans<<endl;
        }

        else {
            cntt[1] = cntt[2] = cntt[3] = 0;
            for (int i = 1;i<=n;i++){
                if (a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
                    cntt[1]++;
                    cg[i] = min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
                    ans += a[i][1];
                    q[1][cntt[1]] = cg[i];
                }
                else if (a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
                    cntt[2]++;
                    cg[i] = min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
                    ans += a[i][2];
                    q[2][cntt[2]] = cg[i];
                }
                else if (a[i][3]>=a[i][2] && a[i][3]>=a[i][1]){
                    cntt[3]++;
                    cg[i] = min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
                    ans += a[i][3];
                    q[3][cntt[3]] = cg[i];
                }
            }

            int lmt = n/2;

            if (cntt[1] <= lmt && cntt[2]<=lmt && cntt[3] <= lmt){
                cout<<ans<<endl;
            }
            else {
                int idx =1;
                for(int i = 1;i<=3;i++){
                    int flag = 0;
                    for (int j = 1;j<=3;j++){
                        if (i == j)continue;
                        if (cntt[j]>cntt[i]){
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0){
                        idx = i;
                        break;
                    }
                }

                sort(q[idx]+1,q[idx]+cntt[idx]+1);

                for (int i = 1;i<=cntt[idx]-lmt;i++){
                    ans-=q[idx][i];
                }

                cout<<ans<<endl;
            }
        }
    }

    return 0;
}
