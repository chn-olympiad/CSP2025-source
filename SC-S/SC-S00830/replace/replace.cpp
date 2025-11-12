#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=2e3+5;
struct XG{
	string x,y;
}s[N],ans[N];
int q,n;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i].x>>s[i].y;
	for(int i=1;i<=q;i++){
		int sum=0;
		cin>>ans[i].x>>ans[i].y;
		if(ans[i].x.size()!=ans[i].x.size()){
			cout<<0<<endl;
			continue;
		}
		int cnt=0;
		for(int j=0;j<ans[i].x.size();j++){
			if(ans[i].x[j]!=ans[i].y[j]) cnt++;
		}
		for(int l=1;l<=n;l++){
			if(s[l].x.size()>ans[i].x.size()) continue;
			if(s[l].x.size()<cnt) continue;
			for(int k=0;k<=ans[i].x.size()-s[l].x.size();k++){
				string x="",y="";
				for(int j=0;j<s[l].x.size();j++){
					x+=ans[i].x[j+k],y+=ans[i].y[j+k];
				}
				if(x==s[l].x&&y==s[l].y){
					sum++;
				} 
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}