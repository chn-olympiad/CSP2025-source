#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
inline void read(int &x){scanf("%d",&x);}
inline void write(int x){printf("%d",x);}
int n,q,l,r1,r2,tot;
string a,b;
struct Node{
	string x,ya,yb,z;
}node[MAXN];
vector<int>v[MAXN];
map<pair<string,string>,int>mp;
inline void pre(){
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int j=0;j<(int)a.length();j++){
			if(a[j]!=b[j]){
				l=j;
				break;
			}
			else node[i].x+=a[j];
		}
		for(int j1=(int)a.length()-1,j2=(int)b.length()-1;j1>=l&&j2>=l;j1--,j2--){
			if(a[j1]!=b[j2]){
				r1=j1;
				r2=j2;
				break;
			}
			else node[i].z=a[j1]+node[i].z;
		}
		for(int j=l;j<=r1;j++){
			node[i].ya+=a[j];
		}
		for(int j=l;j<=r2;j++){
			node[i].yb+=b[j];
		}
		if(!mp[{node[i].ya,node[i].yb}]){
			mp[{node[i].ya,node[i].yb}]=++tot;
		}
		v[mp[{node[i].ya,node[i].yb}]].push_back(i);
		// cout<<node[i].x<<" "<<node[i].ya<<" "<<node[i].yb<<" "<<node[i].z<<endl;
	}
	return;
}
inline bool check(string a,string b,string xa,string xb){
	if(xa.length()>a.length()||xb.length()>b.length()) return 0;
	for(int i=1;i<=(int)xa.length();i++){
		if(a[a.length()-i]!=xa[xa.length()-i]) return 0;
	}
	for(int i=0;i<(int)xb.length();i++){
		if(b[i]!=xb[i]) return 0;
	}
	return 1;
}
inline int solve(){
	cin>>a>>b;
	string x="",ya="",yb="",z="";
	for(int j=0;j<(int)a.length();j++){
		if(a[j]!=b[j]){
			l=j;
			break;
		}
		else x+=a[j];
	}
	for(int j1=(int)a.length()-1,j2=(int)b.length()-1;j1>=l&&j2>=l;j1--,j2--){
		if(a[j1]!=b[j2]){
			r1=j1;
			r2=j2;
			break;
		}
		else z=a[j1]+z;
	}
	for(int j=l;j<=r1;j++){
		ya+=a[j];
	}
	for(int j=l;j<=r2;j++){
		yb+=b[j];
	}
	// cout<<x<<" "<<ya<<" "<<yb<<" "<<z<<endl;
	if(!mp[{ya,yb}]) return 0;
	int ans=0;
	for(int i:v[mp[{ya,yb}]]){
		string dx=node[i].x,dz=node[i].z;
		// cout<<i<<" ";
		if(check(x,z,dx,dz)){
			ans++;
			// cout<<1<<endl;
		}
		// cout<<0<<endl;
	}
	return ans;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n),read(q);
	pre();
	while(q--){
		write(solve());
		putchar('\n');
	}
	return 0;
}