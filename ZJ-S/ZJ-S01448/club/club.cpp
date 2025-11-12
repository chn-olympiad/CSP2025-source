#include<bits/stdc++.h>
using namespace std;
int t;
long long mxans=-1;
int me[100002][3];
int n;
int maxx=-1;
void dfs(int n1,int n2,int n3,long long ans,int now){
	if(now == n-1){
		if(mxans<ans){
			mxans=ans;
		}
	}
	else if(ans+maxx*(n-1-now) > mxans){
		if((n1+1)<=(n/2)){
			dfs(n1+1,n2,n3,ans+me[now][0],now+1);
		}
		if((n2+1)<=(n/2)){
			dfs(n1,n2+1,n3,ans+me[now][1],now+1);
		}
		if((n3+1)<=(n/2)){
			dfs(n1,n2,n3+1,ans+me[now][2],now+1);
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		mxans=-1;
		for(int j=0;j<n;j++){
			cin>>me[j][0]>>me[j][1]>>me[j][2];
			if(me[j][0]>maxx){
				maxx=me[j][0];
			}
			if(me[j][1]>maxx){
				maxx=me[j][1];
			}
			if(me[j][2]>maxx){
				maxx=me[j][2];
			}
		}
		dfs(0,0,0,0,0);
		if(i!=t-1){
			cout<<mxans<<endl;
		}
		else{
			cout<<mxans;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
