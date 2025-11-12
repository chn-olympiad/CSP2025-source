#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
string s;
int ans;
int a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>s;
    int x=0;
    for(int i=1;i<=s.length();i++){
        if(s[i]==0||s[i]==1||s[i]==2||s[i]==3||s[i]==4||s[i]==5||s[i]==6||s[i]==7||s[i]==8||s[i]==9){
            a[x]=s[i];
            x++;
        }
    }
    sort(a,a+x);
    int b[N],y=0;
    for(int i=x;i>=0;i++){
        b[y]=a[i];
        y++;
    }
    for(int i=0;i<y;i++){
        int c=1;
        ans+=b[i]*c;
        c*=10;
    }
    cout<<ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
