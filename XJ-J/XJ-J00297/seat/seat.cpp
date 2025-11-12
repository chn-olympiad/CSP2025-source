#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

void IOP(){
	cin.tie(0) ,cout.tie(0);
	ios::sync_with_stdio(0);
}

void frop(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
}

const int N = 105;
int m,n,a[N],ccc;

int f(int x){
	int t;
	while(t*n<=x){
		t++;
	}
	return t-1;
}

int main(){
	frop();//必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 必须检查 
	IOP();//注意C风格输入输出 注意C风格输入输出 注意C风格输入输出 注意C风格输入输出 注意C风格输入输出 注意C风格输入输出 
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[(i-1)*n+j];
			if(1==j && j==i)ccc=a[(i-1)*n+j];
		}
	}
	
	sort(a+1,a+n*m+1,greater<int>());
	
	int l;
	for(int i=1;i<=n*m;i++){
		if(a[i]==ccc){
//			cout<< i%n+1 << ' ' << floor(i/n)+1;
			l=i;
			break;
		}
	}
	
//  2 2 99 100 97 98
//  2 2 98 97 99 100
//  3 3 94 95 96 97 98 99 100 92 93
//  4 4 6 1 2 3 4 5 7 8 9 10 11 12 13 14 15 16
	
	int x=0,y=1,tot = 0;
	bool c = 1;
	for(int i=1;i<=l;i++){
		if(c){
			x++;
			if(x>n)x=n,y++,c=0;
//			printf("%d %d %d\n",i,x,y);
		}else{
			x--;
			if(x<1)x=1,y++,c=1;
//			printf("%d %d %d\n",i,x,y);
		}
	}
	
	
	cout<<y<<' '<<x;
	return 0;
}
