#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;
int n,m;
struct p{
	int a,id;
}a[N];
bool cmp(p n1, p n2){
	return n1.a>n2.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n*m;i++)cin >>a[i].a,a[i].id=i;
	sort(a+1,a+n*m+1,cmp);
	int l=1,r=1,k=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			cout<<r<<" "<<l<<"\n";
			return 0; 
		}
		l+=k;
		if(l>n||l<1){
			k*=-1;
			r++;
			l+=k;
		}
	}
	return 0;
}

