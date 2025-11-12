#include <iostream>
using namespace std;
int n,m,b,num[110],a[20][20];
bool flag=false;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;cin>>num[1];
	for(int i=2;i<=n*m;i++){
		cin>>num[i];
		if(num[i]>num[1])b++;
	}for(int i=1;i<=n;i+=2){
		for(int j=1;j<=m;j++){
			if(!b){
				cout<<i<<" "<<j<<endl;return 0;
			}b--;
		}for(int j=m;j>=1;j--){
			if(!b){
				cout<<i+1<<" "<<j<<endl;return 0;
			}b--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}