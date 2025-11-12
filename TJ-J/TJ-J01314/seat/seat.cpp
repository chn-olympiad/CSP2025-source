#include <bits/stdc++.h>
using namespace std;
const int maxn=110;
struct node{
	int num;
	int id;
}a[maxn];
bool cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> a[i].num;
		a[i].id=i;
	}
	sort (a+1,a+n*m+1,cmp);
	/*
	for (int i=1;i<=n*m;i++){
		cout << a[i].num << " ";
	}
	cout << endl;
	*/
	for (int i=1;i<=n*m;i++){
		if (a[i].id==1){
			int x=0;
			if (i%n==0){
				cout << i/n;
				x=i/n;
			}else {
				cout << i/n+1;
				x=i/n+1;
			}
			cout << " ";
			if (x%2!=0){
				if (i%n==0)cout << n;
				else cout << i%n;
			}else {
				int sum=0;
				sum=(x-1)*n+1;
				if (i-sum==0){
					cout << n;
				}else {
					cout << n-(i-sum);
				}
				
			}
			//if (a[i].id==1)cout << " 我是小R " << i << " " << a[i].num;
			//else cout << "我不是小R " << i << " " << a[i].num;
			//cout << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

