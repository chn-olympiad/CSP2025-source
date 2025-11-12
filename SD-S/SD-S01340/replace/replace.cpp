#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PSS pair<string,string>
#define PUU pair<unsigned long long,unsigned long long>
using namespace std;

const int N=2e5+10,P=1313131;
ull haxi[N];
int n,q;
PSS s[N];
ull has[N];


int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
	    cin>>s[i].first>>s[i].second;	
	    string us1=s[i].first,us2=s[i].second;
	    haxi[1]=us1[0]-'a'+1;
	    for(int j=2;j<=us1.size();j++)
	    {
	    	haxi[j]=haxi[j-1]*P+us1[j-1]-'a'+1;
		}
		has[i]=haxi[us1.size()];
		
		haxi[1]=us2[0]-'a'+1;
	    for(int j=2;j<=us2.size();j++)
	    {
	    	haxi[j]=haxi[j-1]*P+us2[j-1]-'a'+1;
		}
		ull temp=haxi[us2.size()]-has[i];
		if(temp<0) temp*=-1;
		has[i]=temp%P;
	}
	while(q--)
	{
		ll ans=0;
		string s1,s2;
		cin>>s1>>s2;
		haxi[1]=s1[0]-'a'+1;
	    for(int j=2;j<=s1.size();j++)
	    {
	    	haxi[j]=haxi[j-1]*P+s1[j-1]-'a'+1;
		}
		ull has1=haxi[s1.size()];
		
		haxi[1]=s2[0]-'a'+1;
	    for(int j=2;j<=s2.size();j++)
	    {
	    	haxi[j]=haxi[j-1]*P+s2[j-1]-'a'+1;
		}
		ull has2=haxi[s2.size()];
		ull temp=has2-has1;
		if(temp<0) temp*=-1;
		temp%=P;
		for(int i=1;i<=n;i++)
		{
			if(temp==has[i]) ans++;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


















//_________________________________________________________

