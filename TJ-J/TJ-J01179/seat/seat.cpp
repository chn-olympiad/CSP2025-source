#include<bits/stdc++.h>
using namespace std;
int a[15][15],n,m,tmp1=1,b[105],fh=1,xr;//n行m列 ,fh=1:+,fh=0:-
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	xr=b[1];
	sort(b+1,b+(n*m)+1,greater<int>());
	/*for(int i=1;i<=n*m;i++){
		cout<<b[i]<<" "; 
	}*/
	int p=1,q=1;//p为n，q为m 
	while(tmp1<n*m){
		if(p>n){
			p=n;
			q++;
			fh=0;
		}
		else if(p<1){
			p=1;
			q++;
			fh=1;
		}
		a[p][q]=b[tmp1];
		if(b[tmp1]==xr){
			cout<<q<<" "<<p;
			return 0;
		}
		if(fh==1) p++;
		else p--;
		tmp1++;
	}
	cout<<m<<" "<<n;
	return 0;
}

