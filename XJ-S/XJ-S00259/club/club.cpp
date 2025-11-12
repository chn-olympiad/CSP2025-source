#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n,s[4][N],ans=0,t,wish[3][N],x[4][N],a;
bool a1()
{
  if(a>0) 
  {
  	a--;
  	return true;
  }
  return false;
}
void swapp(int xb)
{
  for(int i=1;i<=n;i++)
  {
  	if(x[1][i]==xb) x[1][i]=-1;
  	if(x[2][i]==xb) x[2][i]=-1;
  	if(x[3][i]==xb) x[3][i]=-1;
  }
  return ; 
}
int main()
{
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  cin>>t;
  a=t;
  while(a1())
  {
  	ans=0; 
  	cin>>n;
  	for(int i=1;i<=n;i++)
  	{
  	  cin>>s[1][i]>>s[2][i]>>s[3][i];
  	  //cout<<"x"<<i<<"n"<<n<<endl;
  	  x[1][i]=i;
	  x[3][i]=i;
	  x[2][i]=i;
	}
	for(int i=1;i<=n;i++)
    {
      for(int j=i;j<=n;j++)
  	  {
  	    if(s[1][j]>s[1][i])	
  	    {
  	      swap(s[1][j],s[1][i]);
		  swap(x[1][i],x[1][j]);	
		  //cout<<s[3][j]<<"&"<<s[3][i]<<endl;
		  
		}
		if(s[2][j]>s[2][i])	
  	    {
  	      swap(s[2][j],s[2][i]);
		  swap(x[2][i],x[2][j]);	
		  //cout<<s[3][j]<<"&"<<s[3][i]<<endl;

		}
		if(s[3][j]>s[3][i])	
  	    {
  	      swap(s[3][j],s[3][i]);
		  swap(x[3][i],x[3][j]);
		  //cout<<s[3][j]<<"&"<<s[3][i]<<endl;
		}
	  }
    }
	
  /*for(int z=1;z<=3;z++)
  {
  	cout<<"club"<<z<<endl;
  	for(int i=1;i<=n;i++)
    {
      cout<<x[z][i]<<"=>"<<s[z][i]<<endl;
    }
  }*/
  int l1=1,l2=1,l3=1,club1=0,club2=0,club3=0;
  for(int i=1;i<=n;i++)
  {
  	if(x[1][l1]==-1) 
  	{
  	  while(x[1][l1]==-1)
  	  {
  	    l1++;	
	  }
    }
    if(x[2][l2]==-1) 
  	{
  	  while(x[2][l2]==1-1)
  	  {
  	    l2++;	
	  }
    }
    if(x[3][l3]==-1) 
  	{
  	  while(x[3][l3]==-1)
  	  {
  	    l3++;	
	  }
    }
    //cout<<" L1="<<l1<<" L2="<<l2<<" L3="<<l3<<endl;
if(s[1][l1]>=s[2][l2]&&s[1][l1]>=s[3][l3]&&x[1][l1]!=-1&&club1<n/2)
  	{
	  	ans+=s[1][l1];
  	 // cout<<s[1][l1]<<"  "<<s[2][l2]<<"  "<<s[3][l3]<<"_";
  	 // cout<<"1:  name "<<l1<<"=="<<s[1][l1]<<endl;
  	  swapp(l1);
  	  l1++;
	  
  	  club1++;
	}
	else if(s[2][l2]>=s[1][l1]&&s[2][l2]>=s[3][l3]&&x[2][l2]!=-1&&club2<n/2)
  	{
	 	ans+=s[2][l2];
  	  //cout<<s[1][l1]<<"  "<<s[2][l2]<<"  "<<s[3][l3]<<"_";
  	  //cout<<"2:  name "<<l2<<"=="<<s[2][l2]<<endl;
  	  swapp(l2);
  	  l2++;
	 
  	  
  	  club2++;
	}
	else if(s[3][l3]>=s[2][l2]&&s[3][l3]>=s[1][l1]&&x[3][l3]!=-1&&club3<n/2)
  	{
	  ans+=s[3][l3];
  	  //cout<<s[1][l1]<<"  "<<s[2][l2]<<"  "<<s[3][l3]<<"_";
  	  //cout<<"3:  name "<<l3<<"=="<<s[3][l3]<<endl;
  	  swapp(l3);
  	  l3++;
	  
  	  
  	  club3++;
	}
  }
  cout<<ans<<'\n';
  //cout<<"ANS="<<ans<<"  "<<club1<<" "<<club2<<" "<<club3;
  //for(int i=1;i<=n;i++) cout<<x[1][i]<<"  "<<x[2][i]<<"  "<<x[3][i]<<"_";
  }
  return 0;	
} 
