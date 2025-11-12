#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=25;
int a[N][N];
int b[N*N],top=1; 
int n,m;
void dfs(int q,int p,int r){
	if(b[top]==r){
		cout<<p<<" "<<q;
		return ;
	}
//	-99- 100 97 98
//	100 99 98 97
//	  1   2
//	1 100 97
//	2 99  98
//	2 
//	1
	a[q][p]=b[top];
	top++;
	if(p%2){//在单数列，要往下走 
		if(q<n){//下面有空位  
			dfs(q+1,p,r);//向下走 
		}else{//下面没有空位，要往右走  
			dfs(q,p+1,r);
		}
	}else{//在双数列，要往上走 
		if(q>1){//上面有空位  
			dfs(q-1,p,r);//向上走 
		}else{//上面没有空位，要往右走  
			dfs(q,p+1,r);
		}
	}
	return ;
}
bool cmp(int q,int p){
	return q>p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int r=b[1];
	sort(b+1,b+1+n*m,cmp);
	dfs(1,1,r);
	return 0;
}
