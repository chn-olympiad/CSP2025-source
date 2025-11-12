#include <bits/stdc++.h>
using namespace std;

int n,m,score,lie_ans,hang_ans;

bool compare(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num[n*m+1];
	for(int i=0;i<n*m;++i)
	{
		cin>>num[i];
	}
	score=num[0];
	sort(num,num+n*m,compare);
	
	int p=find(num,num+n*m,score)-num+1;
	int lie=p/n;
	if(lie%2==0)
	{
		if(n*lie!=p)
		{
			lie_ans=lie+1;
			hang_ans=p-lie*n;
		}
		else
		{
			lie_ans=lie;
			hang_ans=n;
		}
	}
	else
	{
		if(n*lie!=p)
		{
			lie_ans=lie+1;
			hang_ans=n-(p-n*lie)+1;
		}
		else
		{
			lie_ans=lie;
			hang_ans=n;
		}
	}
	cout<<lie_ans<<" "<<hang_ans;
	return 0;
}
