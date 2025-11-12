#include<bits/stdc++.h>
using namespace std;
const int slen=5e5+10;
int n,k,ans=0;
int a[slen],st[slen][3];
bool f[slen];
int main()
{
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  cin>>n>>k;
  memset(st,0,sizeof(st));
  long long z=0;
  for(int i=1;i<=n;i++)
  {
  	cin>>a[i];
    st[i][1]=a[i];
    if(a[i]==k){ans++;f[i]=true;}
  	if(z<=k) z=z+a[i];
  }
  if(z<k)  {cout<<0;return 0;}
  for(int i=2;i<=n;i++)
  {
  	for(int j=1;j<=n;j++)
  	{
  	  bool f1=false;
  	  int l=i%3;
  	  st[j][l]=st[j][(l+3-1)%3]^st[j+1][(l+3-1)%3]^st[j+1][(l+3-2)%3];
  	  if(st[j][l]==k) 
  	  {
  	  	for(int o=0;o<i;o++)
		  if(f[j+o]){f1=true;break;}
		if(!f1)
		{
		  ans++;
	      for(int o=0;o<i;o++)
		    f[j+o]=true;
	    }
	  }
	}
  }
  cout<<ans;
  return 0;
}