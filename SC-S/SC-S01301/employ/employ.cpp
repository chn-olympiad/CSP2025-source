#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,n;
string s;
int c[505];
int yy=0;
int cd;
int zh;
vector<int> v;
int vs[505]={0};
dfs(int id){
	if(id==n){
		int tt=0;
		int zz=0;
		for(int i=0;i<v.size();i++){
			if(s[i+1]=='1'&&c[v[i]]>tt){
				zz++;
			}
			else{
				tt++;
			}
			if(tt>n-m){
				break;
			}
		}
		if(zz>=m){
			zh++;
		}
//		for(int i=0;i<v.size();i++){
//			cout<<v[i]<<" ";
//		}
//		cout<<"\n";
	}
	for(int i=1;i<=n;i++){
		if(vs[i]==0){
			vs[i]=1;
			v.push_back(i);
			dfs(id+1);
			v.pop_back();
			vs[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	cd=s.size()-1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<s.size();i++){
		if(s[i]=='1'){
			yy++;
		}
	}
	if(n<=18){
		dfs(0);
		cout<<zh;
	}

		int ry=n;
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				ry--;
			}
		}
		if(ry<m){
			cout<<0;
			return 0;
		}
		int sdd=1;
		while(1){
			sdd*=ry;
			ry--;
			if(ry==0){
				break;
			}
		}
		cout<<sdd;
		return 0;
	return 0;
}