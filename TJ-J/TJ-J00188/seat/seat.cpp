#include<bits/stdc++.h>
using namespace std;
int n,m,mx=0,my=0,nx=0,ny=1;
int num[15][15];
struct students{
	int score;
	int p;
}stu[105];
void f(int pl){
	for (int x=1;x<=n;x++){
		for (int y=1;y<=m;y++){
			if(num[x][y]==pl){
				cout<<y<<' '<<x;
				return ;
			}
		}
	}
}
bool cmp(students a,students b){
	return a.score>b.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int x=1;x<=n;x++){
		num[x][1]=x;
	}
	for (int x=1;x<=n;x++){
		for (int y=2;y<=m;y++){
			if(y%2==0){
				num[x][y]=num[x][y-1]+n+n-x-x+1;
			}
			if(y%2!=0){
				num[x][y]=num[x][y-1]+x+x-1;
			}
		}
	}
	for (int x=1;x<=n*m;x++){
		cin>>stu[x].score;
		stu[x].p=x;
	}
	sort(stu+1,stu+n*m+1,cmp);
	for (int x=1;x<=n*m;x++){
		if(stu[x].p==1){
			f(x);
			return 0;
		}
	}
	return 0;
}
