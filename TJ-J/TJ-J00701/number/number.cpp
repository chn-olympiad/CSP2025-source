#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e8+10;
int a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long n=s.size(),m=0;
    for(long long i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            m++;
            a[m]=int(s[i]-'0');
        }
    }

    sort(a+1,a+1+m);
    for(long long i=m;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
