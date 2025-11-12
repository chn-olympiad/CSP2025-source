#include <bits/stdc++.h>
using namespace std;
//======调试======
bool debug = false;
//================
int a[105];//用于保存考生成绩
int xiaor,n,m,x=1,y=1;//x为列，y为行，现增加y，在增加x(y的最大值为n，x的最大值为m)
bool going_down = true;

bool cmp(int a,int b){
    return a > b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n*m;i++){
        cin >> a[i];
    }
    xiaor = a[0];
    sort(a,a+n*m,cmp);

    for(int i=0;i<n*m;i++){
        if(a[i]==xiaor){
            xiaor = i + 1;
            break;
        }
    }
    //模拟路径
    for(int i=1;i<xiaor;i++){
        if(going_down==true){
            if(y == m){
                x++;
                going_down = false;
            }else{
                y++;
            }
        }else{
            if(y == 1){
                x++;
                going_down = true;
            }else{
                y--;
            }
        }
    }
    cout << x <<' '<< y;
}