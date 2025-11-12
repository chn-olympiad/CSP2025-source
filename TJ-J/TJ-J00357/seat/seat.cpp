#include<iostream>
#include<algorithm>
using namespace std;
struct kaoshi{
	int num;
	int fst;
}a[105];
bool cmp(kaoshi x,kaoshi y){
	return x.fst>y.fst;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			k++;
			cin>>a[k].fst;
			a[k].num=k;
		}
	}
	sort(a+1,a+k+1,cmp);
	k=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				k++;
				if(a[k].num==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				k++;
				if(a[k].num==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
