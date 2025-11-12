#include<bits/stdc++.h>
using namespace std;
struct{
	int a1;
	int a2;
	int a3;
}a[5][1000];
int main(){ 
 freopen("club.in","r",stdin);
 freopen("club.out","w",stdout);
  int t,n,ans,b1[100],b2[100],b3[100],p=0;
  //int a[5][1000][3];
  int q1=2,q2=2,q3=2;
  b1[0]=b2[0]=b3[0]=0;
  b1[1]=b2[1]=b3[1]=-1;
  b1[2]=b2[2]=b3[2]=0;
  cin>>t;
  for (int i=1;i<=t;i++)
     { cin>>n;
      for (int j=1;j<=n;j++)
          {
		   cin>>a[i][j].a1 >>a[i][j].a2 >>a[i][j].a3 ;
		   //读入数据 
		   if(b1[0]>(n/2) )
		     {  p=max(a[i][i].a1 ,a[i][j].a2 ,a[i][j].a3 );
		        if (b1[2]<p)
		         { b1[2]=p;
		          ans+=b1[2];
				  }
				//当超出人数时，选择最优解 
			  else  
			  { p=max(a[i][j].a2 ,a[i][j].a3 );
			     ans+=p;
			     if (p==a[i][j].a2 )
		         { b2[0]++;
		           b2[q2]=p;
			       q2++;}
		        if (p==a[i][j].a3 )
		         { b3[0]++;
		           b3[q3]=p;
				   q3++;}} 
				 //当选择非最优解，贪心选择    
			 }
		     
		   else if(b2[0]>n/2 )
		    {  p=max(a[i][i].a1 ,a[i][j].a2 ,a[i][j].a3 );
		        if (b2[2]<p)
		          { b2[2]=p;
		           ans+=b2[2];
				  }
			   else
			     { p=max(a[i][j].a1 ,a[i][j].a3 );
			      ans+=p;
			      if (p==a[i][j].a1 )
		          { b1[0]++;
		            b1[q1]=p;
			        q1++;}
			      if (p==a[i][j].a3 )
		         { b3[0]++;
		           b3[q3]=p;
				   q3++;}}
			}
		  else if(b3[0]>n/2 )
		    {  p=max(a[i][i].a1 ,a[i][j].a2 ,a[i][j].a3 );
		        if (b3[2]<p)
		          { b3[2]=p;
		            ans+=b3[2];
				 }
			   else  
			     { p=max(a[i][j].a1 ,a[i][j].a2 );
			       ans+=p;
			        if (p==a[i][j].a1 )
		         { b1[0]++;
		            b1[q1]=p;
			        q1++;}
		       if (p==a[i][j].a2 )
		        { b2[0]++;
		          b2[q2]=p;
			       q2++;}}
			 }
          else
		     { 
			  p=max(a[i][i].a1 ,a[i][j].a2 ,a[i][j].a3 );
               ans+=p;
			   if (p==a[i][j].a1 )
		          { b1[0]++;
		            b1[q1]=p;
			        q1++;}
		       if (p==a[i][j].a2 )
		         { b2[0]++;
		           b2[q2]=p;
			       q2++;}
		      if (p==a[i][j].a3 )
		        { b3[0]++;
		           b3[q3]=p;
				   q3++;}
				  }//贪心选择 
		  
		}
		sort(b1+1,b1+q1);
		sort(b2+1,b2+q2);
		sort(b3+1,b3+q3);
        cout<<ans<<endl;
	 } 
   return 0;
}
