#include<bits/stdc++.h>
#define int long long
#define base 13331
using namespace std;
long long n,T;
string f,g;
struct node{
	string a,b;
	int cha=0;
}s[200005];
vector<int>q[5000005];
namespace Subtask1{
	signed main(){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<s[i].a.size();j++){
				int len=s[i].a.size(),vis=0;
				for(int k=0;k<=k+len-1;k++){
					if(s[i].a[k]!=f[k]){
						vis=1;
					}
				}
				if(!vis){
					for(int k=0;k<=k+len-1;k++){
						f[k]=s[i].a[k];
					}
					if(f==g){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}
};
namespace Subtask2{
	inline bool check(){
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<s[i].a.size();j++){
				if(s[i].a[j]=='b'){
					cnt1++;
				}
				if(s[i].b[j]=='b'){
					cnt2++;
				}
				if(s[i].a[j]!='a'&&s[i].a[j]!='b'){
					return 0;
				}
				if(s[i].b[j]!='a'&&s[i].b[j]!='b'){
					return 0;
				}
			}
		}
		if(cnt1==cnt2&&cnt1==1){
			return 1;
		}
		else{
			return 0;
		}
	}
	signed main(){
		while(T--){
			int cntt=0;
			cin>>f>>g;
			int idi=0,idj=0;
			for(int i=0;i<f.size();i++){
				if(f[i]=='b'){
					idi=i;
				}
				if(g[i]=='b'){
					idj=i;
				}
			}
			for(int i=1;i<=n;i++){
				int ida,idb;
				for(int j=0;j<s[i].a.size();j++){
					if(f[i]=='b'){
						ida=i;
					}
					if(g[i]=='b'){
						idb=i;
					}
				}
				s[i].cha=ida-idb;
				if(s[i].cha==idi-idj){
					cntt++;
				}
			}
			cout<<cntt<<endl;
		}
		return 0;
	}
};
bool vis=0;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	if(T==1){
		cin>>f>>g;
		cout<<0<<endl;
		return 0;
	}
	if(Subtask2::check()){
		vis=1;
	}
	while(T--){
		cin>>f>>g;
		if(f.size()!=g.size()){
			cout<<0<<'\n';
			continue;
		}
		if(vis==1){
			Subtask2::main();
			continue;
		}
		Subtask1::main();
	}
	return 0;
}
/*
万恶之源啊……我不做这题我是不是就进NOIP了呢？
为什么为什么为什么
为什么我会认为我自己会字符串？？？
为什么我认为我可以做出这题正解？
为什么我见过类似的题却直接跳过了？
为什么我在这题卡了2.5h？？？
哪有那么多为什么啊我就是菜啊
今年回不了gxyzOI了，明年不知道会不会再打
就是菜。 
*/
