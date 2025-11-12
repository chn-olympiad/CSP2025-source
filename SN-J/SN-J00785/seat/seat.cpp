#include<bits/stdc++.h>
using namespace std;
int n,m,maxx,sum;
int a[105];
int main(){
	freopen("seat .in","r",stdin);
	freopen("seat .out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	maxx=a[0];
	for(int i=0;i<n*m;i++){
		if(a[i]>maxx){
			sum++;
		}
	}
	sum+=1;
	if(sum%n==0){
		cout<<sum/n<<" ";
	}else{
		cout<<sum/n+1<<" ";
	}
	if(sum%n!=0){
		if(((sum/n)+1)%2==0){
			cout<<((n-(sum/n-1))*(n-(sum/n-1)))/(n-(sum/n-1));
		}else{
			int qwe=sum%n;
			cout<<(qwe*qwe)/qwe;
		}
	}else{
		if(((sum/n)+1)%2==0){
			cout<<((n-(sum/n-1))*(n-(sum/n-1)))/(n-(sum/n-1));
		}else{
			int qwe=sum%n;
			cout<<(qwe*qwe)/qwe;
		}
	}
}

