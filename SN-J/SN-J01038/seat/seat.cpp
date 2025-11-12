#include<bits/stdc++.h>
using namespace std;
int a[1005],s[1005][1005];
int main()
{
	//freopen('seat.in','r',stdin);
	//freopen('seat.out','w',stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int c=a[1];
	for(int i=1;i<=n*m;i++){
	if(a[i]>a[1]){
		swap(a[i],a[1]);
	}
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
		for(int j=1;j<=m;j++){
				s[i][j]=a[j+i*m];
			}
		}
		if(i%2==0){
		for(int y=m;y>=1;y--){
				int t=m-1;
				s[i][y]=a[i-t];
				t--;
		}
    }
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==c){
				cout<<i<<" "<<j;
			}
			else{
				continue;
			}
		}
	}
	return 0;
}

