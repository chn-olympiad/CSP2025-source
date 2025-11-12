#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,head=0;
	cin>>m>>n;
	if(m==1&&n==1){
		cout<<1<<" "<<1;
		return 0;
	}
	int xs=m*n;
	int ans[m*n];
	for(int i=0;i<m*n;i++){
		cin>>ans[i];
	}
	int x=ans[0];
	sort(ans,&ans[m*n],cmp);
	for(int i=0;i<xs;i++){
		if(ans[i]==x){
			head=i+1;
		}
	}
	int l=head/n;
	if(head%n!=0){
		l++;
	}
	cout<<l<<" ";
	int ll=head%n;
	if(l%2==1){
		if(ll==0){
			cout<<n;
		}else{
			cout<<ll;
		}
	}if(l%2==0){
		if(ll==0){
			cout<<n-ll;
		}else{
			cout<<1;
		}
	}
	return 0;
} 
