#include<bits/stdc++.h>

using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int x=a[1],cnt=0;
	sort(a+1,a+1+n*m,cmp);
	bool f=0;
	for(int i=1;i<=m;i++){
		if(f){
			break;
		}
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt++;
				if(a[cnt]==x){
					cout << i << ' ' << j;
					f=1;
					break;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(a[cnt]==x){
					cout << i << ' ' << j;
					f=1;
					break;
				}
			}
		}
	}
	return 0;
}
