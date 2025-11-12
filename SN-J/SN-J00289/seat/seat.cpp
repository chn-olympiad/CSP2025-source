#include<bits/stdc++.h>
using namespace std;
struct dat{
	int id;
	bool f = false;
};
dat a[200];
bool cmp(dat x,dat y){
	return x.id>y.id;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	//n---hangshu
	//m---lieshu
	a[1].f = 1;
	for(int i = 1;i<=n*m;i++){
		int x;cin>>x;
		a[i].id = x;
	}
	sort(a+1,a+n*m+1,cmp);
	int cur = 0;
	for(int i = 1;i<=n*m;i++){
		if(a[i].f==1){
			cur = i;
			break;
		}
	}
	int x,y,cnt = 0;
	for(int i = 1;i<=m;i++){
		if(i%2==1){
			for(int j = 1;j<=n;j++){
				if(cnt==cur){
					x = j,y = i;
					cout<<y<<" "<<x;
				}
				cnt++;
				if(cnt==cur){
					x = j,y = i;
					cout<<y<<" "<<x;
					return 0;
				}
				
			}
		}
		else{
			for(int j = n;j>=1;j--){
				if(cnt==cur){
					x = j,y = i;
					cout<<y<<" "<<x;
				}
				cnt++;
				if(cnt==cur){
					x = j,y = i;
					cout<<y<<" "<<x;
					return 0;
				}
			}
		}
	}
	return 0;
}
