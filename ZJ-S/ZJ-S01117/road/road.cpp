#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,d[100030],c[21],vis[100030],aa[12][100030],u[2000010],v[2000010],ww[2000010];
vector <int> b[100030],w[100030];
priority_queue <pair<int,int> > q;
long long ans,sum;
//struct Node{
// int num,id;
// bool operator<(const Node& x)const
// {return num<x.num;
// }
//}a[12][10030];
//16:00 彻底被强制线性整破防了 
//16:20 答案偏大+T飞了 
//假了！
//拆点 
signed main()
{freopen("road.in","r",stdin);
 freopen("road.out","w",stdout);
 ios::sync_with_stdio(0);cin.tie(0);
 cin>>n>>m>>k;
 for(int i=1;i<=n+2*k;i++) d[i]=2e9;
 for(int i=1;i<=m;i++)
 {cin>>u[i]>>v[i]>>ww[i];
  b[u[i]].push_back(v[i]);w[u[i]].push_back(ww[i]);
  b[v[i]].push_back(u[i]);w[v[i]].push_back(ww[i]);
 }
 bool ac=true;
 for(int i=1;i<=k;i++)
 {cin>>c[i];
  if(c[i]!=0) ac=false;
  for(int j=1;j<=n;j++)
  cin>>aa[i][j];
 }
 if(ac==true)
 {int i=(1<<k)-1;sum=0;
  for(int j=1;j<=k;j++)
  {if(i&(1<<(j-1)))
   {for(int kk=1;kk<=n;kk++)
    {b[n+j].push_back(kk);w[n+j].push_back(aa[j][kk]);
     b[kk].push_back(n+j);w[kk].push_back(aa[j][kk]);
    }
    sum+=c[j];
   }
  }
  for(int j=1;j<=n+2*k;j++) d[j]=2e9;
  for(int j=1;j<=m;j++)
  {b[u[j]].push_back(v[j]);w[u[j]].push_back(ww[j]);
   b[v[j]].push_back(u[j]);w[v[j]].push_back(ww[j]);
  }
  for(int j=1;j<=n+2*k;j++) vis[j]=false;
  d[1]=0;
  q.push({0,1});
  while(!q.empty())
  {int id=q.top().second,ww=-q.top().first;q.pop();
   if(vis[id]) continue;
   sum+=ww;//cout<<ww<<' ';
   vis[id]=true;
   for(int i=0;i<b[id].size();i++)
   {if(w[id][i]<d[b[id][i]])
    {d[b[id][i]]=w[id][i];
     q.push({-w[id][i],b[id][i]});
    }
   }
  }
  //cout<<sum<<' ';
  ans=min(ans,sum);
  for(int i=1;i<=n+2*k;i++)
  b[i].clear(),w[i].clear();
 cout<<sum;
 return 0;
 }
 d[1]=0;
 q.push({0,1});
 while(!q.empty())
 {int id=q.top().second,ww=-q.top().first;q.pop();
  if(vis[id]) continue;
  ans+=ww;
  vis[id]=true;//u[++j]=id;v[j]=ww;
  for(int i=0;i<b[id].size();i++)
  {if(w[id][i]<d[b[id][i]])
   {d[b[id][i]]=w[id][i];
    q.push({-w[id][i],b[id][i]});
   }
  }
 }
 //cout<<ans<<' ';
 for(int i=1;i<(1<<k);i++)
 {sum=0;
  for(int j=1;j<=k;j++)
  {if(i&(1<<(j-1)))
   {for(int kk=1;kk<=n;kk++)
    {b[n+j].push_back(kk);w[n+j].push_back(aa[j][kk]);
     b[kk].push_back(n+j);w[kk].push_back(aa[j][kk]);
    }
    sum+=c[j];
   }
  }
  for(int j=1;j<=n+2*k;j++) d[j]=2e9;
  for(int j=1;j<=m;j++)
  {b[u[j]].push_back(v[j]);w[u[j]].push_back(ww[j]);
   b[v[j]].push_back(u[j]);w[v[j]].push_back(ww[j]);
  }
  for(int j=1;j<=n+2*k;j++) vis[j]=false;
  d[1]=0;
  q.push({0,1});
  while(!q.empty())
  {int id=q.top().second,ww=-q.top().first;q.pop();
   if(vis[id]) continue;
   sum+=ww;//cout<<ww<<' ';
   vis[id]=true;
   for(int i=0;i<b[id].size();i++)
   {if(w[id][i]<d[b[id][i]])
    {d[b[id][i]]=w[id][i];
     q.push({-w[id][i],b[id][i]});
    }
   }
  }
  //cout<<sum<<' ';
  ans=min(ans,sum);
  for(int i=1;i<=n+2*k;i++)
  b[i].clear(),w[i].clear();
 }
 cout<<ans;
}
//  for(int j=1;j<=id1;j++)
//  {viss[j]=false;_min[j]=1e9+2;jj[j]=1;
//  }
//  vis[1]=true;
//  for(int kk=1;kk<=id1;kk++)
//  _min[kk]=min(_min[kk],aa[s[kk]][1]);
//  for(int j=2;j<=n;j++)
//  {if(vis[u[j]]) continue;
//   //该步能否被篡改
//   min_=1e9+2;
//   //更新乡村贪心
//   for(int kk=1;kk<=id1;kk++)
//   {if(!viss[kk])
//    {if(_min[kk]<min_)
//     {min_=_min[kk];
//      minid=kk;
//	 }
//	}
//   }
//   int _min_=1e9+2,min_id;
//   //更新城市贪心 
//   for(int kk=1;kk<=id1;kk++) 
//   {if(viss[kk])
//    {while(vis[a[s[kk]][jj[kk]].id]&&jj[kk]<=n) jj[kk]++;
//     if(jj[kk]==n+1) continue;
//     if(a[s[kk]][jj[kk]].num<_min_)
//     {_min_=a[s[kk]][jj[kk]].num;
//      min_id=a[s[kk]][jj[kk]].id;
//	 }
//	}
//   }
//   if(min_<_min_)
//   {if(min_<v[j]) //更新乡村
//    {viss[minid]=true;
//     j--;sum+=min_;//cnttt++;
//     continue;
//	}
//	else //原计划 
//	{int id=u[j];sum+=v[j];vis[u[j]]=true;
//	 for(int kk=1;kk<=id1;kk++)
//     _min[kk]=min(_min[kk],aa[s[kk]][id]);
//     j--;
//     continue;
//	}
//   }
//   else
//   {if(_min_<v[j]) //更新城市
//    {vis[min_id]=true;sum+=_min_;
//     for(int kk=1;kk<=id1;kk++)
//     _min[kk]=min(_min[kk],aa[s[kk]][min_id]);
//     j--;
//	}
//	else //原计划 
//	{int id=u[j];sum+=v[j];vis[u[j]]=true;
//	 for(int kk=1;kk<=id1;kk++)
//     _min[kk]=min(_min[kk],aa[s[kk]][id]);
//     j--;
//	}
//   }
//  }
  //if(cnttt!=n-1) cout<<"ERROR";
