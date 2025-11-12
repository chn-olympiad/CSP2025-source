#include<bits/stdc++.h> 
using namespace std;
int t;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		int n=0;
		cin>>n;
		int num=0,ma=0;
		int a[n][3];
		for(int j=0;j<n;j++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			ma=max(a[i][0],max(a[i][1],a[i][2]));
			num+=ma;
		}
		cout<<num<<endl;
	}  
	return 0;
}
