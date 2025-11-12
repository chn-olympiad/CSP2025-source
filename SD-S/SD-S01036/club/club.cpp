#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1e5+10;
vector<int> v[maxn];
int n;
int ans,num;
int ts[4];
int cmp(vector<int> a,vector<int> b){
	return a[1]>b[1];
}
int dfs(int cur){
	if(cur==n){
		return ans=max(ans,num);
	}
	for(int i=0;i<3;i++){
		if(ts[i]){
			ts[i]--;
			num+=v[cur][i];
			dfs(cur+1);
			num-=v[cur][i];
			ts[i]++;
		}
		else continue;	
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=0;i<3;i++){
			ts[i]=n/2;
		}
		for(int i=0;i<n;i++){
			v[i].clear();
			for(int j=0;j<3;j++){
				int temp;
				cin>>temp;
				v[i].push_back(temp);
			}
		}
		if(n>10){
			sort(v,v+n,cmp); 
			for(int i=0;i<n/2;i++){
				ans+=v[i][1];
			}
		}
		if(n<=10){
			dfs(0); 
		}
		cout<<ans;
		if(T)cout<<'\n';
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

