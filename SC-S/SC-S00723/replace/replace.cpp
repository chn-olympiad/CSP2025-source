#include<bits/stdc++.h>
#define ll long long
#define ay array<string,2>
using namespace std;
ll n,m;
string str1,str2,str3,str4,str5,str6;
map<ay,ll>vis;
ay aa;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>str1>>str2;
		aa[0]=str1;aa[1]=str2;
		vis[aa]=1;
//		cout<<aa[0]<<" "<<aa[1]<<" "<<vis[aa]<<'\n';
	}	
	for(ll i=1;i<=m;i++)
	{
		ll ans=0;
		cin>>str1>>str2;
		ll id1,id2;
		ll l=str1.size();l--;
		for(ll j=0;j<=l;j++)
			if(str1[j]!=str2[j])
			{id1=j;break;}
		for(ll j=l;i>=0;j--)
			if(str1[j]!=str2[j])
			{id2=j;break;}
		str3="";str4="";
		for(ll i=id1;i<=id2;i++)
			str3+=str1[i],str4+=str2[i];
		aa[0]=str3;aa[1]=str4;
		for(ll i=id1;i>=0;i--)
		{
			str5=str3;str6=str4;
//			cout<<str5<<" "<<str6<<'\n';
			if(i<id1)
			str3=str1[i]+str3,str4=str2[i]+str4;
			for(ll j=id2;j<=l;j++)
			{
				if(j>id2)
				str5+=str1[j],str5+=str2[j];
				aa[0]=str5;aa[1]=str6;
				if(vis[aa])
					ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}