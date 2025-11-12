#include <bits/stdc++.h>
#define N 200005
using namespace std;
int n,q,m[N],p1[N],p2[N],tot1=0,tot2=0;
string s1[N],s2[N],t1,t2;
vector<int> nt1[N],nt2[N];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i],s1[i]=' '+s1[i],s2[i]=' '+s2[i];
	for(int x=1;x<=n;x++){
		m[x]=s1[x].size()-1;
		nt1[x].push_back(0);
		nt1[x].push_back(0);
		for(int i=2,j=0;i<=m[x];i++){
			while(s1[x][i]!=s1[x][j+1]&&j) j=nt1[x][j];
			if(s1[x][i]==s1[x][j+1]) j++;
			nt1[x].push_back(j);
		} 
		nt2[x].push_back(0);
		nt2[x].push_back(0);
		for(int i=2,j=0;i<=m[x];i++){
			while(s2[x][i]!=s2[x][j+1]&&j) j=nt2[x][j];
			if(s2[x][i]==s2[x][j+1]) j++;
			nt2[x].push_back(j);
		} 
	}
	while(q--){
		cin>>t1>>t2;	
		t1=' '+t1,t2=' '+t2;
		int len=t1.size()-1,l=0,r=0,ans=0;
		for(int i=1;i<=len;i++){
			if(t1[i]!=t2[i]){
				if(!l) l=i;
				r=i;
			}
		}
		for(int x=1;x<=n;x++){
			tot1=tot2=0;
			for(int i=1,j=0;t1[i];i++){
				while(t1[i]!=s1[x][j+1]&&j) j=nt1[x][j];
				if(t1[i]==s1[x][j+1]) j++;
				if(j==m[x]){
					p1[++tot1]=i;
					j=nt1[x][j];
				}
			}
			for(int i=1,j=0;t2[i];i++){
				while(t2[i]!=s2[x][j+1]&&j) j=nt2[x][j];
				if(t2[i]==s2[x][j+1]) j++;
				if(j==m[x]){
					p2[++tot2]=i;
					j=nt2[x][j];
				}
			}
			int i=1,j=1;
			while(i<=tot1&&j<=tot2){
				if(p1[i]==p2[j]){
					if(p1[i]-m[x]+1<=l&&p1[i]>=r) ans++;
					i++,j++;
				}
				else if(p1[i]<p2[j]) i++;
				else if(p1[i]>p2[j]) j++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}//50
