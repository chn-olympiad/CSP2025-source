#include<bits/stdc++.h>
using namespace std;

int n,m;//n行m列
int x,y;//小R的座位
int a[105]; //成绩 

bool cmp(int x,int y){//从大到小 
	return x>y;
}

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	
	cin>>n>>m;//输入 
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	
	int fen=a[1];//小R分数 
	sort(a+1,a+1+n*m,cmp);
	
	int cnt;//小R排名 
	for(int i=1;i<=n*m;i++){
		if(a[i]==fen) cnt=i;
	}
	
	if(cnt>=1&&cnt<=n) x=1,y=cnt;//第x列y行 
	else {
		for(int i=1;i<m;i++){
			if(cnt>i*n&&cnt<=(i+1)*n&&i%2==1) x=i+1,y=n-(cnt-i*n)+1;
			else if(cnt>i*n&&cnt<=(i+1)*n&&i%2==0) x=i+1,y=cnt-i*n;
			else continue;
		}
	}
	
	cout<<x<<" "<<y;//输出 
	cout<<endl;
	return 0;
	
} 
