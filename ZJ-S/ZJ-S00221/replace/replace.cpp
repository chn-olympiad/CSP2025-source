#include<bits/stdc++.h>
using namespace std;int n,m,cnt;
vector<pair<string,string>>ss;
map<string,string>a;
vector<string>ys;
void bl(int id){
	for(int be=0;be<ss[id].first.size();be++)
		for(int en=be;en<ss[id].first.size();en++)
			for(int choose=0;choose<n;choose++)
				if(ss[id].first.substr(be,en)==a[ys[choose]]){
					ss.push_back({ss[id].first.replace(be,en-be,a[ys[choose]]),ss[id].second});
					if(ss[id].first.replace(be,en-be,a[ys[choose]])==ss[id].second)cnt++;
				}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string x,y;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>x>>y,a[x]=y,ys.push_back(x);
	for(int i=0;i<m;i++){
		cin>>x>>y;ss.push_back({x,y});
	}
	for(int id=0;id<m;id++)bl(id);
	cout<<cnt;
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