#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,ans;
string s[N],s2[N];
bool find(string f,string t,string a,string b){
	for(int i=0;i<f.size()-a.size();i++){
		int j=i,k=0;
		while(a[k]==f[j]){
			if(k==a.size())break;
			j++;
			k++;
		}
		string x,y,z,ss;
		if(k==a.size()){
			for(int v=0;v<i;v++)x=x+f[v];
			for(int v=0;v<b.size();v++)y=y+b[v];
			for(int v=i+b.size();v<f.size()-a.size()+b.size();v++)z=z+f[v];
		}
		ss=x+y+z;
		bool aa=1;
		int bb=0;
		while(ss[bb]){
			if(ss[bb]!=t[bb]){
				aa=0;
				break;
			}
			bb++;
		}
		if(aa)return 1;
		else return 0;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		cin>>s2[i];
	}
	for(int i=1;i<=m;i++){
		ans=0;
		string f,t;
		cin>>f;
		cin>>t;
		for(int i=1;i<=n;i++){
			if(find(f,t,s[i],s2[i]))ans++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
