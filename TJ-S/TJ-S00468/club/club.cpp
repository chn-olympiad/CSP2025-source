#include<bits/stdc++.h>
using namespace std;
long long n,t,cnt1,cnt[4],s[4][101010];
long long ans,maxa,maxb,maxc;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        memset(cnt,0,sizeof(cnt));
        ans = 0;
        cin>>n;
        cnt1 = n/2;
        for(int i=1;i<=n;i++){
            cin>>s[1][i]>>s[2][i]>>s[3][i];
        }
        if(n==2){
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    if(i!=j){
                        ans = max(ans,s[i][1]+s[j][2]);
                    }
                }
            }
        }if(n==4){
            for(int i=1;i<=3;i++){
                cnt[i]++;
                for(int j=1;j<=3;j++){
                    cnt[j]++;
                    for(int k=1;k<=3;k++){
                        cnt[k]++;
                        for(int l=1;l<=3;l++){
                            cnt[l]++;
                            if(cnt[1]<=cnt1&&cnt[2]<=cnt1&&cnt[3]<=cnt1){
                                ans = max(ans,s[i][1]+s[j][2]+s[k][3]+s[l][4]);
                            }
                            cnt[l]--;
                        }
                        cnt[k]--;
                    }
                    cnt[j]--;
                }
                cnt[i]--;
            }
        }if(n==10){
            for(int i=1;i<=3;i++){
                cnt[i]++;
                for(int j=1;j<=3;j++){
                    cnt[j]++;
                    for(int k=1;k<=3;k++){
                        cnt[k]++;
                        for(int l=1;l<=3;l++){
                            cnt[l]++;
                            for(int q=1;q<=3;q++){
                                cnt[q]++;
                                for(int w=1;w<=3;w++){
                                    cnt[w]++;
                                    for(int e=1;e<=3;e++){
                                        cnt[e]++;
                                        for(int r=1;r<=3;r++){
                                            cnt[r]++;
                                            for(int t=1;t<=3;t++){
                                                cnt[t]++;
                                                for(int y=1;y<=3;y++){
                                                    cnt[y]++;
                                                    if(cnt[1]<=cnt1&&cnt[2]<=cnt1&&cnt[3]<=cnt1){
                                                        ans = max(ans,s[i][1]+s[j][2]+s[k][3]+s[l][4]+s[q][5]+s[w][6]+s[e][7]+s[r][8]+s[t][9]+s[y][10]);
                                                    }
                                                    cnt[y]--;
                                                }
                                                cnt[t]--;
                                            }
                                            cnt[r]--;
                                        }
                                        cnt[e]--;
                                    }
                                    cnt[w]--;
                                }
                                cnt[q]--;
                            }
                            cnt[l]--;
                        }
                        cnt[k]--;
                    }
                    cnt[j]--;
                }
                cnt[i]--;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
