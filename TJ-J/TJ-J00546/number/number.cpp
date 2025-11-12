#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    char a[100000];
    int n=1;
    for(int i=0;i<=s.size()-1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[n]=s[i];
            n++;
        }
    }for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(a[j]<a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i];
    }

    return 0;
}
