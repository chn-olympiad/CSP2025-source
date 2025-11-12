#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
int main(){
    int n=10000,m=1000000,k=10;
    cout<<n<<" "<<m<<" "<<k<<"\n";
    for (int i=2;i<=n;i++)
    cout<<rnd()%(i-1)+1<<" "<<i<<" "<<rnd()%1000000000+1<<"\n";
    for (int i=n;i<=m;i++){
        int x=rnd()%n+1,y=rnd()%n+1;
        while(x==y)x=rnd()%n+1,y=rnd()%n+1;
        cout<<x<<" "<<y<<" "<<rnd()%1000000000+1<<"\n";
    }
    for (int i=1;i<=k;i++){
        for (int j=0;j<=n;j++)
        cout<<rnd()%1000000000+1<<" ";cout<<"\n";
    }
}