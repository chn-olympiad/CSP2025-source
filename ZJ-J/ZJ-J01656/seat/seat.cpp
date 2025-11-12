//powered by Jin_Yichen
//Luogu UID:727101
#include<bits/stdc++.h>
using namespace std;
int n,m,idx;
struct node{
	int num,id;
}a[105];
bool cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			idx=i;
			break;
		}
	}
	if(idx%n==0){
		int x=idx/n;
		cout<<x<<' ';
		if(x%2==0)cout<<1<<endl;
		else cout<<n<<endl;
	} else {
		int x=idx/n,y=idx%n;
		cout<<x+1<<' ';
		if(x%2==1)cout<<n-y+1<<endl;
		else cout<<y<<endl;
	}
	return 0;
}
