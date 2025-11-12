#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a1,ID;//小R的分数a1和ID 
struct node{
	long long a;//总人的分 
	long long id;//排序后的名次 
}b[101];
long long nm;
bool cmp(node a,node b){
	return a.a>b.a;
}
long long x,y;//位置的坐标，x行 y列 
long long ans[101][101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;	
	nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>b[i].a;
	}
	a1=b[1].a;
	sort(b+1,b+1+nm,cmp);
	for(int i=1;i<=nm;i++){
		b[i].id=i;
	}
//	for(int i=1;i<=nm;i++){
//		cout<<"成绩 = "<<b[i].a<<"id = "<<b[i].id<<endl;
//	}
	for(int i=1;i<=nm;i++){
		if(b[i].a==a1){
			ID=b[i].id;
		}
	}
	ans[1][1]=1;
	//cout<<"a1 = "<<a1<<"ID = "<<ID;
	for(int i=2;i<=n;i++){//第一列 
		ans[i][1]=ans[i-1][1]+1;	
	}
	for(int i=2;i<=m;i++){//第一行 
		if(i%2==0){
			ans[1][i]=ans[1][i-1]+(n+m-1);
		}else if(i%2==1){
			ans[1][i]=ans[1][i-1]+1;
		} 
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			ans[i][j]=abs(ans[i-1][j]-ans[i][j-1])+ans[i-1][j-1];
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==ID){
			cout<<i<<" "<<j;
			return 0;
			}
		} 
	}	 
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/  


