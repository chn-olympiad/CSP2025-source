#include<bits/stdc++.h>
using namespace std;
const int slen=110;
int n,m,x,num=0;
int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  cin>>n>>m;
  cin>>x;
  for(int i=2;i<=n*m;i++)
  {
  	int y;cin>>y;
  	if(y>x) num++;
  }
  int l=num%n,h=num/n+1;
  if(h%2==1)
  	cout<<h<<" "<<l+1;
  else
    cout<<h<<" "<<n-l;
  return 0;
}