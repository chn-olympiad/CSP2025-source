#include<bits/stdc++.h>
using namespace std;
int n,m,t,a[110],s,pm,h,l;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	t=n*m;
	for(int i=1;i<=t;i++) cin>>a[i];
	s=a[1];
	sort(a+1,a+1+t,cmp);
    for(int i=1;i<=t;i++){
    	if(a[i]==s){
    		pm=i;
    		break;
		}
	}
	l=ceil(pm*1.0/n);
	if(l%2==0) h=l*n-pm+1;
	else h=pm-(l-1)*n;
	cout<<l<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
