#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s1[N],s2[N];
string t1[N],t2[N];
vector<int> s[1005][1005];
int ans=0;
int n,q;
void dfs(int t,int u,string tt){
	int g=tt.size();
	if(u>=g) return;
	for(int i=1;i<=n;i++){
		int o=s[t][i].size();
		if(!o) continue;
		int f=0;
		int uu=0;
		for(int j=0;j<o;j++){
			for(int k=s[t][i][j];tt[k]==s1[i][f];k++){
				tt[k]=s2[i][f++];
				uu=k;
				cout<<uu<<endl;
			}
		}
		dfs(t,uu+1,tt);
		for(int j=0;j<o;j++){
			for(int k=s[t][i][j];k<=uu;k++){
				tt[k]=t1[t][k];
			}
		}
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i];
		cin>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i];
		cin>>t2[i];
	}
	for(int i=1;i<=q;i++){
		for(int k=1;k<=n;k++){
			int l1=t1[i].size();
			for(int j=0;j<l1;j++){
				int u=0;
				while(t1[i][j+u]==s1[k][u]) u++;
				if(u==s1[k].size()){
					s[i][k].push_back(j);
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		dfs(i,0,t1[i]);
	}
	cout<<ans<<endl;
	return 0;
}
