#include<bits/stdc++.h>
using namespace std;
string s;
queue<int> q;
int a[1000005],ans[1000005],n;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
  for(int j=0;j<=s.size();j++)
  {
  	if(s[j]>='0'&&s[j]<='9') q.push(s[j]);
  }
  int i=0;
  while(!q.empty()){
  
	 n=i; 	
  	int c=q.front();
  	q.pop();
  	a[i]=c-'0';
  	//cout<<a[i];
  	i++;
  	
}
   sort(a,a+n+1,cmp);
   for(int j=0;j<=n;j++)
  {
   cout<<a[j];
  }
	return 0;
}
