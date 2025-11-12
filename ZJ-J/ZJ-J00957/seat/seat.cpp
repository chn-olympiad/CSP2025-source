#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m;
int a[maxn];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int befRseat=a[1],nowRseat=0;
	sort(a+1,a+(n*m)+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(befRseat==a[i]){
			nowRseat=i;
			break;
		}
	}
	int col=ceil(1.0*(nowRseat)/m),row;
	int Fcol=(nowRseat-1)/m*m;
	if(col%2==1){
		row=nowRseat-Fcol;
	}
	else{
		row=n-(nowRseat-Fcol)+1;
	}
	cout<<col<<" "<<row<<endl;
	return 0;
}