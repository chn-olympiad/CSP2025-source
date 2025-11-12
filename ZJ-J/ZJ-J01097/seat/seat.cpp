#include<bits/stdc++.h>
using namespace std;
struct ikun{
	int v,id;
};
bool cmp(ikun a,ikun b){
	return a.v>b.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,ac;
	ikun a[110];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].v;
		a[i].id=i;
	}
	ac=a[1].v;
	sort(a+1,a+n*m+1,cmp);
	int id;
	for(int i=1;i<=n*m;i++){
		if(a[i].v==ac){
			id=i;
			break;
		}
	}
	int i=(id%n==0?(id/n):(id/n+1));
	int j;
	if(i%2==0)j=(id%n==0?1:n-id%n+1);
	else j=(id%n==0?n:id%n);
	cout<<i<<' '<<j;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
