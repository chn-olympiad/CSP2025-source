#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a1,a2,a3,n,m;
int t;
int a[N][5];
long long f(int qwq,long long u){
	long long ans=0;
	if(qwq>n)return u;
	if(a1<m){
		a1++;
		ans=max(ans,f(qwq+1,u+a[qwq][1]));
		a1--;
	}
	if(a2<m){
		a2++;
		ans=max(ans,f(qwq+1,u+a[qwq][2]));
		a2--;
	}
	
	if(a3<m){
		a3++;
		ans=max(ans,f(qwq+1,u+a[qwq][3]));
		a3--;
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		a1=0;
		a2=0;
		a3=0;
		scanf("%d",&n);
		m=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){//di 1
				scanf("%d",&a[i][j]);
			}
		}
		printf("%d\n",f(1,0));
	}
	return 0;
}
