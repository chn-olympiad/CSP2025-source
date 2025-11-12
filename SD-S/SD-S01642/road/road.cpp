#include<bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3;
#define gc getchar()
inline int rd(){
  int x=0,s=1;
  char ch=gc;
  while(!isdigit(ch)){if(ch=='-')s=-1;ch=gc;}
  while(isdigit(ch)){x=x*10+ch-'0';ch=gc;}
  return x*s;
}
int n,m,k,lf[10001][10001],hg[11],ans;


int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  n=rd(),m=rd(),k=rd();
  int l=n+k;
  for(int i=1;i<=l;i++){
    for(int j=1;j<=l;j++){
      lf[i][j]=INF;
    }
    lf[i][i]=0;
  }
  for(int i=1;i<=m;i++){
    int x,y,z;
    x=rd(),y=rd(),z=rd();
    lf[x][y]=z;
    lf[y][x]=z;
  }
  for(int i=1;i<=k;i++){
    hg[i]=rd();
    for(int j=1;j<=n;j++){
      int u=rd();
      lf[i+n][j]=hg[i]+u;
      lf[j][i+n]=hg[i]+u;
    }
  }
  for(int i=1;i<=l;i++){
    for(int j=1;j<=l;j++){
      int minn=INT_MAX;
      int wz=0;
      for(int k=1;k<=l;k++){
        minn=min(lf[i][k]+lf[k][j],minn);
      }
      lf[i][j]=minn;
      lf[j][i]=minn;
    }
  }
  for(int i=1;i<n;i++){
    ans+=lf[i][i+1];
  }
  cout<<ans;
  fclose(stdin);
  fclose(stdout);
  return 0;
}

