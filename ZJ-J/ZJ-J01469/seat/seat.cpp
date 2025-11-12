#include<bits/stdc++.h>
using namespace std;
int mp[105][105],a[10005],n,m,k,f=1;
bool cmp(int q,int p){
	return q>p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,t=1;
	mp[x][y]=a[t];
	x++;
	if(a[t++]==k){
		cout<<y<<' '<<x<<endl;
		f=0;
	}
	while(f==1&&t<=n*m){
		while(x<=n&&f==1){
			mp[x][y]=a[t];
			if(a[t]==k){
				cout<<y<<' '<<x<<endl;
				f=0;
			}
			x++;t++;			
		}x--;
		y++;mp[x][y]=a[t];
		if(mp[x][y]==k&&f==1){
			cout<<y<<' '<<x<<endl;
			f=0;
		}
		while(x>=1&&f==1){
			mp[x][y]=a[t];
			if(a[t]==k){
				cout<<y<<' '<<x<<endl;
				f=0;
			}
			x--;t++;
		}x++;
		y++;mp[x][y]=a[t];
		if(mp[x][y]==k&&f==1){
			cout<<y<<' '<<x<<endl;
			f=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<mp[i][j]<<' ';
		}cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
