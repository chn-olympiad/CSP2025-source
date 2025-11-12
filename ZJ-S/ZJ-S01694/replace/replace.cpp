#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,pair<bool,string> >mp;
void replace(int i,int j,string a,string& b){
	for(int k=i;k<=j;k++)
		b[k]=a[k-i];
}
void solve1(){
	int ans=0;
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		for(int i=0;i<a.size();i++){
			for(int j=i;j<b.size();j++){
				string str="";
				for(int k=i;k<=j;k++){
					str.push_back(a[k]);
				}
				if(mp[str].first){
					string c=b;
					replace(i,j,mp[str].second,c);
					if(a==c)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		mp[a]={true,b};
	}
	if(n<=100){
		solve1();
	}
}
