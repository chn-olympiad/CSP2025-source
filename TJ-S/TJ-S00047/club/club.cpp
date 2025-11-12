#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
using namespace std;
unsigned int t;
unsigned int n,sum;
deque<unsigned int> mini[3][3];
bool coma(unsigned int a,unsigned int b){return mini[0][0][a]>mini[0][0][b];}
bool comb(unsigned int a,unsigned int b){return mini[1][0][a]>mini[1][0][b];}
bool comc(unsigned int a,unsigned int b){return mini[2][0][a]>mini[2][0][b];}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n;
        unsigned int a[n][3];
        for(int i=0;i<n;i++) for(int j=0;j<3;j++) cin>>a[i][j],sum+=a[i][j];
        for(int i=0;i<n;i++){
            if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) mini[0][0].push_back(a[i][0]-a[i][1]),mini[0][0].push_back(a[i][0]-a[i][2]),mini[0][1].push_back(i),mini[0][1].push_back(i),mini[0][2].push_back(1),mini[0][2].push_back(2);
            else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]) mini[1][0].push_back(a[i][1]-a[i][0]),mini[1][0].push_back(a[i][1]-a[i][2]),mini[1][1].push_back(i),mini[1][1].push_back(i),mini[1][2].push_back(0),mini[0][2].push_back(2);
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][0]) mini[2][0].push_back(a[i][2]-a[i][1]),mini[2][0].push_back(a[i][2]-a[i][0]),mini[2][1].push_back(i),mini[2][1].push_back(i),mini[2][2].push_back(1),mini[2][2].push_back(0);
        }
        unsigned int sortundera[mini[0][0].size()],sortunderb[mini[1][0].size()],sortunderc[mini[2][0].size()];
        for(int i=0;i<mini[0][0].size();i++) sortundera[i]=i;
        for(int i=0;i<mini[1][0].size();i++) sortunderb[i]=i;
        for(int i=0;i<mini[2][0].size();i++) sortunderc[i]=i;
        sort(sortundera,sortundera+mini[0][0].size(),coma);
        sort(sortunderb,sortunderb+mini[1][0].size(),comb);
        sort(sortunderc,sortunderc+mini[2][0].size(),comc);
        while(mini[0][0].size()>n/2&&mini[1][0].size()>n/2&&mini[2][0].size()>n/2){
            while(mini[0][0].size()>n/2){
                mini[mini[0][2][sortundera[0]]][0].push_back(a[mini[0][1][sortundera[0]]][mini[0][2][sortundera[0]]]-a[mini[0][1][sortundera[0]]][(mini[0][2][sortundera[0]]+1)%3]);
                mini[mini[0][2][sortundera[0]]][0].push_back(a[mini[0][1][sortundera[0]]][mini[0][2][sortundera[0]]]-a[mini[0][1][sortundera[0]]][(mini[0][2][sortundera[0]]+2)%3]);
                mini[mini[0][2][sortundera[0]]][1].push_back(mini[0][1][sortundera[0]]);
                mini[mini[0][2][sortundera[0]]][1].push_back(mini[0][1][sortundera[0]]);
                mini[mini[0][2][sortundera[0]]][2].push_back(mini[0][2][(sortundera[0]+1)%3]);
                mini[mini[0][2][sortundera[0]]][2].push_back(mini[0][2][(sortundera[0]+2)%3]);
                sum-=a[sortundera[0]][0];
                mini[0][0].pop_front();
                mini[0][1].pop_front();
                mini[0][2].pop_front();
            }
            sort(sortunderb,sortunderb+mini[1][0].size(),comb);
            sort(sortunderc,sortunderc+mini[2][0].size(),comc);
            while(mini[1][0].size()>n/2){
                mini[mini[1][2][sortunderb[0]]][0].push_back(a[mini[1][1][sortunderb[0]]][mini[0][2][sortunderb[0]]]-a[mini[0][1][sortunderb[0]]][(mini[0][2][sortunderb[0]]+1)%3]);
                mini[mini[1][2][sortunderb[0]]][0].push_back(a[mini[1][1][sortunderb[0]]][mini[0][2][sortunderb[0]]]-a[mini[0][1][sortunderb[0]]][(mini[0][2][sortunderb[0]]+2)%3]);
                mini[mini[1][2][sortunderb[0]]][1].push_back(mini[1][1][sortunderb[0]]);
                mini[mini[1][2][sortunderb[0]]][1].push_back(mini[1][1][sortunderb[0]]);
                mini[mini[1][2][sortunderb[0]]][2].push_back(mini[1][2][(sortunderb[0]+1)%3]);
                mini[mini[1][2][sortunderb[0]]][2].push_back(mini[1][2][(sortunderb[0]+2)%3]);
                sum-=a[sortundera[0]][1];
                mini[1][0].pop_front();
                mini[1][1].pop_front();
                mini[1][2].pop_front();
            }
            sort(sortundera,sortundera+mini[0][0].size(),coma);
            sort(sortunderc,sortunderc+mini[2][0].size(),comc);
            while(mini[2][0].size()>n/2){
                mini[mini[2][2][sortunderc[0]]][0].push_back(a[mini[2][1][sortunderc[0]]][mini[0][2][sortunderc[0]]]-a[mini[0][1][sortunderc[0]]][(mini[0][2][sortunderc[0]]+1)%3]);
                mini[mini[2][2][sortunderc[0]]][0].push_back(a[mini[2][1][sortunderc[0]]][mini[0][2][sortunderc[0]]]-a[mini[0][1][sortunderc[0]]][(mini[0][2][sortunderc[0]]+2)%3]);
                mini[mini[2][2][sortunderc[0]]][1].push_back(mini[2][1][sortunderc[0]]);
                mini[mini[2][2][sortunderc[0]]][1].push_back(mini[2][1][sortunderc[0]]);
                mini[mini[2][2][sortunderc[0]]][2].push_back(mini[2][2][(sortunderc[0]+1)%3]);
                mini[mini[2][2][sortunderc[0]]][2].push_back(mini[2][2][(sortunderc[0]+2)%3]);
                sum-=a[sortundera[0]][2];
                mini[2][0].pop_front();
                mini[2][1].pop_front();
                mini[2][2].pop_front();
            }
            sort(sortundera,sortundera+mini[0][0].size(),coma);
            sort(sortunderb,sortunderb+mini[1][0].size(),comb);
        }
        cout<<sum<<'\n';
    }
    return 0;
}
