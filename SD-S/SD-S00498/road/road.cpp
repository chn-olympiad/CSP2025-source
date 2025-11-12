#include <iostream>
#include <vector>
using namespace std;
struct node
{
	int name,pr;
};
struct road
{
	int x,y,pr;
 } ; 
int coun[1000];
vector < vector <node> > a;
int n,m,k;//城市，道路，乡村
bool t[100000];
int cns=1e9;
bool bian()
{
	for(int i=0;i<=n;i++)
		{
			if(!t[i])
		{
			return 0;
		}
		}
	return 1;
}
void bfs(int q,int pri)
{
	if(bian())
	{	
		for(int i=n+1;i<n+k+1;i++)
		{
		if(t[i]==1)
		pri+=coun[i];
		}
		cns=min(cns,pri);
	//	cout<<1;
		return;
}
	while(!a[q].empty())
	{
		node e=a[q].front();

		a[q].erase(a[q].begin());
		if(t[e.name]=0)
		{
			t[e.name]=1;
			bfs(e.name,pri+e.pr);
			t[e.name]=0;
		}
	}
	
}
int main()
{
	vector <road> f;
	freopen("road1.in","r",stdin);
	//freopen("road1.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		
		int x,y,z;
		cin>>x>>y>>z;
		//cout<<"i:"<<i<<' ';
		
		f.push_back(road{x,y,z});
		///cout<<"i:"<<i<<' ';
	 } 
	// cout<<1;
	 for(int i=0;i<k;i++)
	 {
	 	int x;
	 	cin>>x;
	 	coun[i]=x;
	 	for(int j=1;j<n+1;j++)
	 	{
	 		cin>>x;
	 		f.push_back(road{i+1+n,j,x});
		 }
	 }
	 vector <node> l;
	 for(int i=1;i<=n+k+1;i++)
	 {
	 	for(int j=0;j<f.size();j++)
	 	{
	 		if(f[j].x==i)
	 			l.push_back(node{f[j].y,f[j].pr});
			 if(f[j].y==i)
				 l.push_back(node{f[j].x,f[j].pr});
		 }
		 a.push_back(l);
		 l.erase(l.begin(),l.end());
	 }
	 bfs(1,0);
	 cout<<cns;
	return 0;
 } 
