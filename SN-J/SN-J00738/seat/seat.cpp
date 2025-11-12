//SN-J00738 王子铭 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int b[N][N],n,m;
int a[105];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i ++){
		cin >> a[i];
	}
	int k = a[1];
	sort(a+1,a+n*m+1,cmp);
	int l = 1;
	for(int i = 1;i <= m;i ++){
		for(int j = 1;j <= n;j ++){
			if(a[l]==k){
				if(i%2==1){
					cout << i << " " << j;
				}else{
					cout << i << " " << n-j+1;
				}
				
				return 0;
			}
			l ++;
		}
	}
	return 0; 
}
