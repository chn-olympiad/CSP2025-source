#include<bits/stdc++.h>
using namespace std;
struct id{
	int s1,p;
}a[1010];
bool cmp(id b,id c){
	return b.s1>c.s1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f=n*m;
	for(int i=1;i<=f;i++){
		int s;
		cin>>s;
		a[i].s1=s;
		a[i].p=i;
	}
	sort(a+1,a+f+1,cmp);
	for(int i=1;i<=f;i++){
		if(a[i].p==1){
			if(i%n==0){
				cout<<i/n<<" ";
				if(i/n%2==1){
					cout<<n<<endl;
				}else{
					cout<<1<<endl;
				}
			}else{
				cout<<1+i/n<<" ";
				if((i+3-i%n)/n%2==1){
					cout<<i%n<<endl;
				}else{
					cout<<n-(i%n)+1<<endl;
				}
			}
			break;
		}
	}
	return 0;
}
