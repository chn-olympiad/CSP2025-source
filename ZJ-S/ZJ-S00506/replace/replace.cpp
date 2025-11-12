#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
ll n,q;
string s1[maxn],s2[maxn],t1,t2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		int cnt=t1.size(),sum=0;
		if(cnt<=100){
			bool flag=1;
			string a="",b="";
			for(int i=0;i<cnt;i++){
				if(t1[i]!=t2[i]){
					a=a+t1[i];
					b=b+t2[i];
				}
				else{
					if(sum!=0){
						flag=0;
						break;
					}
					if(a==""&&b=="") continue;
					bool vis=0;
					for(int j=1;j<=n;j++){
						if(s1[j]==a&&s2[j]==b){
							a="",b="";
							sum++;
							vis=1;
							break;
						}
					}
					if(vis==0){
						flag=0;
						break;
					}	
				}
				if(flag==0) break;
			}
			if(a!="") flag=0;
			if(flag==0){
				cout<<0<<endl;
				continue;
			}
			ll ans=0;
			for(int i=0;i<cnt;i++){
				for(int j=1;j<=n;j++){
					a="",b="";
					for(int k=i;k<i+s1[j].size();k++){
						a=a+t1[k];
						b=b+t2[k];
					}
					if(a==s1[j]&&b==s2[j]) ans++;
				}
			}
			cout<<ans<<endl;			
		}
		else cout<<0<<endl;
	}
	return 0;
}
