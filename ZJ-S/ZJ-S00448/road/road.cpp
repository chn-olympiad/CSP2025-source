#include <bits/stdc++.h>
using namespace std;

#define int long long
#define spa putchar(' ')
#define ero putchar('\n')
#define pii pair<int,int>
#define fi first
#define se second

const int N=1e5+10;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
inline void write(int x){
    if(!x)putchar('0');
    if(x<0){putchar('-'),x=-x;}
    int a[60],cnt=0;
    while(x){a[++cnt]=x%10;x/=10;}
    while(cnt--){putchar(a[cnt+1]+48);}
}

struct node{
    int val1,val2,val3,id;
    bool operator<(const node &i)const{
        return val1==i.fi?(val2==i.val2?val3<i.fi:val2<i.val2):val1<i.fi;
    }
};

int n;
// priority_queue<pii,vector<pii>,greater<pii> >q1,q2,q3;
priority_queue<node,vector<node>,greater<node> >q1,q2,q3;
// priority_queue<node>q1,q2,q3;
int a[N][4];
bool fl1,fl11,fll1;
bool fl3,fl33,fll3;
bool fl2,fl22,fll2;
int res1,res2,res3;
int ress1,ress2,ress3;
int resss1,resss2,resss3;
int res11,res21,res31;
int tmp1,tmp2,tmp3;
int tmpp1,tmpp2,tmpp3;
int tmppp1,tmppp2,tmppp3;


bool cmp(int i,int j){
    return a[i][1]==a[j][1]?(a[i][2]==a[j][2]?a[i][3]>a[j][3]:a[i][2]>a[j][2]):a[i][1]>a[j][1];
}

