#include<bits/stdc++.h>
using namespace std;
int n,m,R;
int a[10000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	R=a[1];
	sort(a+1,a+n+1,cmp);
	int hang=1,lie=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			cout<<lie<<" "<<hang;
			return 0;
		}
		if(hang==1&&lie%2==0)lie++;	
		else if(hang==n&&lie%2==1)lie++;
		else hang+=(1-((lie+1)%2)*2);
		
	}
}