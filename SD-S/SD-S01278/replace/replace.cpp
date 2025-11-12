#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
string t1[200005],t2[200005];
long long ans=0;
void solve1()
{
	for(int i=1;i<=q;i++){
		int L=t1[i].length();
		ans=0;
		for(int j=1;j<=n;j++){
			int l=s1[j].length();
			for(int p=0;p+l<=L;p++)
			{
				int flag=1;
				for(int k=p;k<p+l;k++){
					if(t1[i][k]!=s1[j][k-p]){
						flag=0;
						break;
					}
				}
				if(!flag)	continue;
				string c=t1[i];
				for(int k=p;k<p+l;k++){
					c[k]=s2[j][k-p];
				}
				int f=1;
				for(int k=0;k<L;k++){
					if(c[k]!=t2[i][k]){
						f=0;
						break;
					}
				}
				ans+=f;
			}
		}
		cout<<ans<<endl;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio,cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)	cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++)	cin>>t1[i]>>t2[i];
	solve1();
	return 0;
}
