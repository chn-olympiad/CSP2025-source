#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pre(i,b,a) for(int i=(b);i>=(a);i--)
#define mem(a,b) memset(a,b,sizeof(a));

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


struct node{
	int x,val;	
}a[205];
int n,m,ans[20][20],cnt;
bool cmp(node u,node v){
	return u.val>v.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n*m){
		a[i].x=i;
		cin>>a[i].val;
	}
	sort(a+1,a+1+n*m,cmp);
	rep(j,1,m){
		rep(i,1,n){
			cnt++;
			if(j&1) ans[i][j]=a[cnt].x;
			else ans[n-i+1][j]=a[cnt].x;
		}
	}
	rep(i,1,n){
		rep(j,1,m){
			if(ans[i][j]==1){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

