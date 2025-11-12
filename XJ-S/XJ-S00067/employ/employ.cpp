#include<bits/stdc++.h>
using namespace std;
struct node{
	int id;
	int nx;
	bool fq;
};
struct node a[510];
struct node b[510];
int n,m;
int kyp;
int yyp;
int z=1;
string s;
int ans=0;
bool vis[510];
bool cmp(node aa,node bb){
	return aa.nx>bb.nx;
}
void px(){
	for
}
void f(int rs,int jnx){
	if(yyp>=m){
		ans++;
		for(int i=1;i<=n;i++){
			a[i].fq=b[i].fq;
			a[i].nx=b[i].nx;
		}
		return;
	}
	if(kyp+yyp<m)return;
	for(int i=1;i<=kyp;i++){
		if(a[i].fq!=true){
			a[i].nx-=jnx;
			if(a[i].nx<0){
				kyp--;
				a[i].fq=true;
			}
		}
	}
	jnx=0;
	if(s[rs]==0){
		jnx=1;
	}else{
		yyp++;
		kyp--;
	}
	f(rs++,jnx);
}
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin>>n>>m;
	kyp=n;
	yyp=0;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i].nx;
		a[i].id=i;
		a[i].fq=false;
		b[i].nx=a[i].nx;
		b[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	cout<<ans;
	return 0;
} 
/*
3 2
101
1 1 2
*/
