#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;

int n,m;
string s;int scnt;
int c[N];
bool tf[N];
vector<int>vec;
long long ans;

void dfs(int x,int h){
	if(h==x){
		int lin=0;
		for(int i=0;i<n;i++){
//			cout<<vec[i]<<' ';
			if(s[i]=='1'&&lin<vec[i])continue;
			else{
				lin++;
			}
		}
		if(x-lin>=m)ans++;
//		cout<<endl;
		return ;
	}
	else{
		for(int i=1;i<=n;i++){
			if(!tf[i]){
				vec.push_back(c[i]);
				tf[i]=1;
				dfs(x,h+1);
				vec.pop_back();
				tf[i]=0;
			}
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
//	sort(c+1,c+1+n);
	for(int i=0;i<n;i++){
		if(s[i]=='1')scnt++;
	}
	if(scnt<m){
		cout<<0;
		return 0;
	}
	dfs(n,0);
	cout<<ans;
	return 0;
} 