#include<bits/stdc++.h>
#define N 200005
#define fi first
#define se second
using namespace std;
void r(int&x){//u32
	x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}return;
}
int n,q;
pair<string,string> a[N];
int nokmp(string a,string b,string c,string d){
	int piv=0,lena=a.length(),lenc=c.length();
	for(int i=0;(i+piv)<lenc;++i){
		if((a[i]!=c[i+piv])||(b[i]!=d[i+piv])){
			piv+=i+1;i=-1;continue;
		}
		if(i==(lena-1)){
			return 1;
		}
	}return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;string tmpa,tmpb;
	for(int i=1;i<=n;++i){
		cin>>tmpa>>tmpb;
		a[i]=make_pair(tmpa,tmpb);
	}
	for(int i=1;i<=q;++i){
		int tmp=0;
		cin>>tmpa>>tmpb;int xl=tmpa.length();
		int diff=0;
		for(int x=0;x<xl;++x){
			if(tmpa[x]!=tmpb[x])++diff;
		}
		for(int j=1;j<=n;++j){
			if(diff>a[j].fi.length())continue;
			tmp+=nokmp(a[j].fi,a[j].se,tmpa,tmpb);
		}
		cout<<tmp<<endl;
	}
	return 0;
}
