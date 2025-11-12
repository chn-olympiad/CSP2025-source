#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
}t[105];
int w,g;
int cmp(node x,node y){
	return x.a>y.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>t[i].a;
		t[i].b=i;
		if(i==1) g=t[i].a;
	}
	sort(t+1,t+n*m+1,cmp);
	int i=1,j=n*m;
	while(i<=j){
		int mid=(i+j)/2;
		if(t[mid].a==g){
			w=mid;
			break;
		}
		if(t[mid].a>g) i=mid+1;
		else j=mid-1;
	}
	int ans2,ans1=(w+n-1)/n;
	if(ans1%2!=0){
		ans2=w%n;
		if(w%n==0) ans2=n;
	}
	if(ans1%2==0){
		ans2=n-w%n+1;
		if(w%n==0) ans2=1;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
