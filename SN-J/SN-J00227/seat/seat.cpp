//商峻熙 SN-J00227 西安市曲江第一中学 
#include <bits/stdc++.h> 
#define ll long long
using namespace std;
const int N = 20;

ll red(){
	ll k = 0,f = 1;
	char c = getchar();
	while(c<'0' || c>'9'){
		if(c=='-')f = -1;
		c = getchar();
	}
	while(c>='0' && c<='9'){
		k = k*10+(c-'0');
		c = getchar();
	}
	return k*f;
}
int n,m,a[N];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n = red();m = red();
	int sum = 0;
	for(int i = 1;i <= n*m;i++){
		a[i] = red();
		if(i == 1)sum = a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int x = 0;
	for(int i = 1;i <= n*m;i++){
		if(a[i] == sum){
			x = i;
			break;
		}
	}
//	for(int i = 1;i <= n*m;i++){
//		cout << a[i] << " ";
//	}
//	cout << "\n" << x << " " << sum << "\n";
	int p = x/n + 1;
	x %= n;
	if(x == 0)x = n,p--;
//	cout << p << " " << x << "\n";
	if(p%2 == 0){
		printf("%d %d",p,m-x+1);
	}else{
		printf("%d %d",p,x);
	}
	return 0;
}
