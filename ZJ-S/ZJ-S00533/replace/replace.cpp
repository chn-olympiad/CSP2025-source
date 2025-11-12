#include<bits/stdc++.h>
using namespace std;
string a[200015][2],b[200015][2],x[2];
int c[200015][2],n,q,ans=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1];
		c[i][1]=a[i][0].size();
		int o=0,p=0;
		while(a[i][0][o]==a[i][1][o]&&o<c[i][1]) o++;
		c[i][0]=o;
		for(p=o;a[i][0][p]!=a[i][1][p]&&p<c[i][1];p++)
			b[i][0]+=a[i][0][p],
			b[i][1]+=a[i][1][p];
	}	
	while(q--)
	{
		ans=0;
		int i=0,j=0;
		string s,d;
		cin>>x[0]>>x[1];
		while(x[0][i]==x[1][i]&&i<x[0].size()) i++;
		//cout<<"*"<<i<<endl;
		for(j=i;x[0][j]!=x[1][j]&&j<x[0].size();j++)
			s+=x[0][j],d+=x[1][j];
	//	cout<<s<<" "<<d<<endl;
		for(int r=1;r<=n;r++)
		{
			if(s==b[r][0]&&d==b[r][1])
			{
				int f=i-c[r][0],g=f+c[r][1]-1,flag=1;
				//cout<<f<<" "<<g<<endl;
				if(f<0 || g>=x[0].size()) continue;
				for(int u=f;u<=g;u++)
					if(x[0][u]!=a[r][0][u-f]) 
					{
					//	cout<<"*"<<u<<endl;
						flag=0;
					}
						
				if(flag && x[0].size()==x[1].size()) ans++;
			}
		}
		cout/*<<q<<" "*/<<ans<<endl;
	}
	return 0; 
}
