#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int nm=n*m;
	int o=0;
	for(int i=1;i<=nm;i++) cin>>a[i];
	o=a[1];
	sort(a+1,a+1+nm,cmp);
	int u=0;
	for(int i=1;i<=nm;i++)
		if(a[i]==o){
			u=i;
			break;
		}
	int c=0,r=0,e=1;
	for(int i=1;i<=m;i++)
		if(i%2==1)
			for(int j=1;j<=n;j++){
				if(u==e){
					cout<<i<<" "<<j;
					return 0;
				}
				e++;
			}
		else
			for(int j=n;j>=1;j--){
				if(u==e){
					cout<<i<<" "<<j;
					return 0;
				}
				e++;
			}
	return 0;
}
