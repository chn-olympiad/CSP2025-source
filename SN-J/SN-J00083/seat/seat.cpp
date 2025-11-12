#include<bits/stdc++.h>
using namespace std;
int b[105],a[12][12];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	b[0]=b[1];
	sort(b+1,b+n*m+1,cmp);
	int k=1;
	/*for(int i=0;i<=n*m;i++){
		cout<<b[i]<<" ";
	}\
	cout<<endl;*/
	for(int i=1;i<=m;i++){
		if(!(i%2)){
			for(int j=n;j>0;j--){
				a[j][i]=b[k];
				//cout<<a[j][i]<<" "<<i<<" "<<j<<endl;
				k++;
				if(a[j][i]==b[0]){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=1;j<=n;j++){
				a[j][i]=b[k];
				//cout<<a[j][i]<<" "<<i<<" "<<j<<endl;
				k++;
				if(a[j][i]==b[0]){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
