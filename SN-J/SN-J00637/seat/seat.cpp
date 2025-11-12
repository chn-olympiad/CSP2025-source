#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+1+n*m,cmp);
	int h=1,l=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			cout<<l<<" "<<h<<"\n";
			break;
		}
		if(l%2==1) h++;
		else h--;
		if(h>n){
			h=n;
			l++;
		}
		if(h<1){
			h=1;
			l++;
		}
	}
	return 0;
}
