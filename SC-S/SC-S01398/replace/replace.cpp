#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,q;
struct ex{
	string a,b;
}e[maxn];
void read(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>e[i].a>>e[i].b;
	}
	for(int i=0;i<q;i++){
		string tem,temp;
		cin>>tem>>temp;
		if(tem.size()!=temp.size()){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=0;i<n;i++){
			if(e[i].a.size()>tem.size())continue;
			auto z=tem.find(e[i].a,0);
			while(1){
				if(z==string::npos)break;
				string t=tem;
				tem.replace(z,e[i].a.size(),e[i].b);
				if(tem==temp)ans++;
				tem=t;
				z=tem.find(e[i].a,z+1);
			}
		}
		cout<<ans<<"\n";
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	read();
	
	return 0;
}