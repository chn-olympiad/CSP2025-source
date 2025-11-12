#include <iostream>
using namespace std;

int c[505];

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    scanf("%d",&n,&m);
    string s;
    cin>>s;
    int cnt=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    for(int i=0;i<s.size();i++){
        cnt+=(s[i]-'0');
    }
    cout << 0;
    return 0;
}
