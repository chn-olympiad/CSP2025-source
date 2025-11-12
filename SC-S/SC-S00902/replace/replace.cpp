#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,q,ch[N][26],ch1[N][26],tot,tot1,ans,bg[N],l[N],ccc[N];
string s[N][2],t[2];
vector<int> tmp[N],tmp1[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(q==1){
		for(int i=1;i<=n;i++){
			cin>>s[i][0]>>s[i][1];
			int k=s[i][0].length();
			int u=0;
			for(int j=0;j<k;j++){
				if(!ch[u][s[i][0][j]-'a']) ch[u][s[i][0][j]-'a']=++tot;
				u=ch[u][s[i][0][j]-'a'];
			}
			tmp[u].emplace_back(i);
			u=0;
			for(int j=0;j<k;j++){
				if(!ch1[u][s[i][1][j]-'a']) ch1[u][s[i][1][j]-'a']=++tot1;
				u=ch1[u][s[i][1][j]-'a'];
			}
			tmp1[u].emplace_back(i);
		}
		cin>>t[0]>>t[1];
		int k=t[0].length();
		if(t[0].length()!=t[1].length()){
			printf("0\n");
			return 0;
		}
		int bg1=-1,ed=-1;
		for(int j=0;j<k;j++){
			if(bg1==-1&&t[0][j]!=t[1][j]) bg1=j;
			if(t[0][j]!=t[1][j]) ed=j;
		}
		for(int i=0;i<=bg1;i++){
			int u=0;
			for(int j=i;j<k;j++){
				if(ch[u][t[0][j]-'a']==0){
					break; 
				}
				u=ch[u][t[0][j]-'a'];
				if(j<ed) continue;
				for(int kk:tmp[u]) ccc[kk]++;
			}
//			cout<<i<<":"<<endl;
			u=0;
			for(int j=i;j<k;j++){
				if(ch1[u][t[1][j]-'a']==0){
					break; 
				}
				u=ch1[u][t[1][j]-'a'];
				if(j<ed) continue;
				for(int kk:tmp1[u]) if(ccc[kk]) /*cout<<kk<<endl,*/ans++;
			}
		}
		printf("%d",ans);
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		l[i]=s[i][0].length();
		bg[i]=-1; int ed=-1;
		for(int j=0;j<=l[i];j++){
			if(bg[i]==-1&&s[i][0][j]!=s[i][1][j]) bg[i]=j;
			if(s[i][0][j]!=s[i][1][j]) ed=j;
		}
		int len=ed-bg[i]+1;
		string ss1=s[i][0].substr(bg[i],len);
		s[i][1]=s[i][1].substr(bg[i],len);
		int u=0;
		for(int j=0;j<len;j++){
			if(!ch[u][ss1[j]-'a']) ch[u][ss1[j]-'a']=++tot;
			u=ch[u][ss1[j]-'a'];
		}
		tmp[u].emplace_back(i);
//		cout<<bg[i]<<" "<<ed<<endl;
	}
	while(q--){
		cin>>t[0]>>t[1];
		int k=t[0].length();
		if(t[0].length()!=t[1].length()){
			printf("0\n");
			continue;
		}
		int bg1=-1,ed=-1;
		for(int j=0;j<k;j++){
			if(bg1==-1&&t[0][j]!=t[1][j]) bg1=j;
			if(t[0][j]!=t[1][j]) ed=j;
		}
		int len=ed-bg1+1;
//		cout<<bg1<<" "<<ed<<endl;
		string t1=t[0].substr(bg1,len);
		int u=0,can=1;
		for(int j=0;j<len;j++){
			if(!ch[u][t1[j]-'a']){
				printf("0\n"); can=0;
				break;
			}
			u=ch[u][t1[j]-'a'];
		}
		if(!can){
			continue;
		}
		for(int i:tmp[u]){
//			cout<<i<<endl;
			if(s[i][1]==t[1].substr(bg1,len)){
//				cout<<"!"<<i<<endl;
				if(t[0].substr(bg1-bg[i],l[i])==s[i][0]) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}