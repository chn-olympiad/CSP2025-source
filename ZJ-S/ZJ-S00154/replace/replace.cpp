#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,L=52e5+5;
int n,q,l,r,len,bh,Trie[L][27][2],rot[N][2],jd[2];
string x,y,nx,ny;
struct node{
	string a,b;
}rep[N];
map<pair<string,string>,int>M;
vector<int>tag[L][2];
void find(string a,string b){
	l=r=0;
	len=a.size();
	for(int i=0;i<len;++i)
		if(a[i]!=b[i]){
			l=i;
			break;
		}
	for(int i=len-1;i>=0;--i)
		if(a[i]!=b[i]){
			r=i;
			break;
		}
}
void Build(string x,int h,int num){
	int now=rot[h][0];
	len=x.size();
	for(int i=l-1;i>=0;--i){
		if(!Trie[now][x[i]-'a'][0]) Trie[now][x[i]-'a'][0]=++jd[0];
		now=Trie[now][x[i]-'a'][0];
	}
	tag[now][0].push_back(num);
	
	now=rot[h][1];
	for(int i=r+1;i<len;++i){
		if(!Trie[now][x[i]-'a'][1]) Trie[now][x[i]-'a'][1]=++jd[1];
		now=Trie[now][x[i]-'a'][1];
	}
	tag[now][1].push_back(num);
}
bool ma[N];
int find(string x,int h){
	int now=rot[h][0],cnt=0;
	len=x.size();
	memset(ma,false,sizeof(ma));
	
	for(int j=0;j<tag[now][0].size();++j)
		ma[tag[now][0][j]]=true;
	for(int i=l-1;i>=0;--i){
		if(!Trie[now][x[i]-'a'][0]) break;
		now=Trie[now][x[i]-'a'][0];
		for(int j=0;j<tag[now][0].size();++j)
			ma[tag[now][0][j]]=true;
	}
	
	now=rot[h][1];
	for(int j=0;j<tag[now][1].size();++j)
		if(ma[tag[now][1][j]]) ++cnt;
	for(int i=r+1;i<len;++i){
		if(!Trie[now][x[i]-'a'][1]) break;
		now=Trie[now][x[i]-'a'][1];
		for(int j=0;j<tag[now][1].size();++j)
			if(ma[tag[now][1][j]]) ++cnt;
	}
	return cnt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>rep[i].a>>rep[i].b;
		find(rep[i].a,rep[i].b);
		x=y="";
		for(int j=l;j<=r;++j){
			x+=rep[i].a[j];
			y+=rep[i].b[j];
		}
		if(!M[make_pair(x,y)]){
			M[make_pair(x,y)]=++bh;
			rot[bh][0]=++jd[0];
			rot[bh][1]=++jd[1];
		}
		Build(rep[i].a,M[make_pair(x,y)],i);
	}
	pair<string,string> now;
	while(q--){
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<'0'<<endl;
			continue;
		}
		find(x,y);
		nx=ny="";
		for(int i=l;i<=r;++i){
			nx+=x[i];
			ny+=y[i];
		}
		now=make_pair(nx,ny);
		if(!M[now]){
			cout<<'0'<<endl;
			continue;
		}
		cout<<find(x,M[now])<<endl;
	}
	return 0;
}
