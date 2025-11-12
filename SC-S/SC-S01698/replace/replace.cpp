#include<bits/stdc++.h>
using namespace std;
map<string,string> m;
long long n,q;
string zc(int l,int r,string x){
	string re;
	for(int i=l;i<=r;i++){
		re+=x[i];
	}return re;
}
long long rp(string x,string y){
	long long re=0;
	if(m[x]==y){
		re++;
	}
	for(int i=0;i<x.size();i++){
		for(int j=x.size()-1;j>i;j--){
			if(zc(0,i,x)==zc(0,i,y)&&zc(j,x.size()-1,x)==zc(j,x.size()-1,y)){
				if(m[zc(i+1,j-1,x)]==zc(i+1,j-1,y)){
					re++;
				}
			}
		}
	}return re;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		m[x]=y;
	}for(int i=1;i<=q;i++){
		string x,y;
		cin>>x>>y;
		cout<<rp(x,y)<<endl;
	}
	return 0;
}