//SN-J00269
//安奭颉
//西安高新一中沣东中学初中校区 
#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k;
	int a[101];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int j=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==j){
			if(i%n==0){
				k=i/n;
				cout<<k<<" ";
				if(k%2==0) cout<<1<<endl;
				else cout<<n<<endl;
				break;
			}
			else{
				k=i/n+1;
				cout<<k<<" ";
				if(k%2==0) cout<<n-i%n+1;
				else cout<<i%n;
				break;
			} 
		}
	}
	return 0;
}

