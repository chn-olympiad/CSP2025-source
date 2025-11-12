#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200010],x,y,x2;
unordered_map<string,string> a;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	//测试点1~2
	//目标：10分
	cin>>n>>q;
	//if(n<=100){
		for(int i=0;i<n;i++){
			cin>>s[i]>>x;
			a[s[i]]=x;
		}
		
		while(q--){
			ans=0;
			cin>>x>>y;
			for(int i=0;i<n;i++){
				x2=x;
				for(int j=0;j+s[i].size()<=x.size();j++){
					if(x2.substr(j,s[i].size())!=s[i])continue;
					x2.replace(j,s[i].size(),a[s[i]]);
					//cout<<x<<" "<<x2<<'\n';
					if(x2==y)ans++;
					x2=x;
				}
			}
			cout<<ans<<'\n';
		}
	/*}else{
		cout<<"666我不会啊"; 
	}*/
	return 0;
}