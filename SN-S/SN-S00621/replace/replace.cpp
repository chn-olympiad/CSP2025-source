#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
string s1[200005],s2[200005];
bool check_same(int a1,int a2,string sa,string sb)
{
	cout<<"check"<<a1<<' '<<a2<<' '<<sa<<' '<<sb<<endl;
	for(;a1<=a2;a1++)
	{
		if(sa[a1]!=sb[a1])return false;
	}
	cout<<"okk";
	return true;
}
bool check(string t1,int pos,string ss1,string ss2,string t2)
{
	//check(t1,i,s1[j],s2[j],t2)
	
	if(pos+ss1.length()>ss2.length())return false;
	
	
	if(pos!=0)if(!check_same(0,pos-1,t1,t2)) return false;
	if(!check_same(pos+ss2.length(),t1.length(),t1,t2))return false;
	
	//return strcmp(ss1,ss2);

return check_same(0,ss1.length(),ss1,ss2);	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
 
 int n,q;
 cin>>n>>q;
 for(int i=0;i<n;i++)
 {
 	cin>>s1[i]>>s2[i];
 }
 
 while(q--)
 {
 	string t1,t2;
 	cin>>t1>>t2;
 	int ans=0;
 	for(int i=0;i<n;i++)
 	{
 		for(int j=0;j<n;j++)
 		if(check(t1,i,s1[j],s2[j],t2))ans++;
 		
	 }
	 cout<<ans<<endl;
 	
 }
	return 0;
}