void solve(){
    n=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            a[i][j]=read();
        }
    }
    while(!q1.empty())q1.pop();
    while(!q2.empty())q2.pop();
    while(!q3.empty())q3.pop();
    // sort(a+1,a+n+1,cmp);
    int ans1=0,ans2=0,ans3=0;
    for(int i=1;i<=n;i++){
        // join 1
        fl1=0,fl2=0,fl3=0;
        fll1=0,fll2=0,fll3=0;
        fl11=0,fl22=0,fl33=0;
        res1=0,res2=0,res3=0;
        tmp1=0,tmp2=0,tmp3=0;
        res11=0,res21=0,res31=0;
        if(q1.size()<n/2){
            tmp1=ans1+a[i][1];
            tmp2=ans2;
            tmp3=ans3;
        }
        else{
            res1=ans1-q1.top().fi+a[i][1];
            if(q2.size()<n/2){
                res2=ans2+a[q1.top().se][2];
                res3=ans3;
                fl11=1;
            }
            else{
                res2=ans2-q2.top().fi+a[q1.top().se][2];
                res3=ans3+a[q2.top().se][3];
            }
            if(q3.size()<n/2){
                res31=ans3+a[q1.top().se][3];
                res21=ans2;
                fl11=1;
            }
            else{
                res31=ans3-q3.top().fi+a[q1.top().se][3];
                res21=ans2+a[q3.top().se][2];
            }
            if(res21+res31>res2+res3){
                res2=res21;
                res3=res31;
                fl1=1; // 3
            }
        }
        if(res1+res2+res3>tmp1+tmp2+tmp3){
            tmp1=res1;
            tmp2=res2;
            tmp3=res3;
            fll1=1;
        }
        // join 2
        tmpp1=0,tmpp2=0,tmpp3=0;
        ress1=0,ress2=0,ress3=0;
        res11=0,res21=0,res31=0;
        if(q2.size()<n/2){
            tmpp1=ans1;
            tmpp2=ans2+a[i][2];
            tmpp3=ans3;
        }
        else{
            ress2=ans2-q2.top().fi+a[i][2];
            if(q1.size()<n/2){
                ress1=ans1+a[q2.top().se][1];
                ress3=ans3;
                fl22=1;
            }
            else{
                ress1=ans1-q1.top().fi+a[q2.top().se][1];
                ress3=ans3+a[q1.top().se][3];
            }
            if(q3.size()<n/2){
                res31=ans3+a[q2.top().se][3];
                res11=ans1;
                fl22=1;
            }
            else{
                res31=ans3-q3.top().fi+a[q2.top().se][3];
                res11=ans1+a[q3.top().se][1];
            }
            if(res31+res11>ress1+ress3){
                ress1=res11;
                ress3=res31;
                fl2=1;
            }
        }
        if(ress1+ress2+ress3>tmpp1+tmpp2+tmpp3){
            tmpp1=ress1;
            tmpp2=ress2;
            tmpp3=ress3;
            fll2=1;
        }
        // join 3
        tmppp1=0,tmppp2=0,tmppp3=0;
        resss1=0,resss2=0,resss3=0;
        res11=0,res21=0,res31=0;
        if(q3.size()<n/2){
            tmppp1=ans1;
            tmppp2=ans2;
            tmppp3=ans3+a[i][3];
        }
        else{
            resss3=ans3-q3.top().fi+a[i][3];
            if(q1.size()<n/2){
                resss1=ans1+a[q3.top().se][1];
                resss2=ans2;
                fl33=1;
            }
            else{
                resss1=ans1-q1.top().fi+a[q3.top().se][1];
                resss2=ans2+a[q1.top().se][2];
            }
            if(q2.size()<n/2){
                res21=ans2+a[q3.top().se][2];
                res11=ans1;
                fl33=1;
            }
            else{
                res21=ans2-q2.top().fi+a[q3.top().se][2];
                res11=ans1+a[q2.top().se][1];
            }
            if(res11+res21>ress1+ress2){
                resss1=res11;
                resss2=res21;
                fl3=1;
            }
        }
        if(resss1+resss2+resss3>tmppp1+tmppp2+tmppp3){
            tmppp1=resss1;
            tmppp2=resss2;
            tmppp3=resss3;
            fll3=1;
        }
        int sum1=tmp1+tmp2+tmp3;
        int sum2=tmpp1+tmpp2+tmpp3;
        int sum3=tmppp1+tmppp2+tmppp3;
        if(sum1>max(sum2,sum3)){
            ans1=tmp1;
            ans2=tmp2;
            ans3=tmp3;
            if(fll1){
                if(fl1){
                    if(fl11){
                        q3.push({a[q1.top().se][3],q1.top().se});
                        q1.pop();
                        q1.push({a[i][1],i});
                    }
                    else{
                        q2.push({a[q3.top().se][2],q3.top().se});
                        q3.pop();
                        q3.push({a[q1.top().se][3],q1.top().se});
                        q1.pop();
                        q1.push({a[i][1],i});
                    }
                }
                else{
                    if(fl11){
                        q2.push({a[q1.top().se][2],q1.top().se});
                        q1.pop();
                        q1.push({a[i][1],i});
                    }
                    else{
                        q3.push({a[q2.top().se][3],q2.top().se});
                        q2.pop();
                        q2.push({a[q1.top().se][2],q1.top().se});
                        q1.pop();
                        q1.push({a[i][1],i});
                    }
                }
            }
            else{
                q1.push({a[i][1],i});
            }
        }
        else if(sum2>max(sum1,sum3)){
            ans1=tmpp1;
            ans2=tmpp2;
            ans3=tmpp3;
            if(fll2){
                if(fl2){
                    if(fl22){
                        q3.push({a[q2.top().se][3],q2.top().se});
                        q2.pop();
                        q2.push({a[i][2],i});
                    }
                    else{
                        q1.push({a[q3.top().se][1],q3.top().se});
                        q3.pop();
                        q3.push({a[q2.top().se][3],q2.top().se});
                        q2.pop();
                        q2.push({a[i][2],i});
                    }
                }
                else{
                    if(fl22){
                        q1.push({a[q2.top().se][1],q2.top().se});
                        q2.pop();
                        q2.push({a[i][2],i});
                    }
                    else{
                        q3.push({a[q1.top().se][3],q1.top().se});
                        q1.pop();
                        q1.push({a[q2.top().se][1],q2.top().se});
                        q2.pop();
                        q2.push({a[i][2],i});
                    }
                }
            }
            else{
                q2.push({a[i][2],i});
            }
        }
        else{
            ans1=tmppp1;
            ans2=tmppp2;
            ans3=tmppp3;
            if(fll3){
                if(fl3){
                    if(fl33){
                        q2.push({a[q3.top().se][2],q3.top().se});
                        q3.pop();
                        q3.push({a[i][3],i});
                    }
                    else{
                        q1.push({a[q2.top().se][1],q2.top().se});
                        q2.pop();
                        q2.push({a[q3.top().se][2],q3.top().se});
                        q3.pop();
                        q3.push({a[i][3],i});
                    }
                }
                else{
                    if(fl33){
                        q1.push({a[q3.top().se][1],q3.top().se});
                        q3.pop();
                        q3.push({a[i][3],i});
                    }
                    else{
                        q2.push({a[q1.top().se][2],q1.top().se});
                        q1.pop();
                        q1.push({a[q3.top().se][1],q3.top().se});
                        q3.pop();
                        q3.push({a[i][3],i});
                    }
                }
            }
            else{
                q3.push({a[i][3],i});
            }
        }
    }

    while(!q1.empty()){
        write(q1.top().se);spa;
        q1.pop();
    }
    ero;
    while(!q2.empty()){
        write(q2.top().se);spa;
        q2.pop();
    }
    ero;
    while(!q3.empty()){
        write(q3.top().se);spa;
        q3.pop();
    }
    ero;
    write(ans1+ans2+ans3);ero;ero;
}

signed main(){
    // freopen(".in","r",stdin);
    // freopen("1.out","w",stdout);
    int T=read();
    // int T=1;
    while(T--){solve();}
    return 0;
}