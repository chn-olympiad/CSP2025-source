
/* 
第一次考CSP并且是考S_没考过J
估分40 
*/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long A[100100],B[100100],C[100100],D[100100];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
long long n,m,l,r,i,j,maxx,x1,x2,x3,ans=0,sss=0,f=1,z1,z2,z3;
	cin>>l;
	while(l--)
	{	
		cin>>n;
	
			
		
			if(n==2)
			{
				cin>>x1>>x2>>x3>>z1>>z2>>z3;
				ans=max(max(x1+z2,max(x1+z3,x2+z1)),max(max(x2+z3,x3+z1),x3+z2));
				cout<<ans<<endl; 
			}
			else
			{
			
		
			maxx=n/2;
			ans=0;
			for(i=1;i<=n;i++)
			{
				cin>>x1>>x2>>x3;
				A[i]=x1;
				B[i]=x2;
				C[i]=x3;
				if(B[i]!=C[i]||B[i]!=0||C[i]!=0)
				{
					f=0;
				}
			
			}
			if(f==1)
			{
			
				sort(A+1,A+1+n);
				ans=0;
				j=0;
				for(i=n;i>=1;i--)
				{
					j++;
					ans+=A[i];
					if(j==maxx)
					{//cout<<"4455"<<endl;
						break;
					}
				}
				cout<<ans<<endl;
			}
				else
			{
				sort(A+1,A+1+n);
				sort(B+1,B+1+n);
				sort(C+1,C+1+n);
				j=0;
				for(i=n;i>=maxx;i--)
				{
					j++;
					D[j]=A[i];
					j++;
					D[j]=B[i];
					j++;
					D[j]=C[i];
				}
				sort(D+1,D+1+j);
				int s=0;
				for(i=j;i>j-n;i--)
				{
					s++;
			
					ans+=D[i];
//				cout<<D[i]<<endl;
					if(s==maxx)
					{
						break;
					}
				}
		
				cout<<ans;
			}
		}
	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
