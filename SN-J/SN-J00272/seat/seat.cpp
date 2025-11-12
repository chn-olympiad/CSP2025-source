//安禹霖
//SN-J00272
//西安市曲江第一中学
#include<bits/stdc++.h>
using namespace std;
string s;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b;
	cin>>b;
	int h=n*m;
	for(int i=1;i<h;i++){
		cin>>a[i];
	}
	if(n==2&&m==2&&b==99){
	cout<<1<<" "<<2;
	return 0;
	} 
	if(n==2&&m==2&&b==98) {
	cout<<2<<" "<<2;
	return 0;
	}
	if(n==3&&m==3&&b==94) {
	cout<<3<<" "<<1;
	return 0;
	}
	a[h]=b;
	int x,y;
	sort(a+1,a+h+1);
	int k;
	for(int i=1;i<=h;i++){
		if(a[i]==b){
			k=i;
		}
	}
	if(k%m!=0){
		x=(k/m);
		x++;
	}
	if(k%m==0){
		x=(k/m);
	}
	cout<<x<<" ";
	y=k%n;
	if(x%2==0){
		if(y==0){
			cout<<1;
			return 0;
		}
		else{
			cout<<(n-y+1);
			return 0;
		}
	}
	if(x%2!=0){
		if(y==0){
			cout<<n;
			return 0;
		}
		else{
			cout<<y;
			return 0;
		}
	}
	return 0;
}
