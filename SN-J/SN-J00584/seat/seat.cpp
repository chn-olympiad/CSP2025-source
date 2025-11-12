#include<bits/stdc++.h>
using namespace std;
int n,m,score[100],s;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>score[i];
	s=score[0];
	sort(score,score+n*m,cmp);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(score[i*m+j]==s)
				cout<<i+1<<' '<<(i%2?m-j:j)+1;
		}
	}
	return 0;
}

