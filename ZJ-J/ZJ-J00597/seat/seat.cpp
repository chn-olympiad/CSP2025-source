#include<bits/stdc++.h>
using namespace std;
int n,m,c1,r1;
struct cspj{
	bool R;
	int score;
};
cspj a[1010];
bool cmp(cspj x,cspj y){
	return x.score>y.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;
	}
	a[1].R=true;
	int t=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].R==true){
			t=i;
			break;
		}
	}
	int mod=t%(2*n);
	int intg=t/(2*n);
	if(mod<=n && mod){
		c1=mod;
		r1=2*intg+1;	
	}else if(mod>n){
		c1=2*n-mod+1;
		r1=2*intg+2;
	}else if(mod==0){
		c1=1;
		r1=2*intg;
	}	
	cout<<r1<<' '<<c1<<endl;
	return 0;
}
