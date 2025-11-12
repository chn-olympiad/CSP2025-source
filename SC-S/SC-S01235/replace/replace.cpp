#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long p1=1e9+7;
struct node{
	long long from,to;
	string s2;
}biao[200005];
ll toh(string s,int start,int end)
{
	ll ans1=0;
	for(int i=start;i<=end;i++)
	{
		ans1=ans1*27+s[i]-96;
		ans1%=p1;
	}
	//cout<<ans1<<' '<<s<<endl; 
	return ans1;
}
bool cmp(node e1,node e2)
{
	return e1.from<e2.from;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s1,s2;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		biao[i].from=toh(s1,0,s1.length()-1);
		biao[i].to=toh(s2,0,s2.length()-1);
		biao[i].s2=s2;
	}
	sort(biao+1,biao+n+1,cmp);
	long long hsh;
	long long h1,h2;
	long long pos1,pos2;
	int cnt=0;
	for(int i1=1;i1<=q;i1++)
	{
		cin>>s1>>s2;
		long long ans=0;
		hsh=toh(s2,0,s2.length()-1);
		for(int j=0;j<s1.length();j++)
		{
			for(int k=0;k<s1.length();k++)
			{
				h1=toh(s1,j,k);
				for(int i=1;i<=n;i++)
				{
					//cout<<biao[i].from<<' '<<i<<' '<<h1<<' '<<j<<' '<<k<<' '<<endl; 
					if(biao[i].from==h1)
					{
						cnt=0;
						long long s3=0;
						for(int k1=0;k1<j;k1++)
						{
							s3=(s3*27+s1[k1]-96)%p1;
							//cout<<s1[k1];
						}
						for(int k1=0;k1<biao[i].s2.length();k1++)
						{
							s3=(s3*27+biao[i].s2[k1]-96)%p1;
							//cout<<biao[i].s2[k1];
						}
						for(int k1=k+1;k1<s1.length();k1++)
						{
							s3=(s3*27+s1[k1]-96)%p1;
							//cout<<s1[k1];
						}
						//cout<<"- ";
						if(s3==hsh) ans++;
						//cout<<s3<<' '<<hsh<<endl;
					} 
				}
			}
		}
		cout<<ans<<endl;
	}
}