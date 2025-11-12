#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,m;
struct st{
	int score;
	int id;
}a[maxn];
bool cmp(st X,st Y){
	return Y.score<X.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].score,a[i].id=i;
	sort(a+1,a+1+n*m,cmp);
	int wher;
	for(int i=1;i<=n*m;i++) if(a[i].id==1){wher=i;break;}
	int x=(wher-1)/n;int y=(x%2==0 ? wher-x*n : n-wher+x*n+1);
	printf("%d %d",x+1,y);
	return 0;
}