#include<bits/stdc++.h>
using namespace std;
int n,k,num,c[50000];
struct PX{
	int lon,l,r;
}b[50000];
bool cmp(PX c,PX d){
	return c.lon<d.lon;}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

//	a^=b;yihuo

	cin>>n>>k;
	if(n<=2&&k==0)
	{
		cout<<"0";
	}
	else
	{
		int a[50000],cnt=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
	    	{
	    		//cout<<i<<j;
				
	    		if(i==j&&a[i]==k){
	    		//	cout<<i<<j;
	    	    	b[cnt].lon=j-i+1;
	    		    b[cnt].l=i;
	    		    b[cnt].r=j;// cout<<b[cnt].l<<b[cnt].r<<" "<<b[i].lon<<endl;
	    		    cnt++;
	    		   
				}
				else{
				    int p=a[i];
					for(int q=i+1;q<=j;q++)
					{
						p^=a[q];
					}
					if(p==k)
					b[cnt].lon=j-i+1;
	    		    b[cnt].l=i;
	    		    b[cnt].r=j;
	    		    cnt++;
	    		  //  cout<<b[i].l<<b[i].r<<" "<<b[i].lon<<endl;
				}
	    	}
		}
		sort(b+1,b+cnt+1,cmp);
		int num1;
		for(int i=1;i<=cnt;i++)
		{
			
			int ln=0,rn=0;
			if(b[i].lon!=0)
			{
			   
				ln=b[i].l;
				rn=b[i].r; 
			//	cout<<ln<<rn<<" "<<b[i].lon<<endl;
				if(num==0)
				{
					for(int k=ln;k<=rn;k++)
					{
						
						c[k]=1;
					}
					
					num++;
					//cout<<ln<<rn<<endl;
				//	cout<<endl;
				}
				else {
					int o=0;
					for(int j=ln;k<=rn;k++){
						if(c[k]==1)
						{
							o++;
						}
					}
					if(o==0)
					{
						num++;
				//		cout<<ln<<rn<<endl;
					}
				}
			}
		}
		cout<<num;
	}

	


	return 0;
}

