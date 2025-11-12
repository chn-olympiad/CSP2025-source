#include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int arr[MAXN][3];
int _index[MAXN][3];
int clubs[3][MAXN];
bool joined_club[MAXN];
struct ClubMember{
    int _index,num;
    ClubMember():_index(0),num(0){}
    ClubMember(int _index,int num):_index(_index),num(num){}
    static bool compare(ClubMember &a,ClubMember &b){
        return a.num>b.num;
    }
    static ClubMember ClubMember_make(int _index,int num){
        ClubMember obj(_index,num);
        return obj;
    }
};
bool bigger(int a,int b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(joined_club,0,MAXN);
        int n;
        cin>>n;
        int clubs_ptr[3]={0};
        for(int i=0;i<n;i++){
            cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
            ClubMember t[3];
            t[0]=ClubMember::ClubMember_make(0,arr[i][0]);
            t[1]=ClubMember::ClubMember_make(1,arr[i][1]);
            t[2]=ClubMember::ClubMember_make(2,arr[i][2]);
            sort(t,t+3,ClubMember::compare);
            for(int j=0;j<3;j++) _index[i][t[j]._index]=j;
            if(t[0].num==t[1].num) _index[i][t[1]._index]=_index[i][t[0]._index];
            if(t[1].num==t[2].num) _index[i][t[2]._index]=_index[i][t[1]._index];
            for(int j=0;j<3;j++){
                if(_index[i][j]==0){
                    clubs[j][clubs_ptr[j]++]=i;
                }
            }
        }
        for(int i=0;i<3;i++){
            sort(clubs[i],clubs[i]+clubs_ptr[i],bigger);
        }
        int max_ptr=clubs_ptr[0];
        if(clubs_ptr[1]>max_ptr) max_ptr=clubs_ptr[1];
        if(clubs_ptr[2]>max_ptr) max_ptr=clubs_ptr[2];
        max_ptr=min(max_ptr,n/2);
        int clubs_itr_offset[3]={0},res=0;
        for(int i=0;i<max_ptr;i++){
            for(int j=0;j<3;j++){
                while(true){
                    int I=i+clubs_itr_offset[j];
                    if(I>=clubs_ptr[j]) break;
                    bool flag=true;
                    if(joined_club[clubs[j][I-clubs_itr_offset[j]]]){
                        flag=false;
                        clubs_itr_offset[j]++;
                    }
                    else{
                        int joiner=clubs[j][I];
                        res+=arr[joiner][j];
                        joined_club[joiner]=true;
                    }
                    if(flag) break;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(joined_club[i]) continue;
            ClubMember t[3];
            t[0]=ClubMember::ClubMember_make(0,arr[i][0]);
            t[1]=ClubMember::ClubMember_make(1,arr[i][1]);
            t[2]=ClubMember::ClubMember_make(2,arr[i][2]);
            sort(t,t+3,ClubMember::compare);
            for(int j=0;j<3;j++){
                if(clubs_ptr[t[j]._index]>=n/2) continue;
                clubs[j][clubs_ptr[t[j]._index]++]=i;
                res+=t[j].num;
                break;
            }
            joined_club[i]=true;
        }
        cout<<res<<"\n";
    }
    return 0;
}