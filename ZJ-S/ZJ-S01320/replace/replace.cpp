#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
struct node{
	string val;
	int ste;
};
string a[N],b[N],x,y;
int n,q,ans;
int finds(string y,string x){
	for(int i=0;i<y.size()-x.size()+1;i++){
		if(y[i]!=x[0])continue;
		int flag=1;
		for(int j=0;j<x.size();j++){
			if(y[i+j]!=x[j]){
				flag=0;
				break;
			}
		}
		if(flag)return i;
	}
	return -1;
}
bool work(string y,int ad,string x,string mb){
	for(int i=0;i<y.size();i++){
		if(i==ad){
			for(int j=0;j<x.size();j++)
				if(x[j]!=mb[ad+j])return false;
			i=ad+x.size()-1;
			continue;
		}
		if(y[i]!=mb[i])return false;
	}
	return true;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	while(q--){
		cin>>x>>y,ans=0;
		for(int i=1;i<=n;i++){
			int tip=finds(x,a[i]);
			if(tip==-1)continue;
			if(work(x,tip,b[i],y))ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
