#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct name
{
	int lo,cl;	
};
name a[100000][3];
struct club
{
	vector <int> love;
	int l=0;
	int re=0;	
}; 
club clu[3];

bool com(name a,name b)
{
	return a.lo>b.lo;
}
bool cmp(int c,int b)
{
	return abs(a[c][1].lo-a[c][0].lo)>abs(a[b][1].lo-a[b][0].lo);
}
int main()
{
	freopen("club1.in","r",stdin);
	freopen("club1.out","w",stdout);
vector <int> answer;
int t;
cin>>t;
for(int k=0;k<t;k++)
{
	
	int n;
	cin>>n;

	for(int i=0;i<n;i++)
		cin>>a[i][0].lo>>a[i][1].lo>>a[i][2].lo;
	for(int i=0;i<n;i++)
	{
		sort(a[i][0].lo,a[i][2].lo,com);
	
	clu[a[i][0].cl].re++;
	clu[a[i][0].cl].l+=a[i][0].lo;
	clu[a[i][0].cl].love.push_back(i);
	}	
	for(int i=0;i<3;i++)
	{
		if(clu[i].re>n/2)
		sort(clu[i].love.begin(),clu[i].love.end(),com);
		
	}
	}
	answer.push_back(clu[0].l+clu[1].l+clu[2].l);
	 for(int i=0;i<3;i++)
	 {
	 	clu[i].love.erase(clu[i].love.begin(),clu[i].love.end());
	 	clu[i].l=0;
	 	clu[i].re=0;
	 }
	for(int i=0;i<answer.size();i++)
		cout<<answer[i]<<endl;
	return 0;
}
