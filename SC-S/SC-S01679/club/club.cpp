#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
int n ,t , ton[5];
struct zus{
    int zu1 , zu2 , zu3 , poi;
}a[MAXN];

int get_max(int xx){
    if(a[xx].zu1 > a[xx].zu2){
        if(a[xx].zu1 > a[xx].zu3){
            return 1;
        }
    }
    if(a[xx].zu2 > a[xx].zu1){
        if(a[xx].zu2 > a[xx].zu3){
            return 2;
        }
    }
    if(a[xx].zu3 > a[xx].zu1){
        if(a[xx].zu3 > a[xx].zu2){
            return 3;
        }
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin >> t;
    cout <<endl;
    while(t--){
        memset(ton , 0 , sizeof(ton));

        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i].zu1 >> a[i].zu2 >> a[i].zu3;
        }

        int ans = 0;
        for(int i = 1;i <= n;i++){
            int maxx = INT_MIN;
            maxx = max(maxx,max(a[i].zu1,max(a[i].zu2,a[i].zu3)));
            if(ton[get_max(i)] >= n/2){
                int num = get_max(i);
                if(num == 1){
                    maxx = max(a[i].zu2,a[i].zu3);
                    if(maxx == a[i].zu2 ){
                        if(ton[2] < n/2){
                            ton[2]++;
                            ans += maxx;
                            a[i].poi = 2;
                        }
                        else{
                            for(int j = i;j > 0;j--){
                                if(a[j].zu2 > a[i].zu2){
                                    ans -= a[i].zu2;
                                    ans += a[j].zu2;
                                    a[j].poi = 2;
                                    break;
                                }
                            }
                        }
                    }
                    else if(maxx == a[i].zu3 ){
                        if(ton[3] < n/2){
                            ton[3]++;
                            ans += maxx;
                            a[i].poi = 3;
                        }
                        else{
                            for(int j = i;j > 0;j--){
                                if(a[j].zu3 > a[i].zu3 ){
                                    ans -= a[i].zu3;
                                    ans += a[j].zu3;
                                    a[j].poi = 3;
                                    break;
                                }
                            }

                        }
                    }
                }
                else if(num == 2){
                    maxx = max(a[i].zu1,a[i].zu3);
                    if(maxx = a[i].zu1 ){

                        if(ton[1] < n/2){
                            ton[1]++;
                            ans += maxx;
                            a[i].poi = 1;
                        }
                        else{
                            for(int j = i;j > 0;j--){
                                if(a[j].zu1 < a[i].zu1){
                                    ans -= a[i].zu1;
                                    ans += a[j].zu1;
                                    a[j].poi = 1;
                                    break;
                                }
                            }
                        }
                    }
                    else if(maxx == a[i].zu3 ){
                        if(ton[3] < n/2){
                            ton[3]++;
                            ans += maxx;
                            a[i].poi = 3;
                        }
                        else{
                            for(int j = i;j > 0;j--){
                                if(a[j].zu3 < a[i].zu3){
                                    ans -= a[i].zu3;
                                    ans += a[j].zu3;
                                    a[j].poi = 3;
                                    break;
                                }
                            }
                        }
                    }
                }
                else if(num == 3){
                    maxx = max(a[i].zu1,a[i].zu2);
                    if(maxx = a[i].zu1){
                        if(ton[1] < n/2){
                            ton[1]++;
                            ans += maxx;
                            a[i].poi = 1;
                        }
                        else{
                            for(int j = i;j > 0;j--){
                                if(a[j].zu1 < a[i].zu1){
                                    ans -= a[i].zu1;
                                    ans += a[j].zu1;
                                    a[j].poi = 1;
                                    break;
                                }
                            }
                        }
                    }
                    else if(maxx == a[i].zu2){
                        if(ton[2] < n/2){
                            ton[2]++;
                            ans += maxx;
                            a[i].poi = 2;
                        }
                        else{
                            for(int j = i;j > 0;j--){
                                if(a[j].zu2 < a[i].zu2){
                                    ans -= a[i].zu2;
                                    ans += a[j].zu2;
                                    a[j].poi = 2;
                                    break;
                                }
                            }

                        }
                    }
                }
            }
            ton[get_max(i)]++;
            ans += maxx;
            a[i].poi = get_max(i);
        }
        cout << ans << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}