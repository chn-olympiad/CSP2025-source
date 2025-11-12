#include <bits/stdc++.h>
using namespace std;
const int N=5e6+10,L=5e6+10;
int n,q;
string s[N][3];
string t1,t2;
int Next[L];
int Next2[L];
void get_next(int d){
	int p=0;
	Next[1]=0;
	for(int i=1;i<s[d][1].size();i++){
		while(p&&s[d][1][i]!=s[d][1][p]) p=Next[p];
		if(s[d][1][i]==s[d][1][p]){
			Next[i+1]=p+1;
			p++;
		}
	}
}
void get_next2(int d){
	int p=0;
	Next2[1]=0;
	for(int i=1;i<s[d][2].size();i++){
		while(p&&s[d][2][i]!=s[d][2][p]) p=Next2[p];
		if(s[d][2][i]==s[d][2][p]){
			Next2[i+1]=p+1;
			p++;
		}
	}
}
bool vis[N];
bool viss[N];
void KMP(int d){	//t1长，s[d][1]短 
	int p=0;
	for(int i=0;i<t1.size();i++){
//		cout<<i<<' ';
		while(p&&s[d][1][p]!=t1[i]) p=Next[p];
		if(s[d][1][p]==t1[i]) p++;
//			cout<<p<<' ';
		if(p==s[d][1].size()){
			vis[i-s[d][1].size()+1]=true;
			p=Next[p];
		}
	}
//	cout<<'\n';
}
void KMP2(int d){	//t2长，s[d][2]短 
	int p=0;
	for(int i=0;i<t2.size();i++){
		while(p&&s[d][2][p]!=t2[i]) p=Next2[p];
		if(s[d][2][p]==t2[i]) p++;
//		cout<<p<<' ';
		if(p==s[d][2].size()){
			viss[i-s[d][2].size()+1]=true;
			p=Next2[p];
		}
	}
//	cout<<'\n';
}
bool vis1[N],vis2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cin>>t1>>t2;	//找到s【i】【1】在t1中的匹配
		int ans=0; 
		for(int i=1;i<=n;i++){
			for(int j=0;j<=max(s[i][1].size(),t1.size())+2;j++) Next[j]=Next2[j]=0,vis[j]=vis1[j]=vis2[j]=viss[j]=false;
//			for(int j=0;j<=t1.size()+2;j++) vis[j]=vis1[j]=vis2[j]=viss[j]=false;	//记录当前为起始点是否匹配 
			if(t1.size()<s[i][1].size()){
				continue;
			} 
			get_next(i);	//找出s【i】【1】的Next 
			KMP(i);
//			for(int j=0;j<t1.size();j++) cout<<vis[j]<<' ';
//			cout<<'\n';
			//t1长，s[d][1]短
			
			//t2长，s[d][2]短
			get_next2(i);
			KMP2(i); 
			for(int j=0;j<t1.size();j++){
				if(t1[j]==t2[j]) vis1[j]=true;
				else break;
			}
//			vis2[t1.size()]=true;
			for(int j=t1.size()-1;j>=0;j--){
				if(t1[j]==t2[j]) vis2[j]=true;
				else break;
			}
			for(int j=0;j<t1.size()-s[i][1].size()+1;j++){
				if(j==0&&(j==t1.size()-s[i][1].size()||vis2[j+s[i][1].size()])&&vis[j]&&viss[j]) ans++;
				if(j==0) continue;
				if((vis1[j-1]==true)&&(j==t1.size()-s[i][1].size()||vis2[j+s[i][1].size()])&&vis[j]&&viss[j]) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

