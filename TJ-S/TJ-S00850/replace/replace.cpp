#include <bits/stdc++.h>
using namespace std;
string s[200005][7];
int n,q,sum;
struct stu{
    int a,b;
};
stu find_(string a,string b){
    int l=a.size();
    stu ans;
    for (int i=0;i<l;i++){
        if (a[i] != b[i]){
            ans.a = i;
            break;
        }
    }
    for (int i=l-1;i>=0;i--){
        if (a[i] != b[i]){
            ans.b = i;
            break;
        }
    }
    return ans;
}
string did(string s,stu ans){
    string s2="";
    for (int i=ans.a;i<=ans.b;i++){
        s2 += s[i];
    }
    return s2;
}
string did2(string s1,string s2,stu ans){
    string sn="";
    int x=ans.a,y=ans.b;
    for (int i=0;i<s2.size();i++){
        if (i >= x && i <= y){
            sn += s1[i-x];
        }else{
            sn += s2[i];
        }
    }
    return sn;
}
int is_(string a,string b){
    int la = a.size(),lb = b.size();
    for (int i=0;i<=lb-la;i++){
        stu ans = {i,i+la-1};
        if (did(b,ans) == a){
            return i;
        }
    }
    return -1;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin >> n >> q;
    for (int i=1;i<=n;i++){
        cin >> s[i][1] >> s[i][2];
        /*stu ans=find_(s[i][1],s[i][2]);
        s[i][1] = did(s[i][1],ans);
        s[i][2] = did(s[i][2],ans);*/
    }
    while (q--){
        sum = 0;
        string s1,s2;
        cin >> s1 >> s2;
        /*stu ans=find_(s1,s2);
        s1 = did(s1,ans);
        s2 = dis(s2,ans);*/
        for (int i=1;i<=n;i++){
            string sa=s[i][1],sb=s[i][2];
            int is=is_(sa,s1);
            //printf("is:%d\n",is);
            if (is!=-1){
                stu ans={is,is+sa.size()-1};
                string ss1=did2(sb,s1,ans);//,ss2=did2(sb,s2,ans);
                //cout << "compare a&b:" << ss1 << " " << ss2 << " and ans is:" << ans.a << " " <<ans.b << endl;
                if (ss1==s2){
                    sum++;
                }
            }
        }
        cout << sum << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

