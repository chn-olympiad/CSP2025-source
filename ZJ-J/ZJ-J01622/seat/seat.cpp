#include<bits/stdc++.h>
using namespace std;

const int maxn=15;
int n,m;
int v[maxn*maxn];
bool cmp(int x,int y){
	return x>y;
}
int sum,num;
int a,b;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>v[i];
	}
	sum=v[1];
	sort(v+1,v+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(v[i]==sum)num=i;
	}
	a=(num-1)/n+1;
	b=(num-1)%n;
	if(a%2==1){
		b++;
	}else{
		b=n-b;
	}
	cout<<a<<' '<<b;
	return 0;
}
