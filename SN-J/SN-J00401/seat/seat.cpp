#include<bits/stdc++.h>
using namespace std;
//bool flag[105];//you
int cmp(int x,int y){
	if(x>y) return x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;//you
	cin>>n>>m;
	int a[105];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int p=a[1],s;
	
	sort(a,a+n*m);
	sort(a,a+n*m,cmp);
	

	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			s=i;
		}
	}
	
	




	
	int l;
	if(s%n!=0 ) l=s/n+1;
	else l=s/n;
	int h;
	if(l%2!=0&&s%n!=0) h=s%n;
	else if(l%2!=0&&s%n==0) h=n;
	else h=n-s%n+1;
	cout<<l<<" "<<h<<endl;
	
	return 0;
} 
