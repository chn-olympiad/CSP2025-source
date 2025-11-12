#include<bits/stdc++.h> 
using namespace std;
long long n,m,c,s,i,j,k,p,q;
int a1[200],a2[50][50];
bool t[50][50];
int dfs(int x,int y){
	if(s==c){
		p=x;
		q=y;
	}else if(a2[x][y+1]==0&&t[x][y+1]==false&&y+1<m&&x<n&&y+1>=0&&x>=0){
		t[x][y]=true;
		s++;
		dfs(x,y+1);
	}else if(a2[x][y-1]==0&&t[x][y-1]==false&&y-1<m&&x<n&&y-1>=0&&x>=0){
		t[x][y]=true;
		s++;
		dfs(x,y-1);
	}else if(a2[x+1][y]==0&&t[x+1][y]==false&&y<m&&x+1<n&&y>=0&&x+1>=0){
		t[x][y]=true;
		s++;
		dfs(x+1,y);
	}
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(i=0;i<n*m;i++){
		cin>>a1[i];
	}
	c=a1[0];
	sort(a1,a1+(n*m));
	for(i=0;i<n*m;i++){
		if(a1[i]==c){
			c=i;
			c=n*m-c-1;
			break;
		}
	}
	
	dfs(0,0);
	cout<<p+1<<' '<<q+1;
	return 0;
}
