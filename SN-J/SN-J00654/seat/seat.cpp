#include<bits/stdc++.h>
using namespace std;
int gr_s[15][15];
int gr[105];
int gr1[105];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>gr[i];
	}
	int R=gr[1];
	sort(gr+0,gr+n*m+1);
	for(int i=n*m;i>=1;i--){
		gr1[i]=gr[i];
//		cout<<gr1[i];
	}
	int num=1;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j1=1;j1<=n;j1++){
				gr_s[j1][i]=gr1[num];
				num++;
//				cout<<"0";
//				if(gr_s[j1][i]==R){
//					cout<<i<<" "<<j1;
//					return 0;
//				} 
			}
		}
		else if(i%2==0){
			for(int j2=n;j2>=1;j2--){
				gr_s[j2][i]=gr1[num];
				num++;
//				cout<<"1";
//				if(gr_s[j2][i]==R){
//					cout<<i<<" "<<j2;
//					return 0;
//				} 
			}
		}
	}
	int x=1;
	if(m%2==0){
//		for(int i=1;i<=n;i++){
//			for(int j2=m;j2>=1;j2--){
//				cout<<gr_s[i][j2]<<" ";
//			}
//			cout<<endl;
//		}
		for(int i=1;i<=n;i++){
			int y=1;
			for(int j2=m;j2>=1;j2--){
				if(gr_s[i][j2]==R){
					cout<<y<<" "<<x;
				}
				y++;
			}
			x++;
		}
	}
	if(m%2!=0){
//		for(int i=n;i>=1;i--){
//			for(int j2=m;j2>=1;j2--){
//				cout<<gr_s[i][j2]<<" ";
//			}
//			cout<<endl;
//		}
		for(int i=n;i>=1;i--){
			int y=1;
			for(int j2=m;j2>=1;j2--){
				if(gr_s[i][j2]==R){
					cout<<y<<" "<<x;
				}
				y++;
			}
			x++;
		}
	}
	return 0;
}
