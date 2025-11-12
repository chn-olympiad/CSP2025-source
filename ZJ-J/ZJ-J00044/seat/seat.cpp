#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int v,idx;
}a[1111];
int n,m;
bool cmp(node a,node b){
	return a.v>b.v;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;++i){
		cin>>a[i].v;
		a[i].idx=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int R_idx=-1;
	for (int i=1;i<=n*m;++i){
		if (a[i].idx==1){
			R_idx=i;
			break;
		}
	}
	if (R_idx==1){
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	//cout<<R_idx<<endl;
	int cnt=1,nx=1,ny=1,f=1;
	bool ff=0;
	for (int i=1;i<=n*m;++i){
		//cout<<nx<<" "<<ny<<" "<<cnt<<endl;
		if (nx==n){
			ny+=1;
			if (cnt+1==R_idx){
				cout<<ny<<" "<<nx<<endl;
				return 0;
			}
			cnt+=1;
			if (f==1){
				f=-1;
			}else{
				f=1;
			}
			nx=n-1;
		}else if (nx==1 && ny!=1){
			ny+=1;
			if (f==1){
				f=-1;
			}else{
				f=1;
			}
			if (cnt+1==R_idx){
				cout<<ny<<" "<<nx<<endl;
				return 0;
			}
			cnt+=1;
			nx=2;
		}else{
			nx+=f;
		}
		++cnt;
		if (cnt==R_idx){
			cout<<ny<<" "<<nx<<endl;
			return 0;
		}
	}
	return 0;
}
/*
2 2
2 99 100 97 98
*/
