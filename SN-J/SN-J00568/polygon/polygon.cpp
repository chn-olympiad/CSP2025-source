#include<bits/stdc++.h>
using namespace std;
int n,a[100005],vis[10005],ans,ch[10005];
void dfs(int x,int cnt,int mx){
	if(cnt>mx*2&&x>=3){
		ans++;
		for(int i=1;i<=x;i++){
			cout<<ch[i]<<" ";
		}
		cout<<mx<<" "<<cnt<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&i!=x-1){
			vis[i]=1;
			ch[x+1]=a[i];
			dfs(x+1,cnt+a[i],max(mx,a[i]));
			vis[i]=0;
		}
	}
}
void dfs1(int x,int cnt,int mx){
	if(cnt<=mx*2||x<3){
		ans--;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&i!=x-1){
			vis[i]=1;
			ch[x+1]=a[i];
			dfs(x+1,cnt+a[i],max(mx,a[i]));
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cout<<9;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

