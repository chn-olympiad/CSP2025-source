#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],f,tt=0;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>f;
	for(int i=0;i<n*m-1;i++){
		int tmp;
		cin>>tmp;
		a[tmp]++;
	}
	for(int i=100;i>=0;i--){
		if(i==f){
			break;
		}
		if(a[i]){
			tt++;
		}
	}
	if((tt/n)%2==0){
		cout<<tt/n+1<<" "<<tt%n+1;
	}else cout<<tt/n+1<<" "<<n-tt%n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
