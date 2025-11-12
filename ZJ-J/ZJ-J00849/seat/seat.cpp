#include<bits/stdc++.h>
using namespace std;
int a[11][11]={};
int score[108]={};
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n=0,m=0;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>score[i];
    }
    int sc=score[0];
    sort(score,score+n*m,cmp);
    int indexx=0;
    int x=0,y=0;
    for(int i=0;i<m;i++){
        if(i%2==0){
            for(int j=0;j<n;j++){
                a[i][j]=score[indexx];
                indexx++;
                if(a[i][j]==sc){
                    x=i;
                    y=j;
                }
            }
        }
        else{
            for(int j=n-1;j>=0;j--){
                a[i][j]=score[indexx];
                indexx++;
                if(a[i][j]==sc){
                    x=i;
                    y=j;
                }
            }
        }
    }
    cout<<x+1<<" "<<y+1<<endl;
    return 0;
}
