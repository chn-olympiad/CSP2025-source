#include<bits/stdc++.h>
using namespace std;
int n;
int a[10001];
int num = 0;
bool cmp(int x,int y){
	return x>y;
}
int cnt = 0;
/*void dfs(int x){
	int num_ = num;
	int op = num_;
	num_ -= a[x+1];
	int l = x+2;
	int r = l;
	while(){
		if(op-a[r]<=a[x+1]){
			l++;
			r=l;
		}else{
			op-a[r];
			
		}
	}
}*/
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num += a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(n==3){
		if(num>a[1]*2){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
		return 0;
	}
	/*for(int i=0;i<=n-2;i++){
		num-=a[i];
		dfs(i);
	}*/
	
	return 0;
}