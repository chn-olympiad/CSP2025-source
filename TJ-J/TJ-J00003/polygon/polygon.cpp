#include<bits/stdc++.h>
using namespace std;
int sum=0;int visited[5010];int a[5010];int n;
map<vector<int>,bool> mp;
void dfs(int c,int len,int Max,vector<int> vec){
	sort(vec.begin(),vec.end());
	if(c>=n){
		if(len>Max*2 && !mp.count(vec)){
			sum++;sum=sum%998244353;
			mp[vec]=1;
		}
		return ;
	}
	if(c>=3 && len>Max*2 && !mp.count(vec)){
		sum++;sum=sum%998244353;
		mp[vec]=1;
	}
	for(int i=0;i<n;i++){
		if(!visited[i]){
			visited[i]=1;
			vec.push_back(i);
			dfs(c+1,len+a[i],max(Max,a[i]),vec);
			vec.pop_back();
			visited[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	vector<int> tmp;
	dfs(0,0,0,tmp);
	printf("%d\n",sum%998244353);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
