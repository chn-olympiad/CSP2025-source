#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cmath>
using namespace std;
int x,y,light[10005];
dfs(int xx,int yy,int op){
	op--;
	if(op==0){
		cout<<yy<<" "<<xx;
		return 0;
	}
	if(yy%2==1&&xx!=x){
		dfs(xx+1,yy,op);
	}else if(yy%2==0&&xx!=1){
		dfs(xx-1,yy,op);
	}else if(xx==x||xx==1){
		dfs(xx,yy+1,op);
	}

}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	for(int i=1;i<=x*y;i++){
		cin>>light[i];
	}
	int ans=light[1],op;
	sort(light+1,light+x*y+1);
	for(int i=x*y;i>=1;i--){
		op=i;
		if(ans==light[i]){
			break;
		}
	}
	dfs(1,1,x*y-op+1);
	return 0;
}
