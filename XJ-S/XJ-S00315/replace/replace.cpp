#include<iostream>
using namespace std;
const int N=2e5+10;
int n,q;
pair<string,string> s[N];
pair<string,string> t[N];
int s1h[N],s1t[N],s2h[N],s2t[N],ds[N];
int ans=0;
int sum=0;
void solve1(){
    for(int i=1;i<=q;i++){
        ans=0;
        if(t[i].first.size()!=t[i].second.size()){
            cout<<"0"<<'\n';
            continue;
        }
        for(int j=1;j<=n;j++){
            for(int k=0;k<t[i].first.size();k++){
                bool flag=true;
                for(int head=k;head<k+s[j].first.size();head++){
                    if(t[i].first[head]!=s[j].first[head-k]){
                        k=head;
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    string ss=t[i].first;
                    for(int head=k;head<k+s[j].first.size();head++){
                        ss[head]=s[j].second[head-k];
                    }
                    if(ss==t[i].second){
                        ans++;
                        break;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return ;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i].first>>s[i].second;
        sum+=s[i].first.size();
        sum+=s[i].second.size();
    }
    for(int i=1;i<=q;i++){
        cin>>t[i].first>>t[i].second;
    }
    if(n<=1000&&sum<=2000){
        solve1();
        return 0;
    }
    for(int i=1;i<=n;i++){
        int idxa,idxb;
        for(int j=0;j<s[i].first.size();j++){
            if(s[i].first[j]=='b'){
                s1h[i]=j;
                s1t[i]=s[i].first.size()-j-1;
                idxa=j;
            }
            if(s[i].second[j]=='b'){
                s2h[i]=j;
                s2t[i]=s[i].second.size()-j-1;
                idxb=j;
            }
        }
        ds[i]=idxb-idxa;
    }
    for(int i=1;i<=q;i++){
        int ans=0;
        int idxa,idxb;
        int t1h,t1t,t2h,t2t;
        if(t[i].second.size()!=t[i].first.size()){
            cout<<"0"<<'\n';
            continue;
        }
        for(int j=0;j<t[i].first.size();j++){
            if(t[i].first[j]=='b'){
                t1h=j;
                t1t=t[i].first.size()-j-1;
                idxa=j;
            }
            if(t[i].second[j]=='b'){
                t2h=j;
                t2t=t[i].second.size()-j-1;
                idxb=j;
            }
        }
        int dt=idxb-idxa;
        for(int i=1;i<=n;i++){
            if(ds[i]==dt){
                if(t1h<s1h[i]&&t1t<s1t[i]&&t2h<s2h[i]&&t2t<s2t[i]){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}