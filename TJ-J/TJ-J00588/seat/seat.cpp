#include<bits/stdc++.h>
using namespace std;
struct seatt{
	int c,r;
	int fen;
	int xiaoR;
}a[101];
bool cmp(seatt a,seatt b){
	return b.fen<a.fen;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	a[1].xiaoR=3;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].fen;
	}
	sort(a+1,a+1+n*m,cmp);
	int k=1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				a[k].c=i;
				a[k].r=j;
				k++;
			}
		}
		else if(i%2==0){
			for(int j=m;j>=1;j--){
				a[k].c=i;
				a[k].r=j;
				k++;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i].xiaoR==3){
			cout<<a[i].c<<' '<<a[i].r;
		}
	}
	
	
	
	
	
	
	
	
	
//	if(m%2==1){
//		for(int j=m;j>=1;){
//			for(int i=n;i>=1;i--){
//				if(a[i].R==1){
//					cout<<i<<' '<<j;
//					return 0;
//				}
//			}
//			j--;
//			for(int i=1;i<=n;i++){
//				if(a[i].R==1){
//					cout<<i<<' '<<j;
//					return 0;
//				}
//			}
//			j--;
//		}
//	}
//	else if(m%2==0){
//		for(int j=1;j<=m;){
//			for(int i=1;i<=n;i++){
//				if(a[i].R==1){
//					cout<<i<<' '<<j;
//					return 0;
//				}
//			}
//			j--;
//			for(int i=n;i>=1;i--){
//				if(a[i].R==1){
//					cout<<i<<' '<<j;
//					return 0;
//				}
//			}
//			j--;
//		}
//	}
	
	
	return 0;
}
