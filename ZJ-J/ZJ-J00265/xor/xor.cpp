#include<iostream>
using namespace std;
int n;
int k;
int a[500005];
int ans;
bool flag=true;
void dfs(int num,int value,int cnt){
	if(num>n){
		int c=cnt;
		if(value==k)c++;
		if(c>ans)ans=c;
		return;
	}
	if(value==k){
		dfs(num+1,a[num],cnt+1);
		dfs(num+1,-1,cnt+1);
	}else{
		dfs(num+1,value==-1?a[num]:value xor a[num],cnt);
		dfs(num+1,-1,cnt);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1)flag=false;
	}
	if(k==0){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			else if(a[i]==a[i+1])ans++,i++;
		}
		cout<<ans;
	}else if(k==1&&flag){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		cout<<ans;
	}else{
		dfs(1,-1,0);
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// expect 30 pts
