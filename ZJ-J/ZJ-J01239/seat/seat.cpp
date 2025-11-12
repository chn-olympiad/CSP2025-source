#include<bits/stdc++.h>
using namespace std;
int n,m,fw;
struct nm{
	int w,id;
}a[200];
bool px(nm a,nm b){
	return a.w>b.w;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].w;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,px);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			fw=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if((i-1)*n+j==fw){
					cout<<i<<" "<<j;
					fclose(stdin);
					fclose(stdin);
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if((i-1)*n+n-j+1==fw){
					cout<<i<<" "<<j;
					fclose(stdin);
					fclose(stdin);
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdin);
	return 0;
}
