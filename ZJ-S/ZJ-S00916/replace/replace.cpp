#include <iostream>
using namespace std;
int judgepattern(string pat[2],string s1,string s2){
    int l = pat[0].length();
    int su = 0;
    for(int i = 0 ;i<s1.length()-l;++i){
        if(s1.replace(i,l,pat[0])==s2.replace(i,l,pat[1])){
            ++su;
        }
    }
    return su;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    scanf("%d%d",n,q);
    string yz[n][2];
    for(int i=0; i<n;++i){
        scanf("%s%s" , yz[i][0], yz[i][1]);
    }
    /*
    for(int i=0;i<n;++i){
        for(int j =0;j<2;++j){
            printf("%s",yz[i][j]);
        }
    }*/
    for(int i=0 ; i<q ;++i){
        int ans = 0;
        string wt[2];
        scanf("%s%s",wt[0],wt[1]);
        for(int j=0;j<n;++j){
            ans+=judgepattern(yz[j],wt[0],wt[1]);
        }
        printf("%d\n",ans);
    }
    return 0;
}