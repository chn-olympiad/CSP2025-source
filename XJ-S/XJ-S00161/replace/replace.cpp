#include<bits/stdc++.h>
using namespace std;
unsigned long long ha[1000005],pre1[5000005],pre2[5000005],p[5000005];
string s1,s2,s3,s4;
const int N=1e6+3;
int n,q;
int fun()
{
	long long sum=0,cnt=0;
	for(int i=0;i<s1.size();i++)
	sum=(sum*131+s1[i])%N;
	cnt+=sum;
	sum=0;
	for(int i=0;i<s2.size();i++)
	sum=(sum*131+s2[i])%N;
	cnt=cnt+13331*sum;
	return cnt;
}
void fun2()
{
	for(int i=0;i<s1.size();i++)
	pre1[i]=(pre1[i-1]*131+s1[i]);
	for(int i=0;i<s2.size();i++)
	pre2[i]=(pre2[i-1]*131+s2[i]);	
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	p[0]=1;
	for(int i=1;i<=5000000;i++)
	p[i]=p[i-1]*131;
	while(n--)
	{
		cin>>s1>>s2;
		ha[fun()]++;
	}
	while(q--)
	{
		cin>>s1>>s2;
		int len=s1.size(); 
		if(s1.size()!=s2.size()||s1==s2)
		{
			cout<<0<<"\n";
			continue;
		}
		int R=0,L=0;
		for(int i=0;i<len;i++)
		if(s1[i]!=s2[i])
		{
			L=i;
			break;
		}
		for(int i=len-1;i>=0;i--)
		if(s1[i]!=s2[i])
		{
			R=i;
			break;
		}
		fun2();
		int ans=0;
		for(int l=1;l<=L+1;l++)
		for(int r=R+1;r<=len;r++)
		ans+=ha[((pre2[r]-pre2[l-1]*p[r-l+1]+13331*(pre1[r]-pre1[l-1]*p[r-l+1]))%N+N)%N];
		cout<<ans<<endl;
	}
	return 0;
}

