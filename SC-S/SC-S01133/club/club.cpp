#include<bits/stdc++.h>
using namespace std;
const int N=10001;
int q,w,e;
int t,n;
int a[N][N];
int d[3]={1,2,3};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				q=q+a[i][1];
				if(d[1]>n/2){
					break;
				}
			}
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				w=w+a[i][1];
				if(d[2]>n/2){
					break;
				}
			}
			if(a[i][3]>a[i][2]&&a[i][3]>a[i][1]){
				e=e+a[i][1];
				if(d[3]>n/2){
					break;
				}
			}
		}
	}
	cout<<q<<w<<e;
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}