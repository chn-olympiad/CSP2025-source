#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	int c;
	if(b>a){
		c=b;
		b=a;
		a=c;
	}
}
int main(){
	freopen("number1.in","r",stdin);
	freopen("number1.out","w",stdout);
	int n,m,a,hang,lie;
	cin>>n>>m;
	vector<int> v;
	cin>>v[0];
	v[0]=a;
	for(int i=1;i<n*m;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=1;i<=n*m;i++){
		if(v[i]==a){
			if(i/n%2==0 && i>n){
				if(i%n!=0){
					lie=i/n+1;
					hang=i%n;
				} 
				else{
					lie=i/n;
					hang=1;
				} 
			}
			else if(i/n%2!=0 && i>n){
				if(i%n!=0){
					lie=i/n+1;
					hang=m-(i%n);
				}
				else{
					lie=i/n;
					hang=m;
				}
			}
			else if(i<n){
				lie=1;
				hang=i;
			}
		}
	}
	cout<<hang<<lie;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
