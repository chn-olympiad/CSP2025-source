#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club1.in","r",stdin);
	freopen("club1.ans","w",stdout);
	int x[10001],y[10001],z[10001];
	int m=0;
	int a=0,b=0,c=0;
	int t;
	int num=0;
	cin>>t;
	int o[t];
	for(int j=0;j<t;j++){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x[i]>>y[i]>>z[i];
			if(x[i]>y[i]&&x[i]>z[i]){
				a++;
				num+=x[i];
			}else if(y[i]>x[i]&&y[i]>z[i]){
				b++;
				num+=y[i];
			}else if(z[i]>x[i]&&z[i]>y[i]){
				c++;
				num+=z[i];
			}
		}
		m=(a+b+c)/2;
		if(m>=a&&m>=b&&m>=c){
			o[j]=num;
		}else if(m<b){
			for(int f=0;f<b-m+1;f++){
				b--;
				if(x[f]>=z[f]){
					a++;
					num=num-y[f]+x[f];
					o[j]=num;
				}else{
					c++;
					num=num-y[f]+z[f];
					o[j]=num;
				}
			}
		}else if(m<c){
			for(int f=0;f<c-m+1;f++){
					c--;
				if(y[f]>x[f]){
					b++;
					num=num-z[f]+y[f];
					o[j]=num;
				}else{
					a++;
					num=num-z[f]+x[f];
					o[j]=num;
				}
			}
		}else{
			for(int f=0;f<a-m;f++){
				a--;
				if(y[f]>z[f]){
					b++;
					num=num-x[f]+y[f];
					o[j]=num;
				}else{
					c++;
					num=num-x[f]+z[f];
					o[j]=num;
				}
			}
		}
		num=0;
		a=0;
		b=0;
		c=0;
		m=0;
	}
for(int i=0;i<t;i++){
	cout<<o[i]<<endl;
}
return 0;	
}
