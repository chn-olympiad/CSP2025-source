//SN-J01140 西安高新第二初级中学 韦博彦 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[105],n,m;
bool f=0;
bool cmp(int x,int y) {
	return x>y;
}
signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int R=a[1],x=1,y=1;
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1; i<=n*m; i++) {
		if(a[i]==R) {
			cout<<y<<" "<<x;
			return 0;
		} else {
			if(i%n==0) {
				y++;
				if(f==0) f=1;
				else f=0;
			}
			if(f==0) {
				x++;
			} else {
				x--;
			}
		}
	}


	return 0;
}
/*
	怎么就调不出来啊啊啊啊啊啊啊啊！！！！！！！！！！！
	呜呜呜只能是二等奖了{’^’}
	备份小代码：
	#include<bits/stdc++.h>
	#define int long long
	using namespace std;
	int a[105],n,m;
	bool cmp(int x,int y){
		return x>y;
	}
	signed main(){
	//	freopen("seat.in","r",stdin);
	//	freopen("seat.out","w",stdout);
		cin>>n>>m;
		for(int i=2;i<=n*m;i++){
			cin>>a[i];
		}
		int R=a[1],x=1,y=1;
		sort(a+1,a+1+(n*m),cmp);
		int p;
		for(int i=1;i<=n*m;i++){
			if(a[i]==R){
				p=i;
				break;
			}
		}
		cout<<p<<endl;
		int q=p/n;
		int w=p%n;
		if(q%2==0){
		if(w==0) cout<<q<<" "<<n;
			else cout<<q+1<<" "<<n-w+1;
		}else if(q%2==1){
			if(w==0) cout<<q<<" "<<n;
			else cout<<q+1<<" "<<w;
		}
		return 0;
	}
	(虽然好像比上边的还拉胯) ~>(-_-)<~
*/
