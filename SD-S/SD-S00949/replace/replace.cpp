#include <bits/stdc++.h>
using namespace std;
#define N 200050
struct node{
    string a,b;
    int len;
}s[N];
int n,q;
char lin[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].b;
        s[i].len=s[i].a.size();
    }
    while(q--){
        int ans=0;
        string s1,s2;
        cin>>s1>>s2;
        if(s1.size()!=s2.size()){
            cout<<"0"<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++){
            if(s1.find(s[i].a)!=-1){
                int cnt=0;
                int xb=s1.find(s[i].a);
                int xb_fb=xb;
                while(cnt!=s[i].len){
                    lin[cnt]=s1[xb];
                    s1[xb++]=s[i].b[cnt++];
                }
                if(s1==s2) ans++;
                cnt=0;
                while(cnt!=s[i].len){
                    s1[xb_fb++]=lin[cnt++];
                }
            }else{
                continue;
            }
        }
        cout<<ans<<"\n";
    }
	return 0;
}


