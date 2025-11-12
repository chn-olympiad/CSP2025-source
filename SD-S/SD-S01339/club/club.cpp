#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005][3];
long long max_ans=0;
void dfs(long long score,int man,int num_x,int num_y,int num_z){
	if(man>n){
		if(score>max_ans){
			max_ans=score;
		}
		return ;
	}
	int b[3]={0,1,2};
	for(int i=0;i<=2;i++){
		for(int j=0;j<=1-i;j++){
			if(a[man][b[j]]<a[man][b[j+1]]){
				int cmp=b[j];
				b[j]=b[j+1];
				b[j+1]=cmp;
			}
		}
	}
	for(int i=0;i<=1;i++){
		if(b[i]==0&&num_x<=n/2-1){
			dfs(score+a[man][0],man+1,num_x+1,num_y,num_z);
		}else if(b[i]==1&&num_y<=n/2-1){
			dfs(score+a[man][1],man+1,num_x,num_y+1,num_z);
		}else if(b[i]==2&&num_z<=n/2-1){
			dfs(score+a[man][2],man+1,num_x,num_y,num_z+1);
		} 
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		max_ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		}
		dfs(0,1,0,0,0);
		cout<<max_ans<<endl;
	}
	return 0;
}

