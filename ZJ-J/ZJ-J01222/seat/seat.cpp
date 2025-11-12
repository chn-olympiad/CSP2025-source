#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int o = n*m;
	int op;
	for(int i=1;i<=o;i++){
		cin>>a[i];
		op = a[1];
	}
	int x;
	sort(a+1,a+1+o,cmp);
	for(int i=1;i<=o;i++){
		if(a[i]==op){
		 	x=i;	
		}
	} 
	int lie;
	int dis;
	if(x%n==0){
		lie = x/n;	
		dis = 1;//Õû³ý 
	} else{
		lie = x/n+1;
		dis = 0;//ºóÒ»ÁÐ 
	}
	int hang;
	if(dis==1){
		hang = n;
	}else{
		if(lie%2==0){
			hang = n-(x-x/n*n)+1;
		}else{
			hang = x-x/n*n;
		}
	}
	cout<<lie<<" "<<hang<<endl;
	return 0;
}