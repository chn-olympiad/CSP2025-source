#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s,c="";
cin>>s;
int a=0;
for(int i=0;i<s.length();i++){
    if(s[i]>='z' && s[i]<='z'){
        a++;

    }
    else{
        c+=s[i];
    }
}
int sum=c.length();
if(sum==1) {
        cout<<c<<endl;
        return 0;
}
else{
for(int i=0;i<sum;i++){
    int maxj=i;
    for(int j=i+1;j<=sum;j++){
        if(c[maxj]<c[j]){
        maxj=j;
    }
    }
    swap(c[i],c[maxj]);
}
}
cout<<c<<endl;




return 0;
}
