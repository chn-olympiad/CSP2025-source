#include<bits/stdc++.h>

using namespace std;

int n,q;

int a[200005][3];

map<pair<int,int>,int>dis;

int main(){
	
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int c1=0,c2=0;
		int idx=0;
		while(idx+1<s1.size()&&s1[idx]=='a')idx++;
		c1=idx;
		idx=s1.size()-1;
		while(idx-1>=0&&s1[idx]=='a')idx--;
		c2=n-idx+1;
		
		int c3=0,c4=0;
		idx=0;
		while(idx+1<s2.size()&&s2[idx]=='a')idx++;
		c3=idx;
		idx=s2.size()-1;
		while(idx-1>=0&&s2[idx]=='a')idx--;
		c4=n-idx+1;
		
		a[i][1]=c3-c1;
		a[i][2]=c4-c2;
	}
	
	while(q--){
		
		string s1,s2;
		cin>>s1>>s2;
		
		int c1=0,c2=0;
		int idx=0;
		while(idx+1<s1.size()&&s1[idx]=='a')idx++;
		c1=idx;
		idx=s1.size()-1;
		while(idx-1>=0&&s1[idx]=='a')idx--;
		c2=n-idx+1;
		
		int c3=0,c4=0;
		idx=0;
		while(idx+1<s2.size()&&s2[idx]=='a')idx++;
		c3=idx;
		idx=s2.size()-1;
		while(idx-1>=0&&s2[idx]=='a')idx--;
		c4=n-idx+1;
		
		queue<pair<int,int> >q;
		q.push({c1,c2});
		dis[{c1,c2}]=1;
		
		while(q.size()){
			pair<int,int> x=q.front();
			q.pop();
			for(int i=1;i<=n;i++){
				int tx=x.first+a[i][1];
				int ty=x.second+a[i][2];
				if(dis[{tx,ty}]!=0)continue;
				dis[{tx,ty}]=dis[x]+1;
				q.push({tx,ty});
			}
		}
		
		cout<<dis[{c3,c4}]-1<<"\n";
	
	}
	
	return 0;
}