#include <bits/stdc++.h>
using namespace std;


int l[100005][3];
int t;


int maxn = -1;

int search(int k,int n,int a,int b,int c,int num){
	if(k > n){
		if(num > maxn){
			maxn = num;
		}
		return 0;
	}
	else{
		if(a > 0){
			search(k+1,n,a-1,b,c,num + l[k][0]);
		}
		if(b > 0){
			search(k+1,n,a,b-1,c,num + l[k][1]);
		}
		if(c > 0){
			search(k+1,n,a,b,c-1,num + l[k][2]);
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int ooo = 1;ooo<=t;ooo++){
		memset(l,0,sizeof(l));
		int n;
		cin >> n;
		int a = n/2;
		for(int i = 1;i<=n;i++){
			scanf("%d %d %d",&l[i][0],&l[i][1],&l[i][2]);
		}
		maxn = -1;
		search(1,n,a,a,a,0);
		cout << maxn<< endl;
	}
	return 0;
		
}