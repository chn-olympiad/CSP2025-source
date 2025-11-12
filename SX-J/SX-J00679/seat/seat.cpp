#include <bits/stdc++.h>
using namespace std;
int n, m;
int s[105];
int idx[11][11];

bool cmp (int a, int b){
	return a>b;
}

int wz(int a){
	int lie;
	int hang;
	if(a%n==0){
		lie = a/n;
	}else if(a%n!=0){
		lie = a/n+1;
	}
	
	if (lie%2==1){
		if(a%n!=0){
			hang = a%n;
		}else if(a%n==0){
			hang = n;
		}
	}else if(lie%2==0){
		if(a%n!=0){
			hang = n-a%n+1;
		}else if(a%n==0){
			hang = 1;
		}
	}
	
	printf("%d %d",lie,hang);
	return 0;
}

int main() {
	// shu ru
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin >> n >> m;
	for(int i = 1 ; i <= n*m; i++) {
		cin >> s[i];
	}
	int xa = s[1],idxa = 0;
	
	//pai xu
	sort(s+1,s+n*m+1,cmp);
	
	//cha zhao
	for(int i = 1 ;i <= n*m; i++){
		if(s[i]==xa){
			idxa = i;
			break;
		}
	}
	
	// wei zhi
	wz(idxa);
	return 0;
}
