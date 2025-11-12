#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pre(i,b,a) for(int i=(b);i>=(a);i--)
#define mem(a,b) memset(a,b,sizeof(a));

using namespace std;


typedef long long ll;
typedef unsigned long long ull;

const int N=1e5+5;
int T,n,f[N][5],cnt[5],ans;
struct node{
	int val,x;
}maxn[N];
struct edge{
	int val1,val2,val3;
}a[N];
bool cmp(edge u,edge v){
	if(u.val1==v.val1){
		if(u.val2==v.val2) return u.val2>v.val2;
		return u.val2>v.val2;
	}
	return u.val1>v.val1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		mem(a,0);mem(cnt,0);mem(maxn,0);ans=0;
		cin>>n;
		rep(i,1,n){
			cin>>a[i].val1>>a[i].val2>>a[i].val3;
		}
		if(n==2){
			int max1=max(a[1].val1+a[2].val2,a[1].val1+a[2].val3);
			int max2=max(a[1].val2+a[2].val1,a[1].val2+a[2].val3);
			int max3=max(a[1].val3+a[2].val1,a[1].val3+a[2].val2);
			ans=max(max1,max(max2,max3));
			cout<<ans<<endl;
		}
		else{
			sort(a+1,a+1+n,cmp);
			rep(i,1,n/2){
				ans+=a[i].val1;
			}
			cout<<ans<<endl;			
		}

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

