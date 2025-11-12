#include<bits/stdc++.h>
using namespace std;
const int N=5e3+1;
int n,s[N],fors[N],ans=0,q;
void forif(int k,int sum)
{
  int maxs=s[k];
  sum+=s[k];
  //cout<<sum<<" "<<s[k]<<" "<<k<<" "<<k-q+2<<"next"<<endl;
  if(k>n||k==0) 
  {
  	//cout<<sum<<" "<<s[k]<<" "<<k<<"end"<<endl;
  	return ;
  }
 if(sum>maxs*2/*&&flag[sum][s[k]*2][k-q+2]==0*/) ans++;//,cout<<endl<<"  ans++"<<ans<<endl
  
  //if(k==3) ans++;
  for(int i=1;i<=n-k;i++)
  {
  	forif(k+1,sum);
  }
  
}
int main()
{
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  cin>>n;
  for(int i=1;i<=n;i++)
  {
  	cin>>s[i];
  }
  sort(s+1,s+n+1);
  for(int i=1;i+2<=n;i++)
  {
  	if(s[i]==s[i-1]) continue;
  		for(int j=i+1;j+1<=n;j++)
  	{ 
  	  q=j;
  	  forif(j+1,s[i]+s[j]);
	}
  }
  cout<<ans%998244353;
  return 0;
}
