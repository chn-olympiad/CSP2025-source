#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[123]={0};
	cin>>n>>m>>a[1];
	int x=a[1];
	for(int i=2;i<=n*m;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;--i){
		if(a[i]==x){
		    
			int ans,answer,j=n*m-i+1;
			if(j%n==0){
				cout<<j<<" "<<n<<endl;
				cout<<j/n<<" ";
				ans=j/n;
			}else{
				cout<<j/n+1<<" ";
				ans=j/n+1;
			}
			answer=j%n;
			if(j%n==0){
				answer=n;
			}
			if(ans%2==1){
				cout<<answer;
			}else{
				cout<<n-answer+1;
			} 
		}
	}
	return 0;
}
