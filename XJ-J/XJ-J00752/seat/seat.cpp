#include <bits/stdc++.h>
using namespace std;
int n,m,x=0;
int a[10000];
int ans[10000][10000];
int main(){
    int temp;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=i;j<=n*m;j++){
            if(a[i]<a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(int i=1;i<=n;i=i+2){
        for(int j=1;j<=m;j++){
            x++;
            if(a[x]==num){
                cout<<i<<' '<<j;
                return 0;
            }
        }for(int j=m;j>=1;j--){
            x++;
            if(a[x]==num){
                cout<<i+1<<' '<<j;
                return 0;
            }
        }
    }
}
