//ac100 Õº¡È±£”” 
#include<bits/stdc++.h>
using namespace std;
int n,m;
struct st{
	int a,num;
}s[105];
bool cmp(st x,st y){
	return x.a>y.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>s[i].a;
		s[i].num=i+1;
	}
	sort(s,s+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(s[i].num==1){
			int c=(i+1)/n;
			if(i+1-c*n!=0)c+=1;
			if(c%2==0){
				cout<<c<<' ';
				cout<<c*n-i;
				return 0;
			}
			else{
				cout<<c<<' ';
				if((i+1)%n==0){
					cout<<n;
				}
				else cout<<(i+1)%n;
				return 0; 
			}
		}
	}
	return 0;
}
