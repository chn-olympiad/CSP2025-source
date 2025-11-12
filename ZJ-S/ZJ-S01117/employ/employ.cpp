#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[510],p[510];
long long fac[100010],ans;
string s;
bool ac=true;
int main()
{freopen("employ.in","r",stdin);
 freopen("employ.out","w",stdout);
 cin>>n>>m>>s;
 fac[0]=1;
 for(int i=1;i<=n;i++)
 fac[i]=fac[i-1]*i%mod;
 for(int i=0;i<s.size();i++)
 {if(s[i]=='0') ac=false;
 }
 if(ac==true){cout<<fac[n];return 0;}
 for(int i=1;i<=n;i++)
 cin>>a[i]; 
 if(n<=10)
 {for(int i=1;i<=n;i++) p[i]=i;
  for(int i=1;i<=fac[n];i++)
  {int cnt=0,cntt=0;
   for(int j=1;j<=n;j++)
   {if(s[j-1]=='0') cnt++;
    else if(cnt>=a[p[j]]) cnt++;
    else cntt++;
   }
   if(cntt>=m) ans++;
   next_permutation(p+1,p+1+n);
  }
  cout<<ans;
  return 0;
 }
 
}
