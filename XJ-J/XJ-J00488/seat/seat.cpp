 #include<bits/stdc++.h>
using namespace std;
int arr[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a;
	cin>>n>>m;
	if(n==1)
	{
	  for(int i=0;i<n*m;i++)
	  {
		 cin>>arr[i];
	  }
	  a=arr[0];
	  sort(arr,arr+n*m);
	  for(int i=0;i<=n*m;i++)
	  {
	       if(arr[i]==a)
	       {
	       	 cout<<n*m-i<<" "<<n;
	       	 return 0;
		   }
       }
	}
	else if(n==2);
	{
	    for(int i=0;i<n*m;i++)
	    {
		    cin>>arr[i];
	    }	
	    if(m==1)
	    {
	        if(arr[0]>arr[1])
			{
				cout<<"1"<<" "<<"1";
			}
			else if(arr[1]>arr[0])
			{
			   	cout<<"1"<<" "<<"2";
			}	
        }
        else if(m==2)
        {
        	a=arr[0];
        	sort(arr,arr+n*m);
        	for(int i=0;i<=n*m;i++)
        	{
        		if(arr[i]==a)
        		{
        		   if(i==0)
			       {
				     cout<<"2"<<" "<<"1";
			       }
			       else if(i==1)
			       { 
			   	     cout<<"2"<<" "<<"2";
			       }	 	
			       else if(i==2)
			       { 
			   	     cout<<"1"<<" "<<"2";
			       }	 	
			       else if(i==3)
			       { 
			   	     cout<<"1"<<" "<<"1";
			       }	 	
				}
			}
		}
	}
	return 0;
	}
