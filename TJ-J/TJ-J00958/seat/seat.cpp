#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[999],c=1,r=1,s,k=0;
	bool e="True";
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
			cin>>a[i];
	}
	s=a[0];
	int map[n+1][m+1];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n;i++){
		if(e){
			for(int j=0;j<m;j++){
				map[i][j]=a[k];
				k+=1;
			}
		}
		else{
			for(int j=m;j>0;j--){
				map[i][j]=a[k];
			}
		}
		e=not(e);
	}
	for(c=0;c<n;c++){
		for(r=0;r<m;r++){
			if(map[c][r]==s){
				cout<<c+1<< ' ';
				cout<<r+1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
