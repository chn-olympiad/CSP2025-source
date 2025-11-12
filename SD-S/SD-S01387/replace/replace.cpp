#include<bits/stdc++.h>
using namespace std;
int n,t,a[5500000],m,p;
string l[220000],r[220000];
string x,y;
map<string,int>mp;
int qw(string d){
//	cout<<">>>>  "<<d<<'\n';
//	printf("\n\n\n\n\n");
	int ioto=0;
	if(d==y){
		return 1;
	} 
	if(mp[d]==234){
		return 0;
	}
	mp[d]=234;
	for(int i=1;i<=n;i++){
		if(d.find(l[i])!=-1){
			int ui=d.find(l[i]),o=l[i].size(),pp=d.size();
			string u=d.substr(0,ui-1)+r[i]+d.substr(ui+o-1,pp);
//			cout<<d<<"       "<<u<<'\n';
			ioto+=qw(u);
		}
	}
	return ioto; 
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
	}
	while(t--){
		cin>>x>>y;
		m=p=0;
		printf("%d\n",qw(x));
	}
	return 0;
}
