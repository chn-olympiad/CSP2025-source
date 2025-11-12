#include<bits/stdc++.h> 
using namespace std;
bool cmp(int x,int y){
	if(x>y){
		return x>y;
	}
}
int a,b,p;
int n[1008],s,sum;
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin>>a>>b;
	for(int i=1;i<=a*b;i++){
		cin>>n[i];
	}
	p=n[1];
	s=a*b;
	sort(n+1,n+s+1,cmp);
	for(int i=1;i<=s;i++){
		sum++;
		if(n[i]==p){
			break;
		}
	}
	int m=0,n=0,m1=0;
	m=sum/a;//确定列数 
	n=sum%a;//确定行数 
	m1=m%a;		
	if(m%2!=0){
		cout<<n<<' '<<m1;
	} 
	else{
		cout<<n<<' '<<a-m1;
	}
	
	
	return 0;
} 
