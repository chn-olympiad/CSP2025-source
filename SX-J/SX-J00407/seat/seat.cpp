#include<bits/stdc++.h>
using namespace std;
int a[110];
int b[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int y=n*m;
	for(int i=1;i<=y;i++){
		cin>>a[i];
	}
	int q=a[1],s;
	sort(a,a+y+1);
	int w=y;
	for(int i=1;i<=y;i++){
		b[w]=a[i];
		w--;
	}
	for(int i=1;i<=y;i++){
		if(b[i]==q){
			s=i;
			break;
		}
	}
	if(s<n) cout<<1<<" "<<s;
	else cout<<s%n+1<<" "<<s/n+1;
	cout<<endl;
	return 0;
}