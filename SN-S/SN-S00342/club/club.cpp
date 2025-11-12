#include<bits/stdc++.h>
using namespace std;
bool gg(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		int m,c=0;
		cin>>m;
		int a[m][3];
		int b[m];
		for (int j=0;j<m;j++){
			cin>>a[j][0]>>a[j][1]>>a[j][2];
		}
		for (int j=0;j<m;j++){
			b[j] = a[j][0];
		}
		sort(b,b+m,gg);
		for (int j=0;j<m/2;j++){
			c+=b[j];
		}
		cout<<c<<endl;
	}
	//评价：骗分代码（拿分低屎山型） 
	return 0;
}  
