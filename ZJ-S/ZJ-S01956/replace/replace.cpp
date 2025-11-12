#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
string s1[200005],s2[200005];
bool p(string x,string y){
	if(x.size()>y.size()){
		return 0;
	}
	int l=0,r=0;
	while(r<y.size()){
		if(x[l]==y[r]){
			l++,r++;
		}else{
			l=0,r++;
		}
		if(l==x.size()){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		int a=0,b=0;
		if(x.size()!=y.size()){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]){
				a=i;
				break;
			}
		}
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]){
				b=i;
			}
		}
		string t="";
		for(int i=a;i<=b;i++){
			t+=y[i];
		}
		int sm=0;
		for(int i=1;i<=n;i++){
			if(p(s1[i],x)&&p(s2[i],y)&&p(t,s2[i])){
				sm++;
			}
		}
		cout<<sm<<"\n";
	}
	return 0;
}
