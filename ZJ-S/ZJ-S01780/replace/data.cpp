#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
int main(){
    int n=200000,q=200000;
    cout<<n<<" "<<q<<"\n";
    for (int i=1;i<=n;i++,cout<<"\n")
    for (int j=1;j<=25;j++)
    if(j==13)cout<<" ";
    else cout<<(char)(rnd()%26+'a');
    // cout<<"aaaaaaaaab baaaaaaaaa\n";
    for (int i=1;i<=q;i++,cout<<"\n")
    for (int j=1;j<=25;j++)
    if(j==13)cout<<" ";
    else cout<<(char)(rnd()%26+'a');
    // cout<<"aaaaaaaaab baaaaaaaaa\n";
}