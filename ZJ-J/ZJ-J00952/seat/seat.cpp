#include<bits/stdc++.h>
using namespace std;
int n,m,f=1,x=1,y=1;
bool flag=1;
struct point{
	int id,fen;	
}a[10110];
bool cmp(point q,point p){
	return q.fen>p.fen;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].fen;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);

	if(a[1].id==1){
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i=2;i<=n*m;i++){
		if(x<n&&flag){
			
			x++;
			
		}
		else if(x>1&&flag==0){
			
			x--;
			
		}
		else{
			y++;
			if(flag){
				flag=0;
			}
			else{
				flag=1;
			}
		}
		if(a[i].id==1){
			cout<<y<<" "<<x;
			return 0;
		}
	}
	
	return 0;
}
