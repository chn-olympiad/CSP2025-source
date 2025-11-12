#include<bits/stdc++.h>
#define cir(i,a,b) for(auto i=a;i<b;++i)
using namespace std;
ifstream inf("club.in");
ofstream ouf("club.out");
using lint=long long;
int main(){
    ios::sync_with_stdio(false),inf.tie(nullptr);
    int T;inf>>T;
    while(T--) []{
        int n;inf>>n;
        vector<tuple<lint,lint,lint>> info(n);
        for(auto&[a,b,c]:info) inf>>a>>b>>c;
        vector<pair<lint,int>> s1,s2,s3;
        cir(i,0,n){
            const auto[a,b,c]=info[i];
            if(max({a,b,c})==a){
                s1.emplace_back(a-max(b,c),i);
            }else if(max({a,b,c})==b){
                s2.emplace_back(b-max(a,c),i);
            }else{
                s3.emplace_back(c-max(a,b),i);
            }
        }
        sort(s1.begin(),s1.end(),greater<>());
        sort(s2.begin(),s2.end(),greater<>());
        sort(s3.begin(),s3.end(),greater<>());
        auto ans=0ll;
        for(auto&[dw,p]:s1) ans+=get<0>(info[p]);
        for(auto&[dw,p]:s2) ans+=get<1>(info[p]);
        for(auto&[dw,p]:s3) ans+=get<2>(info[p]);
        while((int)(max({s1.size(),s2.size(),s3.size()}))>n/2){
            if((int)(s1.size())>n/2){
                ans-=s1.back().first;
                s1.pop_back();
            }else if((int)(s2.size())>n/2){
                ans-=s2.back().first;
                s2.pop_back();
            }else{
                ans-=s3.back().first;
                s3.pop_back();
            }
        }
        ouf<<ans<<'\n';
    }();
    return 0;
}
