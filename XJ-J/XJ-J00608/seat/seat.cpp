#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m; // 行，列 
	cin>>n>>m;
	int people=n*m;
	int a[105];
	for(int i=1;i<=people;i++){
		cin>>a[i];
	}
	int chaxun=a[1],weizhi=0;
	sort(a+1,a+people+1,cmp);
	for(int i=1;i<=people;i++){
		if(a[i]==chaxun){
			weizhi=i;
			break;
		}
	}
	double yunsuan=weizhi;
	int hang=weizhi%n; //2
	if(weizhi%n==0){
		hang=n;
	}
	int lie=ceil(yunsuan/m); //1
	bool shangxia=lie%2;
	cout<<lie<<" ";
	if(shangxia){ //1 -> 往下 
		cout<<hang;
	}
	else if(!shangxia){ // 0->往上 
		cout<< n-hang+1;
	}
	return 0;
}
