#include<bits/stdc++.h>
using namespace std;
int n;/*AFOed
string HAdd(string a,string b){
    string c="";
    if(a.size()<b.size()) swap(a,b);
    int k=0,j=0;
    for(int i=0;i<a.size();i++){
        if(b.size()<i) k=int(a[i]-'0')+j,j=0;
        else k=int(a[i]-'0')+int(b[i]-'0')+j,j=0;
        while(k>9) k-=10,j++;
        c+=char(k+'0');
    }
    if(j>0) c+=char(j+'0');
    return c;
}
int HCmp(string a,string b){
    if(a.size()>b.size()) return 1;
    if(a.size()<b.size()) return -1;
    for(int i=0;i<a.size();i++){
        if(a[i]>b[i]) return 1;
        if(a[i]<b[i]) return -1;
    }
    return 0;
}
string HSub(string a,string b){
    if(HCmp(a,b)==0) return "0";
    string c="";
    int k=0,j=0;
    for(int i=0;i<a.size();i++){
        if(b.size()<i) k=int(a[i]-'0')+j,j=0;
        k=int(a[i]-'0')-int(b[i]-'0')+j,j=0;
        while(k<0) k+=10,j--;
        c+=char(k+'0');
    }
    return c;
}
string HMutI(string a,int b){
    string c="";
    int k=0,j=0;
    for(int i=0;i<a.size();i++){
        k=int(a[i]-'0')*b+j,j=0;
        while(k>9) k-=10,j++;
        c+=char(k+'0');
    }
    if(j>0) c+=char(j+'0');
    return c;
}
string HMutH(string a,string b){
    string c="0";
    if(a.size()<b.size()) swap(a,b);
    for(int i=0;i<b.size();i++){
        string p=HMutI(a,int(b[i]-'0'));
        for(int j=0;j<=i;j++) p="0"+p;
        c=HAdd(p,c);
    }
    return c;
}
string HMod(string a){
    const string MODS="998244353";
    if(HCmp(a,MODS)!=1) a=HSub(a,MODS);
    return a;
}
string HDiv(string a,string b){
    string c="0";
    if(a.size()<b.size()) swap(a,b);
    for(int i=0;i<b.size();i++){
        string p=HMutI(a,int(b[i]-'0'));
        for(int j=0;j<=i;j++) p="0"+p;
        c=HAdd(p,c);
    }
    return c;
}*/
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    vector<int>v(n);
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    if(n==3){
        sort(v.begin(),v.end());
        if(v[0]+v[1]>v[2]) printf("1");
        else printf("0");
    }
    return 0;
}
