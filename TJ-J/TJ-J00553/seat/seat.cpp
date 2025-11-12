#include <bits/stdc++.h>
using namespace std;

int seatlist[11][11],scorelist[103];
int r,n,m,tot,flag=1;
bool bflag;
bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin >> n >> m;
    tot=n*m;
    for(int i=1;i<=tot;i++){
        cin >> scorelist[i];
    }
    r=scorelist[1];
    sort(scorelist+1,scorelist+tot+1,cmp);

    for(int x=1;x<=m;x++){
        if(bflag) break;
        else if(x%2==0){
            for(int i=n;i>=1;i--){
                seatlist[i][x]=scorelist[flag];
                if(scorelist[flag]==r){
                    cout << x <<" "<< i;
                    bflag=1;break;
                }
                flag++;
            }
        }else if(x%2==1){
            for(int i=1;i<=n;i++){
                seatlist[i][x]=scorelist[flag];
                if(scorelist[flag]==r){
                    cout << x <<" "<< i;
                    bflag=1;break;
                }
                flag++;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
