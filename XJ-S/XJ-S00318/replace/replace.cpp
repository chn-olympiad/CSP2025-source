#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int n,q;
char s[maxn][2][2*maxn];
char t[maxn][2][2*maxn];
char l[maxn];
long long ans;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>(s[i][0]+1);
        cin>>(s[i][1]+1);
        l[i]=strlen(s[i][0]+1);
    }
    int l1,l2;
    bool flg;
    int mn,mx;
    for(int i=1;i<=q;i++){
        cin>>(t[i][0]+1);
        cin>>(t[i][1]+1);
        l1=strlen(t[i][0]+1);
        l2=strlen(t[i][1]+1);
        mn=l1, mx=1;
        for(int w=1;w<=l1;w++){
            if(t[i][0][w]!=t[i][1][w]){
                mn=min(w,mn);
                mx=w;
            }
        }
        if(l1!=l2){
            cout<<"0"<<endl;
            continue;
        }
        ans=0;
        for(int k=1;k<=n;k++){
            for(int j=1;j<=(l1-l[k]+1);j++){
                flg=1;
                for(int w=j;w<=(j+l[k]-1);w++){
                    if(s[k][0][w-j+1]!=t[i][0][w]) flg=0;
                    if(s[k][1][w-j+1]!=t[i][1][w]) flg=0;
                }
                if(flg){
                    if(j<=mn) if(mx<=(j+l[k]-1)) ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}