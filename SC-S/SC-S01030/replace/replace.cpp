#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10,M=2e5+10;
int n,q;
struct tree{
	int a[26];
}t1[N],t2[N];
int tot1,tot2;
vector<int>us1[N],us2[N];
int dep1[N],dep2[N];
void build1(string s,int id){
	int now=0;
	for(int i=0;i<s.size();i++){
		if(t1[now].a[s[i]-'a']){
			now=t1[now].a[s[i]-'a'];
		}
		else{
			t1[now].a[s[i]-'a']=++tot1;
			now=tot1;
		}
		dep1[now]=i+1;
	}
	us1[now].push_back(id);
}
void build2(string s,int id){
	int now=0;
	for(int i=0;i<s.size();i++){
		if(t2[now].a[s[i]-'a']){
			now=t2[now].a[s[i]-'a'];
		}
		else{
			t2[now].a[s[i]-'a']=++tot2;
			now=tot2;
		}
		dep2[now]=i+1;
	}
	us2[now].push_back(id);
}
int shi1[N],shi2[N];
void jian1(){
	queue<int>q;
	for(int i=0;i<=25;i++){
		if(t1[0].a[i]){
			q.push(t1[0].a[i]);
			shi1[t1[0].a[i]]=0;
		}
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<=25;i++){
			int y=t1[x].a[i];
			if(y){
				int z=x;
				while(z&&!t1[shi1[z]].a[i]){
					z=shi1[z];
				}
				shi1[y]=t1[shi1[z]].a[i];
				q.push(y);
			}
		}
	}
}
void jian2(){
	queue<int>q;
	for(int i=0;i<=25;i++){
		if(t2[0].a[i]){
			q.push(t2[0].a[i]);
			shi2[t2[0].a[i]]=0;
		}
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<=25;i++){
			int y=t2[x].a[i];
			if(y){
				int z=x;
				while(z&&!t2[shi2[z]].a[i]){
					z=shi2[z];
				}
				shi2[y]=t2[shi2[z]].a[i];
				q.push(y);
			}
		}
	}
}
int vis[M],len[M];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		build1(s,i);
		cin>>s;
		build2(s,i);
		len[i]=s.size();
	}
	jian1();jian2();
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0<<'\n';
			continue;
		}
		int L,R,l=s1.size();
		for(int i=0;i<l;i++){
			if(s1[i]!=s2[i]){
				L=i+1;
				break;
			}
		}
		for(int i=l-1;i>=0;i--){
			if(s1[i]!=s2[i]){
				R=i+1;
				break;
			}
		}
		int now1=0,now2=0,ans=0;
		for(int i=0;i<l;i++){
			while(now1&&!t1[now1].a[s1[i]-'a'])now1=shi1[now1];
			while(now2&&!t2[now2].a[s2[i]-'a'])now2=shi2[now2];
			if(t1[now1].a[s1[i]-'a']){
				now1=t1[now1].a[s1[i]-'a'];
			}
			if(t2[now2].a[s2[i]-'a']){
				now2=t2[now2].a[s2[i]-'a'];
			}
			if(i+1>=R&&i+2-min(dep1[now1],dep2[now2])<=L){
				int S1=now1,S2=now2;
				while(S1&&i+2-dep1[S1]<=L){
					for(int j=0;j<us1[S1].size();j++){
						vis[us1[S1][j]]=1;
					}
					S1=shi1[S1];
				}
				while(S2&&i+2-dep2[S2]<=L){
					for(int j=0;j<us2[S2].size();j++){
						if(vis[us2[S2][j]]){
							ans++;
						}
					}
					S2=shi2[S2];
				}
				S1=now1;
				while(S1&&i+2-dep1[S1]<=L){
					for(int j=0;j<us1[S1].size();j++){
						vis[us1[S1][j]]=0;
					}
					S1=shi1[S1];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
15:50建两颗失配树，两边同时跑。
666，空间是2G，应该不会炸。
16:17不会开无线栈，坠机了。
16:44写完开调。
16:49样例三错但没T，样例四T但没错。
17:08可过样例三。
17:24卡到1.4s实在卡不动了。
80pts。
*/