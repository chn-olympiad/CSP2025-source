#include<bits/stdc++.h>
using namespace std;
struct node{
	int num,id;
}a[1001];
int n,m;
bool cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i].id<<" "<<a[i].num<<'\n';
//	}
	int i=1,j=1,cnt=1,flag=1;//1 down 2 up
	while(a[cnt].id!=1){
		if(flag==1) i++;
		else i--;
		if(i==n+1&&flag==1){
			flag=2;
			j++;
			i=n;
		}
		else if(i==0&&flag==2){
			flag=1;
			j++;
			i=1;
		}
		cnt++;
	}
	cout<<j<<" "<<i<<'\n';
	return 0;
}