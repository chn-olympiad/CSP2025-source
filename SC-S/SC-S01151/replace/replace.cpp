#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
struct sl{
    string s;
}s1[200010],s2[200010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i].s>>s2[i].s;
    }
    string t1,t2;
    while(q--){
        cin>>t1>>t2;
        if(sizeof(t1)!=sizeof(t2)){
            cout<<0<<endl;
        }else{
            for(int i=0;i<=sizeof(t1);i++){
                for(int j=1;j<=n;j++){
                    if(t1[i]==s1[j].s[0]&&t2[i]==s2[j].s[0]){
                            int flag=1;
                        for(int k=1;k<=sizeof(s1[j].s);k++){
                            if(t1[i+k]!=s1[j+k].s[0]||t2[i+k]!=s2[j+k].s[0]){
                                flag=0;
                                break;
                            }
                        }
                        if(flag)ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
};
