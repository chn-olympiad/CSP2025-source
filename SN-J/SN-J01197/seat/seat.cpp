//SN-J01197  魏赫含  西安高新一中沣东中学初中校区
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[105],k,q=1,sum=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[sum*m+j]; 
		}
		sum++;
	}
	k=a[1];
	sort(a+1,a+(n*m)+1);
	if(a[1]==k){
		if(m%2==1){
			cout<<m<<" "<<n;
		}
		else cout<<m<<" "<<1;
		return 0;
	}
	for(int i=n*m;i>0;i--){
		if(a[i]==k){
			if(q%n==0){
				cout<<q/n<<" ";
				if((q/n)%2==0){
					cout<<1;
				}
				else{
					cout<<n;
				}
				return 0;
			} 
			else{
				cout<<(q/n)+1<<" ";
				if(((q/n)+1)%2==0){
					cout<<n-(q%n)+1;
				}
				else{
					cout<<q%n;
				} 
				return 0;
			} 
		}
		q++;
	}
	return 0;
}
