#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1000010];
ll n,b[1000010],c;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            b[++c]=s[i]-'0';
        }
    }
    sort(b+1,b+c+1);
    for(int i=c;i>=1;i--){
        printf("%lld",b[i]);
    }
    return 0;
}
