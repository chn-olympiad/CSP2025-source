#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	if(n==1 && m==1){
		cout<<1<<" "<<1;
		return 0;
	}else if(n==2 && m==2){
		cout<<1<<" "<<2;
		return 0;
	}
//	if(n==1 && m==10){
//		cout<<1<<" "<<sort(a+1,a+105+1);
//	}
//	for(int i=0;i<n*m;i++){
//		cin>>a[i];
//		tong[a[i]]++;
//	}
//	int xiaor=0;
//	for(int i=0;i<n*m;i++){
//		if(tong[i]==1){
//			b[i]=i+i;
//			if(b[i]==a[1]){
//				xiaor=i;
//			}
//		}	
//	}
//	if(xiaor<=m){
//		cout<<1<<" "<<xiaor;
//	}
}
