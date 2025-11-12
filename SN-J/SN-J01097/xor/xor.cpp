#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,aa[50000001],mid[50000001],ma,mi=INT_MAX,ans=1;
vector<int> a[50000001];
struct node{
	int x,y;
};

vector<int> q,kk;
void dfs(int x,int y)
{
	while(x>1){
		a[y].push_back(x%2);
		x=x/2;
	}
	a[y].push_back(x);
}
vector <node> o;

bool emp(node xx,node yy)
{
	return xx.y<yy.y;
}
void ddd(int xx,int yy)
{
	for(int i=xx;i<=yy;i++)
	{
		for(int j=0;j<a[i].size();j++){
			int h=a[i].size();
			ma=max(ma,h);
			if(mid[j]==1&&a[i][j]==1)
			{
				mid[j]=0;
				continue;
				}
			if(mid[j]==1||a[i][j]==1)
			mid[j]=1;
		}
	}
	for(int i=ma;i>0;i++)
	{
		if(mid[i-1]==0)
		ma--;
		else
		break;
	}
	if(kk.size()!=ma)
	return ;
	for(int i=0;i<ma;i++)
	{
		if(kk[i]!=mid[i])
		return ;
	}
	node ttt;
	ttt.x=xx;
	ttt.y=yy;
	o.push_back(ttt);
}

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>aa[i];
	}
	if(k==0){
		ans--;
		for(int i=1;i<=n;i++){
			if(aa[i]==0)
			ans++;
		}
		cout<<ans;
		return 0;
	}
	int cc=k; 
	while(cc>1){
		kk.push_back(cc%2);
		cc=cc/2;
	}
	
	kk.push_back(cc);
		
	for(int i=1;i<=n;i++)
	{
		dfs(aa[i],i);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++){
			ddd(i,j);
			for(int i=0;i<ma;i++)
			mid[i]=0;
			ma=0;	
		}
	}
	for(int j=0;j<o.size();j++){
		mi=min(mi,o[j].y);
}
if(mi==INT_MAX){
	cout<<0;
	return 0;
}
  int mii=mi;
	for(int i=1;i<=o.size();i++)
	{
		mii=INT_MAX;
		for(int j=0;j<o.size();j++){
			if(o[i].x>mi&&o[i].y<mii){
				mii=o[i].y;
			}
		}
		if(mii!=INT_MAX){
		ans++;
		mi=mii;
}		 
	}
	cout<<ans;
	return 0;
}
