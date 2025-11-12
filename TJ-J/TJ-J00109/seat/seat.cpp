#include<bits/stdc++.h>
using namespace std;
int book,books[105];
int n,m;
bool flag=true;
int k;
int c=1,r=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	cin>>book;
	books[1]=book;
	for(int i=2;i<=k;i++){
		cin>>books[i];
	}
	sort(books+1,books+k+1,cmp);
	for(int i=1;i<=k;i++){
		if(books[i]==book){
			cout<<c<<' '<<r;
			break;
		}
		if(flag){
			if(r!=n) r++;
			else{
				flag=false;
				c++;
			}
		}else{
			if(r!=1) r--;
			else {
				flag=true;
				c++;
			}
		}
	}
	return 0;
}
