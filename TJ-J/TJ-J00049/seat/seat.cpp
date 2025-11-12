#include<bits/stdc++.h>
using namespace std;
int a[10003];
int b[103][103];
bool d(int a,int b){
	if(a>b){
		return true;
	}else{
		return false;
	}
}
int main(){
	int m,n;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int as;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	as=a[1];
	sort(a+1,a+1+n*m,d);
	for(int i=1;i<=m*n;i++){
//	cout<<a[i]<<endl;
	}
	int n_=1,m_=1;
	int t=0;
	
	for(int i=1;i<=n*m;i++){
//		if(m_+1>m&&m_-1<1&&n_+1>n){
//			break;
//		}
		b[n_][m_]=a[i];
		
//	cout<<"!"<<a[i]<<" "<<n_<<" "<<m_<<endl;
		if(n_==n&&t==0){
			t=1;
			m_++;
		
			continue;
		}else if(n_==1&&t==1){
			
			t=0;
			m_++;
			continue;
		} 
		if(t==0){
			n_++;
		}else if(t==1){
			n_--;
		}
	
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<b[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(as==b[i][j]){
				cout<<i<<" "<<j;
			}
		}
		cout<<endl;
	}
	return 0;
}
