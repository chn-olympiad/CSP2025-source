#include<bits/stdc++.h>
using namespace std;
int a[225];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,sum,t;cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}	
	sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum){
			t=i;
		}
	}
	int ans1=(t+n-1)/n;
	int ans2;
	if(ans1%2==1){
	    ans2=t-(ans1-1)*n;
	}
	else{
		ans2=n-(t-(ans1-1)*n)+1;
	} 
	cout<<ans1<<" "<<ans2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
