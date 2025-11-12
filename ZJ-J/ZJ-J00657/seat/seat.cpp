#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e6+10;
int n,m;
struct node{
	int x,id;
}a[1010];
bool cmp(node a,node b){
	return a.x>b.x; 
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;
	} 
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,f=1;
	for(int i=1;i<=n*m;i++){
	//	cout<<a[i].x<<" "<<x<<" "<<y<<endl;
		if(a[i].id==1) break;
		if((y==n&&f==1)||(y==1&&f==-1)){
			x++;
			f=-f;
		}else{
			y+=f;
		}
	}
	cout<<x<<" "<<y;
	
	return 0;
} 
/*
3 3
94 95 96 97 98 99 100 93 92
*/
