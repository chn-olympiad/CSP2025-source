#include<bits/stdc++.h>
using namespace std;
long long n,m,x,z,na;
long long a[1001];
bool cmp(int q,int p){
	return q>p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)x=a[i];
		
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x)z=i;
	}
	if(z%n==0){
		na=z/n;
		cout<<z/n;
	}
	else{
		na=z/n+1;
		cout<<z/n+1;
	}
	if(na%2==0){
		cout<<" "<<n-(z-(na-1)*n)+1;
	}else{
		if(z%n==0){
			cout<<" "<<n;
		}
		else cout<<" "<<z%n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}