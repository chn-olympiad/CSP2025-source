#include<bits/stdc++.h>
using namespace std;
//n,m<=10??!!这是我们ABC的B吗？！ 
//小心样例 n=m 
int n,m,a[110],cnt;
int main()
{freopen("seat.in","r",stdin);
 freopen("seat.out","w",stdout);
 cin>>n>>m;
 for(int i=1;i<=n*m;i++) 
 {cin>>a[i];
  if(a[i]>a[1]) cnt++;
 }
 int y=cnt/n+1,x=cnt%n;
 if(y&1) x++;
 else x=n-x;
 cout<<y<<' '<<x;
 return 0;
}
