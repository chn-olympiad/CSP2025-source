#include<bits/stdc++.h>
using namespace std;
long long n,m,ansc,ansr;
struct note{
	int a,id;
}a[11111];
bool cmp(note x,note y){
	if(x.a>y.a)return 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].a;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			ansc=(i-1)/n+1;
			if(i%n!=0)ansr=i%n;
			else ansr=n;
			if(ansc%2==0){
				ansr=n-ansr+1;
			}
			break;
		}
	}
	cout<<ansc<<" "<<ansr;
}
