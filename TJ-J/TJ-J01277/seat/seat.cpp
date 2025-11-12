#include <iostream>
#include <algorithm>
using namespace std;
int c[128],m,n,r,ans_x=1,ans_y=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin.tie(0); 
    cin >> n >> m >>r;
    for(int i=0;i<n*m-1;i++){
        cin >> c[i];
    }
    sort(c,c+n*m-1);
    for(int i=n*m-2;i>=0;i--){
        if(c[i]<r){
            printf("%d %d",ans_x,ans_y);
            break;
        }
        ans_y++;
        if(ans_y>n){
            ans_y=1;
            ans_x++;
        }
    }
    fclose(stdin);
    fclose(stdout);
}
