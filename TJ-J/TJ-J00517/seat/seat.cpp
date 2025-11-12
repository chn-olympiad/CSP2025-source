#include<bits/stdc++.h>
using namespace std;
long long n,m,p;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	p=n*m;
	for(int i=1;i<=p;i++){
		cin>>a[i];
	}
	int cnt=a[1],num=0;
	sort(a+1,a+p+1,cmp);
	for(int i=1;i<=p;i++){
		if(a[i]==cnt){
			num+=i;
			break;
		}
	}
	cout<<num/3+1<<' '<<num%3;
	return 0;	
}
