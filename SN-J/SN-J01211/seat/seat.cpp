#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int r;
bool cmp(int x,int y){
	return x > y;
}
int ans;
void ___go(int ans){
	int x = 1,y = 1;
	int z = 1;//方向 1表示向下，2表示向上 
	for(int i = 1;i <= ans - 1;i++){
		if(z == 1){
			y++;
		}
		if(z == 2){
			y--;
		}
		if(y < 1){
			y++;
			x++;
			z = 1;
		}
		if(y > n){
			y--;
			x++;
			z = 2;
		}
	}
	cout<<x<<" "<<y<<endl;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n * m;i++){
		cin>>a[i];
	}
	r = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	for(int i = 1;i <= n * m;i++){
		//cout<<"a["<<i<<"]="<<a[i]<<endl;
		if(a[i] == r){
			ans = i;
		}
	}
	//cout<<"他是第"<<ans<<"名"<<endl;
	___go(ans);
	return 0;
}
//AC
