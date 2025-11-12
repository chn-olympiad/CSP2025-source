#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int n,m,a[110],r,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	r=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==r){
			s=i+1;
		}
	}
	int x=s/n;
	if(s>n) x++;
	int y=s-(x-1)*n;
	if(x%2){
		cout<<x<<" "<<y;
	}else{
		cout<<x<<" "<<n-y+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

