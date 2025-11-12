#include<bits/stdc++.h>
using namespace std;
int s[105];
int a[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
//	freopen("seat");
//	freoin("seat.in",in);
	int n,m,a1,cnt=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>s[i];
		cnt++;
	}
	a1=s[0];
	sort(s,s+cnt,cmp); 
	int c,r=0;
	cnt=0;
	for(int i=0;i<n;i++){
		if((i+1)%2==1){
			for(int j=0;j<m;j++){
				a[i][j]=s[cnt];
				if(s[cnt]==a1){
					c=i;r=j;
					break;
				}
				cnt++;
			}
		}
		else{
			for(int j=m-1;j>=0;j--){
				a[i][j]=s[cnt];
				if(s[cnt]==a1){
					c=i;r=j;
					break;
				}
				cnt++;
			}
		}
		
	}
	cout<<c+1<<" "<<r+1;
	return 0;
}
