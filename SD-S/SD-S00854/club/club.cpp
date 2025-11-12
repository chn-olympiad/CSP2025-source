#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+5;
int t;
struct node{
	int a,b,c,maxx;
	char ch;
}st[MAX];
bool cmp(node a,node b){
	return a.maxx>b.maxx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int p=n/2;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			st[i].a=x,st[i].b=y,st[i].c=z;
			st[i].maxx=max(x,max(y,z));
			if(st[i].maxx==x)
				st[i].ch='a';
			else if(st[i].maxx==y)
				st[i].ch='b';
			else
				st[i].ch='c';
		}
		sort(st+1,st+1+n,cmp);
	//	for(int i=1;i<=n;i++){
		//	cout<<st[i].a<<" ";
		//	cout<<st[i].b<<" ";
		//	cout<<st[i].c<<"\n";
		//}
		int cnta=0,cntb=0,cntc=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(st[i].ch=='a'){
				if(cnta<p){
					ans+=st[i].maxx;
				}else{
					st[i].maxx=max(st[i].b,st[i].c);
					if(st[i].maxx==st[i].b) st[i].ch='b';
					else st[i].ch='c';
					
				}
			}
		}	
	}
	return 0;
}        
