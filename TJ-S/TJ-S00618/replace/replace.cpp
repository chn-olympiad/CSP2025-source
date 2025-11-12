#include<bits/stdc++.h>
using namespace std;
int n,m,p1,p2,b[4][200005],ans,dp1,dp2,id1,id2;
string x,y;
bool f;
vector<int> v1[200005],v2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	/* */
	if(m<=1000){
		for(int i=1;i<=n;i++)
		{
			cin>>x>>y;
			//cout<<x[0];
			
			for(int j=0;j<x.size();j++){
				v1[i].push_back((int)x[j]);
			}
			for(int j=0;j<y.size();j++){
				v2[i].push_back((int)y[j]);
			}
		}
		for(int o=1;o<=m;o++)
		{
			cin>>x>>y;
			ans=0;
			for(int i=0;i<x.size();i++){
				if(x[i]!=y[i]){
					dp1=i;
					break;
				}
			}
			for(int i=x.size()-1;i>=0;i--){
				if(x[i]!=y[i]){
					dp2=i;
					break;
				}
			}
			//cout<<dp1<<" "<<dp2<<"\n";
		
			int j,k;
			for(int i=1;i<=n;i++){
				id1=id2=-1;
				for(j=0;j<=min( dp1 , (int)x.size()-(int)v1[i].size() );j++){
					if((int)x[j]==v1[i][0])
					f=1;
					for(k=j;k<j+v1[i].size();k++){
						if((int)x[k]!=v1[i][k-j]){
							f=0;
							break;
						}
					}
					if(f)
					{
						id1=j;
					}
				}
				if(id1==-1) continue;
			
				for(j=0;j<=min(dp1,(int)y.size()-(int)v2[i].size());j++){
					if((int)y[j]==v2[i][0])
					f=1;
					for(k=j;k<j+v2[i].size();k++){
						if((int)y[k]!=v2[i][k-j]){
							f=0;
							break;
						}
					}
					if(f)
					{
						id2=j;
						break;
					}
				}
				//cout<<id1<<" "<<id2<<"\n";
				if(id1==id2 and id1<=dp1 and id2<=dp1 and id1+v1[i].size()>dp2){
					ans++;
				}
			}
			cout<<ans<<"\n";
		}
		
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		p1=x.find('b');
		p2=y.find('b');
		b[1][i]=p1;
		b[2][i]=x.size()-1-p1;
		b[3][i]=p2-p1;
		//cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<"\n";
		//cout<<p1<<" "<<p2<<endl;
		//cout<<x<<" "<<y<<"\n";
	}
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		ans=0;
		p1=x.find('b');
		p2=y.find('b');
		for(int i=1;i<=n;i++){
			if(p1>=b[1][i] and x.size()-1-p1>=b[2][i] and p2-p1==b[3][i])
			{
				ans++;
			}
		}
		cout<<ans<<"\n";
		//cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<"\n";
		//cout<<p1<<" "<<p2<<endl;
		//cout<<x<<" "<<y<<"\n";
	}
	//cout<<ans;
	return 0;
}
