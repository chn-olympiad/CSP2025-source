#include<bits/stdc++.h>
using namespace std;
int m[10];
int main(){
	int t,n,i=1,j,a,b,c,d,e,f;
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>n;
		for(j=1;j<=n;j++){
			cin>>a>>b>>c;
			if(a>b||a>c){
				d++;
				if(d>n/2){
					d--;
					e++;
					m[j]=m[j]+d;
				}
				else if(e>n/2){
					e--;
					f++;
					m[j]=m[j]+c;
				}
				else
				m[j]=m[j]+a;
			}
			else if(b>a||b>c){
				e++;
				if(e>n/2){
					e--;
					f++;
					m[j]=m[j]+c;
				}
				else if(f>n/2){
					f--;
					d++;
					m[j]=m[j]+a;
				}
				else
				m[j]=m[j]+b;
			}
			else if(c>a||c>b){
				f++;
				if(f>n/2){
					f--;
					d++;
					m[j]=m[j]+a;
				}
				else if(d>n/2){
					d--;
					e++;
					m[j]=m[j]+b;
				}
				else
				m[j]=m[j]+c;
			}
		}
		cout<<m[j]<<endl;
	}
	return 0;
}
