#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int a[N];
int m,n;
int score_r; 
int row=1,lol=1;
int main()
{ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//ÊäÈëÊä³ö 
	cin>>m>>n;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	score_r=a[1];
	sort(a,a+m*n+1);
	//cout<<score_r; 
	for(int i=m*n;i>=1;i--)
	{
		if(a[i]==score_r)
		{
			cout<<lol<<" "<<row; 
			break;
		}
		else if(lol%2!=0)
		{
			if(row==n)
			{
				lol++;			
			} 
		    else
		    {
			    row++;
	        }
	    }
		else
		{
			if(row==1)
			{
				lol++;
			}
			else 
			{
				row--;
			}
		}			
	}
	return 0;
 } 
