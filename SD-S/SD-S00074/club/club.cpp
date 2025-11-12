#include <bits/stdc++.h>
using namespace std;
int t;
int mmax; 
int zu1,zu2,zu3;
struct stu
{
	int go1;
	int go2;
	int go3;
};
stu sttaf[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>sttaf[i].go1;
			cin>>sttaf[i].go2;
			cin>>sttaf[i].go3;
		}
		for(int i=1;i<=n;i++)
		{

			if(sttaf[i].go1>sttaf[i].go2 && sttaf[i].go2>sttaf[i].go3)
			{
				if((n/2)>=zu1)
				{
					zu1+=1;
					mmax+=sttaf[i].go1;
				} 
				else if((n/2)>=zu2)
				{
					zu2+=1;
					mmax+=sttaf[i].go2;
				}
				else
				{
					zu3+=1;
					mmax+=sttaf[i].go3;
				} 
			}
			else if(sttaf[i].go1>sttaf[i].go3 && sttaf[i].go3>sttaf[i].go2)
			{
				if((n/2)>=zu1)
				{
					zu1+=1;
					mmax+=sttaf[i].go1;
				} 
				else if((n/2)>=zu3)
				{
					zu3+=1;
					mmax+=sttaf[i].go3;
				}
				else
				{
					zu2+=1;
					mmax+=sttaf[i].go2;
				}
			}
			else if(sttaf[i].go2>sttaf[i].go1 && sttaf[i].go1>sttaf[i].go3)
			{
				if((n/2)>=zu2)
				{
					zu2+=1;
					mmax+=sttaf[i].go2;
				} 
				else if((n/2)>=zu1)
				{
					zu1+=1;
					mmax+=sttaf[i].go1;
				}
				else
				{
					zu3+=1;
					mmax+=sttaf[i].go3;
				}
			}
			else if(sttaf[i].go2>sttaf[i].go3 && sttaf[i].go3>sttaf[i].go1)
			{
				if((n/2)>=zu2)
				{
					zu2+=1;
					mmax+=sttaf[i].go2;
				} 
				else if((n/2)>=zu3)
				{
					zu3+=1;
					mmax+=sttaf[i].go3;
				}
				else
				{
					zu1+=1;
					mmax+=sttaf[i].go1;
				}
			}
			else if(sttaf[i].go3>sttaf[i].go1 && sttaf[i].go1>sttaf[i].go2)
			{
				if((n/2)>=zu3)
				{
					zu3+=1;
					mmax+=sttaf[i].go3;
				} 
				else if((t/2)>=zu1)
				{
					zu1+=1;
					mmax+=sttaf[i].go1;
				}
				else
				{
					zu2+=1;
					mmax+=sttaf[i].go2;
				}
			}
			else if(sttaf[i].go3>sttaf[i].go2 && sttaf[i].go2>sttaf[i].go1)
			{
				if((n/2)>=zu3)
				{
					zu3+=1;
					mmax+=sttaf[i].go3;
				} 
				else if((n/2)>=zu2)
				{
					zu2+=1;
					mmax+=sttaf[i].go2;
				}
				else
				{
					zu1+=1;
					mmax+=sttaf[i].go1;
				}
			}
			else if(sttaf[i].go1== sttaf[i].go2 && sttaf[i].go3>sttaf[i].go2)
			{
				if((n/2)>=zu3)
				{
					zu3+=1;
					mmax+=sttaf[i].go3;
				}
				else
				{
					if((n/2)>=zu2)
					{
						zu2+=1;
						mmax+=sttaf[i].go2;
					} 
					else
					{
						zu1+=1;
						mmax+=sttaf[i].go1;
					 } 
				}
			}
			else if(sttaf[i].go1== sttaf[i].go2 && sttaf[i].go3<sttaf[i].go2)
			{
				if((n/2)>=zu1)
				{
					zu1+=1;
					mmax+=sttaf[i].go1;
				}
				else if((n/2>=zu2))
				{
					zu2+=1;
					mmax+=sttaf[i].go2;
				}
				else
				{
					zu3+=1;
					mmax+=sttaf[i].go3;
				}
				
			}
			else if(sttaf[i].go1== sttaf[i].go3 && sttaf[i].go2>sttaf[i].go3)
			{
				if((n/2)>=zu2)
				{
					zu2+=1;
					mmax+=sttaf[i].go2;
				}
				else
				{
					if((n/2)>=zu1)
					{
						zu1+=1;
						mmax+=sttaf[i].go1;
					} 
					else
					{
						zu3+=1;
						mmax+=sttaf[i].go3;
					 }
				}
			}
			else if(sttaf[i].go1== sttaf[i].go3 && sttaf[i].go2<sttaf[i].go3)
			{
				if((n/2)>=zu3)
				{
					zu3+=1;
					mmax+=sttaf[i].go3;
				}
				else if((n/2)>=zu1)
				{
					zu1+=1;
					mmax+=sttaf[i].go3;
				}
				else
				{
					zu2+=1;
					mmax+=sttaf[i].go2; 
				}
			}
			else if(sttaf[i].go3== sttaf[i].go2 && sttaf[i].go1>sttaf[i].go3)
			{
				if((n/2)>=zu1)
				{
					zu3+=1;
					mmax+=sttaf[i].go1;
				}
				else
				{
					if((n/2)>=zu2)
					{
						zu2+=1;
						mmax+=sttaf[i].go2;
					} 
					else
					{
						zu3+=1;
						mmax+=sttaf[i].go3;
					 }
				}
			}
			else if(sttaf[i].go3== sttaf[i].go2 && sttaf[i].go1<sttaf[i].go3)
			{
				if((n/2)>=zu3)
				{
					zu3+=1;
					mmax+=sttaf[i].go3;
				}
				else if((n/2)>=zu2)
				{
					zu2+=1;
					mmax+=sttaf[i].go2;
				}
				else
				{
					zu1+=1;
					mmax+=sttaf[i].go1;
				}
			}
			else
			{
				if((n/2)>=zu1)
				{
					zu1+=1;
					mmax+=sttaf[i].go1; 
				 } 
				 else if((n/2)>=zu2)
				 {
				 	zu2+=1;
				 	mmax+=sttaf[i].go2;
				 }
				 else
				 {
				 	zu3+=1;
				 	mmax+=sttaf[i].go3;
				 }
			}
			cout<<"zu1:"<<zu1<<endl;
			cout<<"zu2:"<<zu2<<endl;
			cout<<"zu3:"<<zu3<<endl<<endl; 		
			cout<<mmax<<endl;
		}

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
