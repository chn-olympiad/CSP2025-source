#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(ans==a[i]){
			int lie=i/n+1;
			int hang=i%n;
			if(hang==0){
				hang=n;
				lie--;
			}
			if(lie%2==0)hang=n-hang+1;
			cout << lie << " " << hang;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
