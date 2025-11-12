#include<bits/stdc++.h>
using namespace std;
int n;
struct mem{
	int like[4];
}stu[100005];
bool vis[100005];
int sum,tim[5];
void dfs(int pos,int sat){
	for(int i=1;i<=3;i++){
			if(tim[i]>n/2) return;
		}
	if(pos==n+1){
		sum=max(sum,sat);
		return;
	}
	for(int i=1;i<=3;i++){
		tim[i]++;
		dfs(pos+1,sat+stu[pos].like[i]);
		tim[i]--;
		}
		}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
   int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int q=1;q<=n;q++){
			for(int m=1;m<=3;m++){
				cin>>stu[q].like[m];
			}
	}
	sum=0;
	for(int i=1;i<=3;i++) tim[i]=0;
	        dfs(1,0);
			cout<<sum<<endl;
	}
		fclose(stdin);
		fclose(stdout);
	return 0;
}
