#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n,m,a[N],tot;
string stra;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>stra;
	for(int i=0;i<stra.size();i++)
	{
		if(a[i]==1) tot++;
	}
	cout<<tot;
	return 0;
}
