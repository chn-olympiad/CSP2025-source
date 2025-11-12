#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-f;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
ll n,m;
struct node{
	int val,cnt;
}a[105];
bool cmp(node x,node y){
	return x.val>y.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		a[i].val=read();
		a[i].cnt=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int tmp=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].cnt==1){
			tmp=i;
			break;
		}
	}
	int x=tmp%n;
	int y=(tmp-x)/n;
	if(x!=0)y++;
	if(y%2==1){
		if(x==0){
			x=n;
		}
	}else{
		if(x==0)x=1;
		else x=n-x+1;
	}
	cout<<y<<' '<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

