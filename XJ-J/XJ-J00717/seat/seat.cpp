#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=100+5;
int g[N][N];
int n,m,key;
int hcnt=1,lcnt=1;//行号，列号 
bool flag=1;//0表示向上，1表示下降

struct node{
	int num;
	int h,l;
}a[N];

bool cmp(node x,node y){
	return x.num>y.num;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		if(i==1){
			key=a[i].num;
		}
	}
//	cout<<key<<"\n";
	sort(a+1,a+1+(n*m),cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i].num<<" ";
//	}
//	cout<<"\n"; 
	for(int i=1;i<=n*m;i++){
		//如果行大于n，从下面换 
		if(hcnt>n){
//			cout<<"下换行操作\n";
			hcnt=n;
			lcnt++;
			//上升
			flag=0; 
		}else if(hcnt<1){
//			cout<<"上换行操作\n";
			hcnt=1;
			lcnt++;
			//下降
			flag=1; 
		} 
		//赋值
		a[i].h=hcnt;
		a[i].l=lcnt;
//		cout<<"当前:"<<hcnt<<" " <<lcnt<<"\n";
		//如果上升
		if(flag==0){
			hcnt--;
		}else{
			hcnt++;
		}
//		cout<<"变换后："<<hcnt<<" "<<lcnt<<"\n";
//		if(a[i].num==key){
//			cout<<a[i].l<<" "<<a[i].h;
//			return 0;
//		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i].num==key){
			cout<<a[i].l<<" "<<a[i].h;
			return 0;
		}
//		cout<<a[i].num<<":"<<a[i].l<<" "<<a[i].h<<"\n";
	}
	return 0;
}
/*
名次/n
(1,1) (2,1)
(1,2) (2,2)
(1,3) (2,3)
(1,n) (1+1,n)
if(hcnt==n+1){
			//换列操作
			hcnt=n;
			lcnt++;
			cout<<"环列,当前行："<<hcnt<<" "<<lcnt<<"\n";
			//翻转 
			if(flag==1){
				flag=0;
			}else{
				flag=1;
			}
		}
//		if(hcnt<=0){
//			cout<<"环行,当前行："<<hcnt<<" "<<lcnt<<endl;
//			hcnt=1;
//			lcnt++;
//			//开始下降
//			flag=1; 
//		}
		//赋值
		a[i].h=hcnt;
		a[i].l=lcnt;
		cout<<lcnt<<" "<<hcnt<<"\n";
		//如果下降，行+1  反之亦然 
		if(flag){
			hcnt++;
		}else{
			hcnt--;
		}
		if(a[i].num==key){
			cout<<"ans:"<<a[i].l<<" "<<a[i].h<<"\n";
			
		}
*/
