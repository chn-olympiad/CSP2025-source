#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int a[100005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int t=0;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]>='a'&&s[i]<='z'){

        }else{
            a[i]=s[i]-48;
            t++;
        }
    }
    sort(a,a+n+1,cmp);
    for(int i=0;i<t;i++){
        cout<<a[i];
    }
    return 0;
}
