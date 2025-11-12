#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int mp[15][15];
void p(){
	int x=0;
	for(int i=0;i<n*m;i++){
		if(i!=0){
			if(a[i]<a[i-1]){
				x=a[i-1];
				a[i-1]=a[i];
				a[i]=x;
			}
		}
	}
}
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	cin>>n>>m;
	int n1=n*m;
	cin>>a[0];//99
	int d=a[0];//99
	for(int i=1;i<n1;i++){
		cin>>a[i];//100 97 98
	}
	p();//100 99 98 97
	mp[1][1]=a[0];//100
	int k=1;
	bool s=0;
	for(int i=1;i<=n;i=i+0){//100-1 1
		for(int j=1;j<=m;j=j+0){//99-1 2
			if(i+1<n&&j<m&&s==0){//98-2 2
				mp[i+1][j]=a[k];
				k++;
				i++;
			}else{
				if(i-1>0&&j<m&&s==1){
					mp[i-1][j]=a[k];
					k++;
					i--;
				}
				else{
					mp[i][j+1]=a[k];
					k++;
					j++;
					s=!s;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==d){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
