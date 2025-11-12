#include<bits/stdc++.h>
using namespace std;
int t,n[6],a[6][100010][3],b[5],d;//a[][]存每个人满意程度 ；
int s(int u,int y,int z) 
{
	if(u>=y&&u>=z)
	  return u;
	else
	{
		if(y>=u&&y>=z)
	      return y;
	    else
	      return z;
	} 
}
int dfs(int mem,int ad,int k/*,A,B,C*/)//mem是剩余人数；ad是地址； 
{
	if(ad>2) return 0;
	if(mem==1)
	{
		if(b[0]<d/2&&b[1]<d/2&&b[2]<d/2)
		  return s(a[k][mem][0],a[k][mem][1],a[k][mem][2]);
		else
		{
			if(b[0]<d/2&&b[1]<d/2)
				return s(a[k][mem][0],a[k][mem][1],-1);
			else
			{
				    if(b[1]<d/2&&b[2]<d/2){
					return s(a[k][mem][1],a[k][mem][2],-1);
				    }
				    else{
					    if(b[0]<d/2&&b[2]<d/2)
					      return s(a[k][mem][0],a[k][mem][2],-1);
					    else
					    {
					  	    for(int i=0;i<3;i++){
					  		  if(b[i]<d/2)
					  		    return a[k][mem][i];
						    }
					    }
				    }	
			}
		}
	}
	else 
	{  
	    if(b[ad]<d/2){
	    	b[ad]+=1;
	    	return s(dfs(mem,ad+1,k),dfs(mem-1,ad,k)+a[k][mem][ad],-1);
		}
		else
		   return dfs(mem,ad+1,k);
	}
}
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n[i];
		for(int j=1;j<=n[i];j++)
		{
			cin>>a[i][j][0];
			cin>>a[i][j][1];
			cin>>a[i][j][2];
		} 
	}
	for(int i=0;i<t;i++)
	{
		d=n[i];
		cout<<dfs(n[i],0,i)<<endl;
	}
	
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
