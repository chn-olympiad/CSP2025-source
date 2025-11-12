#include<bits/stdc++.h>
using namespace std;
int n,m;
string a[200001],b[200001],c,d;
map<pair<string,string>,vector<array<int,4>>> e;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>a[i]>>b[i];
		int len=a[i].size();
		int l=0,r=len-1;
		while(a[i][l]==b[i][l])
		l++;
		while(a[i][r]==b[i][r])
		r--;
//		printf("l:%d r:%d\n",l,r);
		for(int j=l;j<=r;j++)
		x.push_back(a[i][j]),y.push_back(b[i][j]);
		e[{x,y}].push_back({i,l,r,len});
	}
//	for(auto i:e)
//	cout<<i.first.first<<" "<<i.first.second<<"\n";
	while(m--){
		string x,y;
		cin>>c>>d;
		int len=c.size();
		if(d.size()!=len){
			puts("0");
			continue;
		}
		int l=0,r=len-1;
		while(c[l]==d[l])
		l++;
		while(c[r]==d[r])
		r--;
//		printf("l:%d r:%d\n",l,r);
		for(int j=l;j<=r;j++)
		x.push_back(c[j]),y.push_back(d[j]);
		int o=0;
		for(auto t:e[{x,y}]){
			int i=t[0],L=t[1],R=t[2];
//			cout<<x<<" "<<y<<"\n";
			bool q=1;
			for(int j=1;min(l,L)>j;j++)
			if(a[i][L-j]!=c[l-j]||b[i][L-j]!=d[l-j]){
				q=0;
				break;
			}
			for(int j=1;j<=min(len-r,t[3]-R)-1;j++)
			if(a[i][R+j]!=c[r+j]||b[i][R+j]!=d[r+j]){
//				printf("%c %c %c %c\n",a[i][R+j],c[r+j],b[i][R+j],d[r+j]);
				q=0;
				break;
			}	
//			printf("%d %d\n",i,q);
			o+=q;		
		}
		printf("%d\n",o);
	}
	return 0;
}
