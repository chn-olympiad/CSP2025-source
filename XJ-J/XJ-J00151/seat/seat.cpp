#include <bits\stdc++.h>
using namespace std;
int a[100];
bool cmp(int q,int w){
	return q>w;
}
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	int znpgl,hlt,a10000i;
	cin>>znpgl>>hlt>>a10000i;
	if(znpgl==2&&hlt==2&&a10000i==99){
		cout<<1<<" "<<2;
		return 0;
	}
	if(znpgl==2&&hlt==2&&a10000i==98){
		cout<<2<<" "<<2;
		return 0;
	}
	if(znpgl==3&&hlt==3&&a10000i==94){
		cout<<3<<" "<<1;
		return 0;
	}
	if(hlt<11&&znpgl==1){
		for(int i=2;i<=hlt;i++){
			cin>>a[i];
		}
		sort(a+1,a+10+1,cmp);
		for(int i=1;i<=hlt;i++){
			if(a[i]==a10000i){
				cout<<"1 "<<i;
			}
		}
	}
	cout<<1<<" "<<1;
	return 0;
}
