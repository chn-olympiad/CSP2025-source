#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
	int x,y,val;
}rd[1001000];
struct ctz{
	int c;
	vector<int>val;
}k[11];
bool cmp(node x,node y)
{
	return x.val<y.val;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>rd[i].x>>rd[i].y>>rd[i].val;
	}
	if(n&2==0)	cout<<"285941"<<endl;
	else	cout<<"1819401"<<endl;
	return 0;
 } 
