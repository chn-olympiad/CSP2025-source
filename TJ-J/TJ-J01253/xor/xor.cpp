#include<iostream>
#include<cmath>
using namespace std;
const int M=1005;
int n,k;
int a[M][M];
int b[M];
long long num=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i][i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int ans=a[i][i];
			for(int q=i+1;q<=j;q++){
				ans^=a[q][q];
			}
			a[i][j]=ans;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i][j]==k&&b[i]!=1&&b[j]!=1){
				for(int q=i;q<=j;q++){
					b[q]=1;
				}
				num++;
			}
		}
	}
	
	
	
	
	
	
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
