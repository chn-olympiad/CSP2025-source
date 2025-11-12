#include <bits/stdc++.h>
using namespace std;
int node(long long a,long long b){
    string s="",s1="",s2="";
    while(a){
        s+=a%2+'0';
        a/=2;
    }
    while(b){
        s1+=b%2+'0';
        b/=2;
    }
    if(s.size()>s1.size()){
        for(int i=s1.size();i<=s.size();i++){
            s1[i]='0';
        }
    }
    if(s1.size()>s.size()){
        for(int i=s.size();i<=s1.size();i++){
            s[i]='0';
        }
    }
    for(int i=0;i<s.size();i++){
        if(s1[i]==s[i]) s2[i]='1';
    }
    return stoi(s2);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,MAX=INT_MIN;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            int p=i,p1=j,l=j+1,l1=n-i+1,sum=0,sum1=0,cnt=0,cnt1=0;
            if(p<=p1){
                sum=a[p];
                cnt=1;
            }else{
                for(int k=p;k<=p1;k++){
                    sum=node(sum,a[k]);
                }
                cnt=p1-p;
            }
            if(l<=l1){
                sum=a[l];
                cnt1=1;
            }else{
                for(int k=l;k<=l1;l++){
                    sum1=node(sum,a[k]);
                }
                cnt1=l1-l;
            }
            if(sum==k or sum1==k){
                MAX=max(MAX,cnt);
            }
            else{
                MAX=max(MAX,cnt1);
            }
        }
    }
    cout<<MAX;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
