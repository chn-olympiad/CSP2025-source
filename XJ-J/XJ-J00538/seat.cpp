#include<bits/stdc++.h>
using namespace std;
int cj[110];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
	}
	int a=cj[1],b;
	sort(cj+1,cj+cj[n*m]+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(cj[i]==a) b=i;
	}
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=m*n;j++){
			int x,y;
			if(i>n) x++;
			if(j>m) y++;
		}
	}
	
	return 0;
}
