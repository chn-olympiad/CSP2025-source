#include<bits/stdc++.h>
using namespace std;
long long int n,m;
int a[1000001],p[1000001];
int main(){
	freopen("seat","r",stdin);
	freopen("seat","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1],c=1;
	sort(a+1,a+m*n+1);
	for(int i=m*n;i>=1;i--){
		p[c]=a[i];
		c++;
	}for(int i=1;i<=m*n;i++){
	//cout<<p[i];
	if(p[i]==x){
			if((i/n+1)%2==0){
				if(i%n==0)cout<<i/n+1<<" "<<1;
				else cout<<i/n+1<<" "<<n-(i%n)+1;
				}else if(i%n==0)cout<<i/n<<" "<<n;
			else cout<<i/n+1<<" "<<i%n;
			break;
			
		}}
		
	return 0;
}/*2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92
2 2
99 100 97 98
*/
