#include<bits/stdc++.h>
using namespace std;
const int maxn=100001;
int a[maxn];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			cnt++;
		}
	}
	int res=0,lie=0;
	cnt++;
	if(cnt%n==0){
		res=cnt%n;
		lie=cnt/n;
		cout<<lie;
	}else{
		res=cnt%n;
		lie=cnt/n+1;
		cout<<lie;
	}
	cout<<" ";
	
	if(res==0)res=n;
	if(lie%2==1){
		cout<<res;
	}else{
		cout<<n-res+1;
	}
	return 0;
}
