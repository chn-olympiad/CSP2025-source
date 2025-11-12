#include<bits/stdc++.h>
using namespace std;

#define gc getchar()
inline long long rd(){
  long long x=0,s=1;
  char ch=gc;
  while(!isdigit(ch)){if(ch=='-')s=-1;ch=gc;}
  while(isdigit(ch)){x=x*10+ch-'0';ch=gc;}
  return x*s;
}
long long t,ans,maxx,n,a[100001][4],s[4],b2,b3;
bool b[100001];
void dfs(int x){
  if(x>=1&&x<=n){
    for(int i=1;i<=3;i++){
      if(s[i]<n/2&&b[x]==0){
        maxx+=a[x][i];
        s[i]++;
        b[x]=1;
        if(x==n){
          ans=max(maxx,ans);
        }
        dfs(x+1);
        s[i]--;
        b[x]=0;
        maxx-=a[x][i];
      }
    }
}
}

void lesson1(){
  long long b[n+1]={0};
  for(int i=1;i<=n;i++)b[i]=a[i][1];
  stable_sort(b+1,b+1+n);
  for(int i=1;i<+n/2;i++)ans+=b[i];
  cout<<ans<<"\n";
}

int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  t=rd();
  while(t--){
    memset(b,0,sizeof(b));
    memset(s,0,sizeof(s));
    n=rd();
    for(int i=1;i<=n;i++)memset(a[i],0,sizeof(a[i]));
    for(int i=1;i<=n;i++){
      for(int j=1;j<=3;j++){
        cin>>a[i][j];
        if(i==2)b2+=a[i][j];
        if(i==3)b3+=a[i][j];
      }
    }
    ans=0;
    if(b2==0&&b3==0){
      lesson1();
      continue;
    }
    dfs(1);
    cout<<ans<<"\n";
}
  fclose(stdin);
  fclose(stdout);
  return 0;
}

