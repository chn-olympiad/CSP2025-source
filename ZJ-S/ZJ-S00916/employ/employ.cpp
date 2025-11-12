#include<iostream>
using namespace std;
int cur = 0;
bool judge(string pattern,string nd,int nx[],int m){
    int fq=0;
    int ly=0;
    for(int i =0 ; i<pattern.length() ; ++i){
        int e = pattern[i];
        if (nx[e]<=fq or nd[i]=='0'){
            fq++;
        }
        else{
            ly++;
        }
    }
    if(ly>m){
        return true;
    }
    return false;
}
int pi(int n ){
    int ans = 1;
    for(int i=1;i<=n;i++){
        ans*=i;
    }
    return ans;
}
void geneA(int n,string tmp[],string t = ""){
        if(t.length()==n){
            tmp[cur]=t;
            cur++;
        }
        else{
            for(int i=1;i<=n;++i){
                bool flag = true;
                for(int j=0;j<t.length();++j){
                    if(char(i)==t[j]){
                        flag = false;
                        break;
                    }
                if(flag){
                    geneA(n,tmp,t+char(i));
                }
                }
            }
        }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    scanf("%d%d",n,m);
    string s;
    scanf("%s",s);
    int patience[m];
    scanf("%i",patience);
    int p =0;
    string tmp[pi(n)];
    geneA(n,tmp);
    for(string pt:tmp){
        if(judge(pt,s,patience,m)){
            ++p;
        }
    }
    printf("%d",p);
    return 0;
}