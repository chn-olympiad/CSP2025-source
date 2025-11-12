#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,num[105],x = 0;
bool cmp(int a,int b){
	return a > b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n * m;i++){
		scanf("%d",&num[i]);
	}
	x = num[1];
	sort(num + 1,num + n * m + 1,cmp);
	for(int i = 1;i <= n * m;i++){
		if(num[i] == x){
			int a = i / n,b = i % n;
			if(b >= 1) a++;
			if(b == 0) b = n;
			if(a % 2 >= 1) printf("%d %d\n",a,b);
			else printf("%d %d\n",a,m - b + 1);
			return 0;
		}
	}
	return 0;
} 
