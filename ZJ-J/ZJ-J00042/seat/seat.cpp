#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,ans;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=n*m-1;i>=1;i--){
		if(s>a[i]){
			ans=n*m-i;
			break;
		}
	}
	int hang=1,lie=1;
	for(int i=1;i<=ans;i++){
		if(lie%2==1){
			if(hang==n) lie++;
			else hang++;
		}
		else{
			if(hang==1) lie++;
			else hang--;
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
}