#include<bits/stdc++.h>
using namespace std;
map<string,map<string,int> >p;
vector<string>f[1000010];
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	int k=1;
	for(int d=0;d<n;d++){
		cin>>a>>b;
		int s=a.size();
		int i=0,j=0;
		for(int c=0;c<s;c++){
			if(a[c]!=b[c]){
				i=c;
				break;
			}
		}
		for(int c=s-1;c>=0;c--){
			if(a[c]!=b[c]){
				j=c;
				break;
			}
		}
		string x="",y="";
		for(int c=i;c<=j;c++){
			x+=a[c];
			y+=b[c];
		}
		if(!p[x][y]){
			p[x][y]=k;
			k++;
		}
		f[p[x][y]].push_back(a);
	}
	for(int c=0;c<q;c++){
		cin>>a>>b;
		int s=a.size();
		int i=0,j=0;
		for(int d=0;d<s;d++){
			if(a[d]!=b[d]){
				i=d;
				break;
			}
		}
		for(int d=s-1;d>=0;d--){
			if(a[d]!=b[d]){
				j=d;
				break;
			}
		}
		string x="",y="";
		for(int d=i;d<=j;d++){
			x+=a[d];
			y+=b[d];
		}
		int e=0;
		int z=f[p[x][y]].size();
		for(int d=0;d<z;d++){
			if((int)a.find(f[p[x][y]][d])!=-1){
				e++;
			}
		}
		cout<<e<<"\n";
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/