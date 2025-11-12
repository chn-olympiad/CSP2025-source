#include <iostream>
#include <cstdio>
using namespace std;

string s1[200005],s2[200005];
int te1[200005],te2[200005];

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        for(int j=0;j<s1[i].size();j++){
            if(s1[i][j]=='b'){
                te1[i]=j;
                break;
            }
        }
        for(int j=0;j<s2[i].size();j++){
            if(s2[i][j]=='b'){
                te2[i]=j;
                break;
            }
        }
    }
    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        if(t1.size()>2000){
            int temp1=0,temp2=0,ans=0;
            for(int i=0;i<t1.size();i++){
                if(t1[i]=='b'){
                    temp1=i;
                    break;
                }
            }
            for(int i=0;i<t2.size();i++){
                if(t2[i]=='b'){
                    temp2=i;
                    break;
                }
            }
            for(int i=1;i<=n;i++){
                if(temp1>=te1[i]&&temp2>=te2[i]&&(s1[i].size()-te1[i])<=(t1.size()-temp1)&&(s2[i].size()-te2[i])<=(t2.size()-temp2)
                   &&(temp2-temp1)==(te2[i]-te1[i])){
                    ans++;
                }
            }
            cout << ans << endl;
        }else{
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=0;j<t1.size();j++){
                    string temp="";
                    for(int k=j,h=0;h<s1[i].size()&&k<t1.size();k++,h++){
                        temp=temp+t1[k];
                    }
                    if(temp==s1[i]){
                        string temp2=t1;
                        for(int k=j,h=0;h<s1[i].size()&&k<t1.size();k++,h++){
                            temp2[k]=s2[i][h];
                        }
                        if(temp2==t2){
                            ans++;
                        }
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
