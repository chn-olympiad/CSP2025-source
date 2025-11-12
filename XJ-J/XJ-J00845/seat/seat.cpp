#include<bits/stdc++.h>//先sort在二分（保证找到）最后初行数，看是哪个方向（%2）最后输出// 
using namespace std;
int n,m;
int a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int y=n*m; 
	for(int i=1;i<=y;i++){
		cin>>a[i];
	}
	int c=a[1];//小r成绩
	sort(a,a+y+1);//sort成功 
	int h=0;
	while(a[h]!=c){
		h++;
	}
	h=y-h+1;//成绩是从低到高sort所以要多这一步算出坐第几个座位 
	int b=h/n;
	b=b*n;
	if(h%n==0){
		cout<<h/n<<" ";
		if((h/n)%2==1){
			cout<<n;
		}else{
			cout<<1;
		}
	}
	else{
		cout<<(h/n)+1<<" ";
		if((h/n)%2==0){
			cout<<h-b;
		}else{
			cout<<n-h+b+1;
		}
	}
	return 0;
} 
