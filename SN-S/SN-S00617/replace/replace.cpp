#include<bits/stdc++.h>
using namespace std;
string s[1010][3],str;
int num[1010][3];//12 34 56 78 -2n
void findb(int l,int r,int i)
{
	int mid=(l+r)/2;
	if(str[mid]=='b')
	{
		num[i][1]=mid-1;
		num[i][2]=str.size()-mid;
		return;
	}
	findb(mid,r,i);
	findb(l,mid,i);
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n*2;i++)
	{
		cin>>str;
		findb(0,str.size()-1,i);
	}
	string t1,t2;
	int x=n*2+1,y=n*2+2;
	while(q--)
	{
		cin>>t1>>t2;
		findb(0,t1.size(),x);
		findb(0,t2.size(),y);
		long long ans=0;
		for(int i=1;i<=2*n;i+=2)//1 3 5 7 i,i+1
		{
			int numxy=num[x][1]-num[y][1];
if(num[x][1]>num[y][1])
{
	if((num[i][1]>=(num[x][1]-numxy) && num[i][1]<=num[x][1]) && (num[i][2]>=0 && num[i][2]<=num[x][2]) && (num[i+1][2]>=(num[x][1]-numxy) && num[i+1][2]<=num[x][1]) && (num[i+1][1]>=0 && num[i+1][1]<=num[x][2]))
	{
		ans++;
	}
}
if(num[x][1]<num[y][1])
{
	int c;
	c=num[x][1];
	num[x][1]=num[y][1];
	num[y][1]=num[x][1];
	c=num[x][2];
	num[x][2]=num[y][2];
	num[y][2]=num[x][1];
	numxy=num[x][1]-num[y][1];
	if((num[i][1]>=(num[x][1]-numxy) && num[i][1]<=num[x][1]) && (num[i][2]>=0 && num[i][2]<=num[x][2]) && (num[i+1][2]>=(num[x][1]-numxy) && num[i+1][2]<=num[x][1]) && (num[i+1][1]>=0 && num[i+1][1]<=num[x][2]))
{
	ans++;
}
}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
