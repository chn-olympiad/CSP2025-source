#include<bits/stdc++.h>
using namespace std;
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int N,M,hang=1,lie=1;

int main()
{
	cin>>N>>M;
	int seats[N*M],R_score;
	for(int i=0;i<N*M;i++)
	{
		cin>>seats[i];
		
	}
	R_score=seats[0];
	sort(seats,seats+(N*M));
	
	for(int i=0;i<N*M;i++)
	{
		cout<<seats[i]<<endl;
		
	}
	
	for(int i=N*M-1;i>=0;i--)
	{
		if((N*M-i)>N*lie)
		{
			lie++;
		}
		
	}
	
	return 0;
}
