#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
pair<string,string>a[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	int ans=0,pos1,pos2,len,l;
	string s1,s2;
	while(q--){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue; 
		} 
		l=s1.size();
		int ans=0;
		for(int i=1;i<=n;i++){
			pos1=s1.find(a[i].first),pos2=s2.find(a[i].second),len=a[i].first.size();
			if((int)pos1==-1||(int)pos2==-1||pos1!=pos2)continue;
			if(a[i].second!=s2.substr(pos2,len)||
				s1.substr(0,pos1)!=s2.substr(0,pos2)||
				s1.substr(pos1+len,l-pos1-len)!=s2.substr(pos2+len,l-pos2-len))
				continue;
				ans++;
			
		}
		cout<<ans<<'\n';
	}
	return 0;
}
