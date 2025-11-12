#include <bits/stdc++.h>
using namespace std;
const int MAXN=200005;
struct ReplaceRule{
    string from,to;
    int cnt;
    ReplaceRule():cnt(0){}
    ReplaceRule(string from,string to,int cnt):from(from),to(to),cnt(cnt){}
    static ReplaceRule make(string from,string to,int cnt){
        ReplaceRule obj(from,to,cnt);
        return obj;
    }
    bool operator<(ReplaceRule &obj){
        return (this->from)<(obj.from);
    }
    bool operator==(ReplaceRule &obj){
        return ((this->from)==(obj.from))&&((this->to)==(obj.to));
    }
};
ReplaceRule replace_rules[MAXN],final_rules[MAXN];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    int rules_ptr=0;
    for(int i=0;i<n;i++){
        string from,to;
        cin>>from>>to;
        int l=0,r=from.size()-1;
        while(from[l]==to[l]) l++;
        while(from[r]==to[r]) r--;
        string rule_from,rule_to;
        for(int i=l;i<=r;i++){
            rule_from+=from[i];
            rule_to+=to[i];
        }
        replace_rules[rules_ptr++]=ReplaceRule::make(rule_from,rule_to,1);
    }
    sort(replace_rules,replace_rules+rules_ptr);
    int final_rules_ptr=0;
    for(int i=0;i<rules_ptr;i++){
        if(final_rules_ptr==0){
            final_rules[final_rules_ptr++]=replace_rules[i];
        }
        if(replace_rules[i]==final_rules[final_rules_ptr-1]){
            final_rules[final_rules_ptr-1].cnt+=replace_rules[i].cnt;
        }
        else{
            final_rules[final_rules_ptr++]=replace_rules[i];
        }
    }
    for(int i=0;i<q;i++){
        string req_from,req_to;
        cin>>req_from>>req_to;
        if(req_from.size()!=req_to.size()){
            cout<<"0\n";
            continue;
        }
        int l=0,r=req_from.size()-1;
        while(req_from[l]==req_to[l]) l++;
        while(req_from[r]==req_to[r]) r--;
        string simple_req_from,simple_req_to;
        for(int i=l;i<=r;i++){
            simple_req_from+=req_from[i];
            simple_req_to+=req_to[i];
        }
        l=0;r=final_rules_ptr-1;
        int res=0;
        while(l<=r){
            if(l==r){
                if(final_rules[l].from==simple_req_from&&final_rules[l].to==simple_req_to) res=final_rules[l].cnt;
                break;
            }
            int m=(r-l)/2+l;
            if(simple_req_from==final_rules[m].from&&final_rules[l].to==simple_req_to){
                res=final_rules[m].cnt;
                break;
            }
            if(simple_req_from<final_rules[m].from){
                r=m-1;
                continue;
            }
            if(simple_req_from>final_rules[m].from){
                l=m+1;
                continue;
            }
            else break;
        }
        cout<<res<<"\n";
    }
    return 0;
}