#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}
int n,m,c=1,r=1,a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int rseat=a[1];
	bool uptodown=1;
	int cnt=1;
	bool sta=0;
	sort(a+1,a+1+n*m,cmp);
	//cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<"=====\n";
	for(int i=1;i<=n;i++){
		if(sta){
			break;
		}
		if(uptodown){
			for(int j=1;j<=m;j++){
				//cout<<a[cnt]<<" 1\n";
				if(a[cnt]==rseat){
					//cout<<a[cnt]<<"\n";
					r=j;
					c=i;
					sta=1;
					break;
				}
				cnt++;
			}
			uptodown=0;
		}
		else{
			for(int j=m;j>=1;j--){
				//cout<<a[cnt]<<" 0\n";
				if(a[cnt]==rseat){
					//cout<<a[cnt]<<"\n";
					r=j;
					c=i;
					sta=1;
					break;
				}
				cnt++;
			}
			
			uptodown=1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
