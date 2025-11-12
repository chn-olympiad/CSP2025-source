#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1);
	int w=0;
	int t=n*m;
	while(w<=m)
	{
		w++;
		for(int i=1;i<=n;i++)
		{
			if(w>m) break;
			if(a[t]==x)
			{
				cout<<w<<" "<<i;
				return 0;
			}
			t--;
		}
		w++;
		for(int i=n;i>=1;i--)
		{
			if(w>m) break;
			if(a[t]==x)
			{
				cout<<w<<" "<<i;
				return 0;
			}
			t--;
		}
	}
	return 0;
}