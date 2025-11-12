#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
int nums[MAXN];
bool compare(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    cin>>str;
    int p=0;
    for(int i=0;i<str.size();i++){
        if(str[i]>='0'&&str[i]<='9') nums[p++]=str[i]-'0';
    }
    int n=p;
    sort(nums,nums+n,compare);
    for(int i=0;i<n;i++) cout<<nums[i];
    cout<<"\n";
    return 0;
}