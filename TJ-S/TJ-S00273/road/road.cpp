#include<iostream>
#include<vector>
#include<stack>
using namespace std;
bool vis[999999];
int dfs(int st,vector<pair<int,pair<int,int> > >vec,int n,int pr,int mpr)
{
	stack<int>T;
	T.push(st);
	
	vis[st]=true;

		if(!T.empty())
		{
		for(int i=0;i<vec.size();i++){
		
		if(vec[i].second.first==st&&vis[vec[i].second.second]==false)
		{
			pr=pr+vec[i].first;
			vis[vec[i].second.first]==true;
			bool S=true;
			for(int j=1;j<n;j=j+1)
			{
				if(!vis[j])
				{
					S=!S;
					break;
				}
				
			}
			if(S)
			{
				if(pr<mpr)
				{
					mpr=pr;
					
				}
			
				
			}
			else{
			
			dfs(vec[i].second.second,vec,n,pr,mpr);
			T.pop();
			vis[vec[i].second.first]=false;
			}
			}	
		}}
		return mpr; 
	
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,A,B;
	cin>>n>>m>>k;
	const int N=n;
	vector<pair<int,pair<int,int> > >vec;
	pair<int,pair<int,int> > al824;
	pair<int,pair<int,int> > al9a1;
	for(int i=0;i<m;i++)
	{
		cin>> al824.first>>al824.second.first>>al824.second.second;
		al9a1.first=al824.first;
		al9a1.second.second=al824.second.first;
		al9a1.second.first=al824.second.second;
		vec.push_back(al824);
		vec.push_back(al9a1);
	} 
	for(int j=0;j<k;j++)
	{
	cin>>A;
	for(int i=0;i<n;i++){
		cin>>B;
	al9a1.first=A+B;
	al824.first=A+B;
	al9a1.second.second=i;
	al824.second.first=i;
		al9a1.second.first=n+j;
		al9a1.second.second=n+j;
		vec.push_back(al824);
		vec.push_back(al9a1);}	
	}
	cout<<dfs(1,vec,n,0,13);
}
