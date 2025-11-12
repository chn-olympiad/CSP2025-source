//记录篇 
//14:18 吾日三省吾身 
//抽象大赏我来了。
//luogu uid 592463 
//14:27怎么还没有密码？
//不是哥们。
//压缩包密码：Ren5Jie4Di4Ling5%
//14:37 T1维护最大值和次大值的贪心，感觉很有正确性
//14:57 A done. 感觉绿。大样例0.2s。
//15:03 感觉B像是一个预处理生成树 然后跑状压的东西，精细实现一下。
//1s时间很不够用啊。
//T3感觉像ACAM 我不会。。。
//15:34打打T3 20pts 暴力。
//16:44 200都不一定能上了
//原地退役.jpg
//100+[64~80]+10+12=184 进步4分捏。
//瘫。。。
//何意味 又是光速秒掉A然后坐牢吗。。。
//绝望了.jpg 
#include<bits/stdc++.h>
bool MED;
using namespace std;
#define ll long long
const int N=505;
const int mod=998244353;
int n,m,c[N];
string s;
namespace solve1{
  const int M=15;
  int st[M],b[M];
  void solve(){
    int res=0,num,fl;
    for(int i=1;i<=n;i++)b[i]=i;
    do{
      num=0;
      for(int i=1;i<=n;i++){
        if(num>=c[b[i]])num++;
        else if(s[i]=='0')num++;
      }
      if(num<=n-m)res++;
    }while(next_permutation(b+1,b+1+n));
    cout<<res;
  }
}
namespace solve2{
  void solve(){
    int fl=1;
    for(int i=1;i<=n;i++)if(c[i]==0||s[i]=='0')fl=0;
    if(fl){
      ll res=1;
      for(int i=1;i<=n;i++)res=res*i%mod;
      cout<<res;
    }else cout<<0;
  }
}
bool MST;
int main(){
  //fprintf(stderr,"%.3lf MB\n",(&MED-&MST)/1048576.0);
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);
  cin>>n>>m>>s;s=' '+s;
  int FLA=1;
  for(int i=1;i<=n;i++)if(s[i]=='0')FLA=0;
  for(int i=1;i<=n;i++)cin>>c[i];
  if(n==m){solve2::solve();}
  //if(n<=10){solve1::solve();return 0;} 
  if(n==m){solve2::solve();return 0;}
  //if(FLA){solve2::solve();return 0;}
  return 0;
}
