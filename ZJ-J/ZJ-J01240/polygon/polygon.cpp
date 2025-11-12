#include<bits/stdc++.h>
using namespace std;
long long n;
int a[6000];
int b[6000][6000];
long long nn,M;
long long num;
void f1(long long a1,long long a2){
	if(a2==-1){
		return ;
	}
	if(a1>2*a2){
//	cout<<a1<<" "<<a2<<endl;
		num++;
	}
	return ;
}
void f(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			for(int ii=i+1;ii<=n;ii++){
				for(int jj=i+1;jj<=ii;jj++){
					if(ii+1>n){
						if(jj-1<=i){
							if(j-1<=0){
								M=-1;
							}else{
								M=a[j-1];
							}
						}
						else{
							M=a[jj-1];
						}
					}
					else{
						M=a[n];
					}
//					cout<<ii<<" "<<jj<<endl;
					f1(nn-b[i][j]-b[ii][jj],M);
				}
			}
		}	
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
//		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i][i]=a[i];
		nn+=a[i];
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			b[i][j]=b[i-1][j]+b[i][i];
		}
	}
	f();
	for(int i=1;i<=n-1;i++){
//		cout<<nn-b[i][i]<<" "<<a[n]<<endl;
		f1(nn-b[i][i],a[n]);
	}
	f1(nn-b[n][n],a[n-1]);
	f1(nn,a[n]);
	cout<<num%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
