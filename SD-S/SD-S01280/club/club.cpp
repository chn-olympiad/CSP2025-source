#include<bits/stdc++.h>
#define m(a) memset(a,0,sizeof a)
using namespace std;
const int N=1e5+10;
int a1[N][3];
int Dfs(int k,int n,int a,int b,int c){
	int ansa=0,ansb=0,ansc=0;
	if(a<n/2){
		ansa=a1[k][1];
		ansa+=Dfs(k+1,n,a+1,b,c);
	}if(b<n/2){
		ansb=a1[k][2];
		ansb+=Dfs(k+1,n,a,b+1,c);
	}if(c<n/2){
		ansc=a1[k][3];
		ansc+=Dfs(k+1,n,a,b,c+1);
	}
	return max(ansa,max(ansb,ansc));
}
void work(){
	m(a1);
	int n;
	int a=0,b=0,c=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a1[i][1]>>a1[i][2]>>a1[i][3];
	}
	cout<<Dfs(1,n,a,b,c)<<'\n';
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		work();
	}
	return 0;
}

