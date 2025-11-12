#include<bits/stdc++.h>
using namespace std;
//T1 反贪板子，至少比去年好 
//简单题，15min 过大样例 
int n,a[100010][3],ans;
priority_queue <int,vector<int>,greater<int> > q[3];
int main()
{freopen("club.in","r",stdin);
 freopen("club.out","w",stdout);
 ios::sync_with_stdio(0);cin.tie(0);
 int t;cin>>t;
 while(t--)
 {cin>>n;ans=0;
  while(!q[0].empty()) q[0].pop();
  while(!q[1].empty()) q[1].pop();
  while(!q[2].empty()) q[2].pop();
  int cnt[3]={};
  for(int i=1;i<=n;i++)
  {cin>>a[i][0]>>a[i][1]>>a[i][2];
   if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])
   {cnt[0]++;ans+=a[i][0];
    q[0].push(a[i][0]-max(a[i][1],a[i][2]));
   }
   else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])
   {cnt[1]++;ans+=a[i][1];
    q[1].push(a[i][1]-max(a[i][0],a[i][2]));
   }
   else
   {cnt[2]++;ans+=a[i][2];
    q[2].push(a[i][2]-max(a[i][0],a[i][1]));
   }
  }
  if(cnt[0]>n/2)
  {while(q[0].size()!=n/2)
   {ans-=q[0].top();
    q[0].pop();
   }
  }
  else if(cnt[1]>n/2)
  {while(q[1].size()!=n/2)
   {ans-=q[1].top();
    q[1].pop();
   }
  }
  else if(cnt[2]>n/2)
  {while(q[2].size()!=n/2)
   {ans-=q[2].top();
    q[2].pop();
   }
  }
  cout<<ans<<'\n';
 }
}
