#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,s[225],finally[15][15],A=0,x=1,y=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){

            cin>>s[i];

    }
    int cushu=m;
    A=s[1];
    sort(s+1,s+n*m+1);
    int i=n*m;
        for(int q=1;q<=ceil(m/2.0);q++){
            for(int x=1;x<=n;x++){
                finally[x][y]=s[i--];

            }
            y++;cushu--;
            if(cushu>0)
            for(int x=n;x>=1;x--){
                finally[x][y]=s[i--];

            }
            y++;
        }

    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(finally[i][j]==A)
                cout<<j<<" "<<i;
        }
    }
    return 0;
}
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                         

