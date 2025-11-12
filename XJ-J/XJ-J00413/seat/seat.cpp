#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int q=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			int e=i;
			int w=n;
			int num=1;
			while(i>w){
				i-=w;
				num++;
			}
			if(num%2==0){
				cout<<num<<" "<<(num*m-e)+1;
			}else{
				cout<<num<<" "<<e-((num-1)*m);
			}
			
			return 0;
		}
	}
	return 0;
} 
