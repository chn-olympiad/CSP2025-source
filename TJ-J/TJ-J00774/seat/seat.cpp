#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[101]={};
	for(int i=0;i<n*m;i++)
		cin>>s[i];
	int a1=s[0];
	int num=0;
	for(int i=1;i<n*m;i++){
		if(a1<s[i])
			num++;
	}
	int l=1,r=1;
	while(num!=0){
		if(l%2==1){
			if(m-r!=0){
				num--;
				r++;
			}
			else{
				num--;
				l++;
			}
		}
		else if(l%2==0){
			if(m-r!=m-1){
				num--;
				r--;
			}
			else{
				num--;
				l++;
			}
		}	
	}
	cout<<l<<' '<<r;
	return 0;
}
