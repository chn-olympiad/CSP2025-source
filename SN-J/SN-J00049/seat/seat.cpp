//SN-J00049 余炜杰 西安辅轮中学
#include<bits/stdc++.h> 
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int a[11451419];
int seat[11451][19198];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a1;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		a1=a[1];
	}
	sort(a,a+n*m+1,cmp);
	/*for(int i=0;i<n*m;i++){
		cout<<a[i]<<" ";
		
	}*/
	int cnt=0;
	int hang=0,lie=0;
	for(hang;hang<m;hang++){
		if(hang%2==1){
			for(lie;lie<n;lie++){
				seat[hang][lie]=a[cnt];
				cnt++;
			}
		}
		else{
			for(lie;lie>=0;lie--){
				seat[hang][lie]=a[cnt];
				cnt++;
			
			}
		}
		
		
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(seat[i][j]==a1){
				cout<<i+1<<' '<<j+1;
				return 0;
			}
		}
	}
	cout<<1<<' '<<1;
	return 0;
}
