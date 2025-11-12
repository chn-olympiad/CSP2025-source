#include<bits/stdc++.h>
using namespace std;
int const N=3*1e5;
map<string,int>name;
struct e{
	int v,next;
}edge[N];
int n,q,head[N],total=0,nw=0;
void init(int u,int v){
	edge[++total].v=v;
	edge[total].next=head[u];
	head[u]=total;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++){
		string temp1,temp2;
		cin>>temp1>>temp2;
		int u,v;
		if(!name[temp1])name[temp1]=++nw;
		if(!name[temp2])name[temp2]=++nw;
		u=name[temp1];
		v=name[temp2];
		init(u,v);
	}
	while(q--){
		string q1,q2;
		cin>>q1>>q2;
		if(q1.length()!=q2.length()){
			cout<<0<<endl;
			continue;
		}
		int len=q1.length();
		vector<string>pre,final;
		pre.push_back("");
		final.push_back("");
		string temp1="",temp2="";
		for(int i=0;i<len;i++){
			temp1+=q1[i];
			temp2+=q2[i];
			if(temp1==temp2)
				pre.push_back(temp1);
			else
				break;
		}
		temp1="",temp2="";
		for(int i=len-1;i>=0;i--){
			temp1=q1[i]+temp1;
			temp2=q2[i]+temp2;
			if(temp1==temp2)
				final.push_back(temp2);
			else break;
		}
		long long ans=0;
		for(int i=0;i<pre.size();i++){
			int yl,yr;
			yl=pre[i].size();
			for(int j=0;j<final.size();j++){
				yr=len-final[j].size();
				if(yl>=yr)
					continue;
				string f1=q1.substr(yl,(yr-yl));
				string f2=q2.substr(yl,(yr-yl));
				if(!name[f1]||!name[f2])
					continue;
				for(int k=head[name[f1]];k!=-1;k=edge[k].next){
					if(edge[k].v==name[f2]){
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<endl; 
	}
	return 0;
} 
