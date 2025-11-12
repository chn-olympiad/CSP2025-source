#include<iostream>
#include<algorithm>
using namespace std;
int n,q;
struct node{
	string a;
	string b;
}t[200001];
int len[200001];
bool vis[5000001];
int cnt=0;
bool cmp(node qq,node ww){
	return qq.a.length()<ww.b.length();
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>t[i].a>>t[i].b;
		int x=t[i].a.length();
		len[i]=x;
	}
	sort(len+1,len+n+1);
	sort(t+1,t+n+1,cmp);
	while(q--){
		string q,w;
		cin>>q>>w;
		int ans=0;
		for(int i=0;i<q.length();i++){
			for(int j=1;j<=n;j++){
				if(i+len[j]-1>=q.length()) continue;
				string ww="",qq="";
				for(int k=i;k<i+len[j];k++) ww+=w[k];
				for(int k=i;k<i+len[j];k++) qq+=q[k];
				string ss="";
				for(int k=0;k<i;k++) ss+=q[k];
				ss+=ww;
				for(int k=i+len[j];k<q.length();k++) ss+=q[k];
				if(ww==t[j].b&&qq==t[j].a&&ss==w) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
