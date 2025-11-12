//SN-J00722 王培翔 雁塔第一学校
#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],ansn,ansm;
int main(){ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		a[i]=100-a[i];
	}
	int flag=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==flag){
			flag=i;
			break;
		}
	}

	ansm=(flag+n-1)/n;
	if(ansm%2){
		ansn=flag%n;

		if(ansn==0){
			ansn=n;
		}
	}else{
		int sh=flag%n;
		if(sh==0)sh=n;
		ansn=n-sh+1;
	}
	cout<<ansm<<' '<<ansn<<'\n';
	return 0;
}
