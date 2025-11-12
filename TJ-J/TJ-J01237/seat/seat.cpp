#include<bits/stdc++.h>
using namespace std;

#define long long int
bool cmp(int a,int b){
	return a>b;
}
int n,m;
int a[144],s[12][12];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int rs=a[0];
	sort(a,a+1+n*m,cmp);
	int p=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
				s[j][i] =a[p];
				if(a[p]==rs){
					if((i+1)%2==0){
						cout<<i+1<<' '<<n-j;
						return 0;
					}else{
						cout<<i+1<<' '<<j+1;
						return 0;						
					}     
				}
				p++;
				
			}   
		

		}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			cout<<s[j][i];
		cout<<endl;
	}
	}

	
	
	
	


