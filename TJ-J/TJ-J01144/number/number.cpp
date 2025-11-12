#include<bits/stdc++.h>
using namespace std;
const long long MX=1e6+3;
char s[MX];
long long a[MX];
long long t=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    int len1= strlen(s);
    for(int i =0;i<len1;i++){
        if(s[i]>=48&&s[i]<=57){
            a[i]=s[i]-'0';
            t++;
        }
    }
    sort(a,a+len1);

    for(int i =len1-1;i>=len1-t;i--){
        cout<<a[i];

}
return 0;
}
