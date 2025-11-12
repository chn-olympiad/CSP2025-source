#include<bits/stdc++.h>
using namespace std;
long long cnt[200],chengji,xxx;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c=0,p=0;
	bool flag=false;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> cnt[i];
		chengji=cnt[1];
	}
	sort(cnt+1,cnt+n*m+1,cmp);
 	for(int i=1;i<=n*m;i++){
		if(cnt[i]==chengji){
			xxx=i;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(flag==false){
			flag=true;
			for(int j=1;j<=n;j++){
				c++;
				if(xxx==c){
					cout << i << " " << j;
					return 0;
				}
			}
		}

		else if(flag==true){
			flag=false;
			for(int j=n;j>=1;j--){
   				c++;
				if(xxx==c){
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}