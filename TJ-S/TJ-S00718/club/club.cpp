#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,sum=0;
	cin >> t;
	int a[10005];
	int b[10005];
	int c[10005];
	int j;
	int p[10005];
	vector<int> t1(t);
	for(int i=0;i<t1.size();i++){
		cin >> t1[i];
		for(j=0;j<t1[i];j++){
			cin >> p[j] >> p[j+1] >> p[j+2];
			int c1=max(p[j],p[j+1]);
			int c2=max(p[j+1],p[j+2]);
			int m=max(c1,c2);
			
			if(m==p[j]){
				a[j]=p[j];
			}else if(m==p[j+1]){
				b[j]=p[j+1];
			}else{
				c[j]=p[j+2];
			}
			sum+=m;			
		}
	}	
	cout << sum;
	return 0;
} 
