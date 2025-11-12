#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin>>s;
    int l=s.size();
    int a[l+1]={},c=0;
    for(int i=0 ; i<l ; i++){
        if(int(s[i])>=48 && int(s[i])<=57){
            a[c]=int(s[i])-48;
            c++;
        }
    }
    int abc;
    for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
            if(a[i]>a[j]){
                abc=a[i];
                a[i]=a[j];
                a[j]=abc;
            }
        }
    }
    for(int i=0;i<c;i++)
        cout<<a[i];

    fclose(stdin);
    fclose(stdout);
    return 0;
}
