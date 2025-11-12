#include<bits/stdc++.h>
#define lon long long
using namespace std;
int n,m;//10 10
int w;
struct stu{
	int s,bh;
}a[110];
bool cmp(stu a,stu b){return a.s>b.s;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].s,a[i].bh=i;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++) if(a[i].bh==1){
		w=i;
		break;
	}
	for(int i=1;i<=n;i++){
		if(i%2==1) for(int j=1;j<=m;j++){
			w--;
			if(!w){
				cout<<i<<' '<<j;
				return 0;
			}
		}
		if(i%2==0) for(int j=m;j>=1;j--){
			w--;
			if(!w){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}
