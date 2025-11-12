#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,num1=0,num2=0,num3=0;
	cin>>t;
	int long long a[128][3][t],b=0,answer[t];
	int long long one,two,three;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			for(int z=0;z<3;z++)
				cin>>a[j][z][i];
		}
	}
	for(int i=0;i<t;i++){
		for(int j=0;j<n;j++){
		
			//1
			if(num1<n/2 and a[j][0][i]>a[j][1][i] and a[j][0][i]>a[j][2][i]){
				one+=a[j][0][i];num1+=1;
			}
			else if(num1>n/2 and num2<n/2 and a[j][1][i]>a[j][2][i]){
				two+=a[j][1][i];num2+=1;
			} 
			else if(num1>n/2 and num3<n/2 and a[j][1][i]<a[j][2][i]){
				three+=a[j][2][i];num3+=1;
			} 
			//2
			if (num2<n/2 and a[j][0][i]<a[j][1][i] and a[j][1][i]>a[j][2][i]){
				two+=a[j][1][i];num2+=1;
			}
			else if(num2>n/2 and num3<n/2 and a[j][2][i]>a[j][0][i]) {
				three+=a[j][2][i];num3+=1;
			}
			else if(num2>n/2 and num1<n/2 and a[j][2][i]<a[j][0][i]) {
				one+=a[j][0][i];num1+=1;
			}
			//3
			if (num3<n/2 and a[j][0][i]<a[j][2][i] and a[j][2][i]>a[j][1][i]) {
				three+=a[j][2][i];num3+=1;
			}
			else if(num3>n/2 and num1<n/2 and a[j][1][i]<a[j][0][i]){
				one+=a[j][0][i];num1+=1;
			} 
			else if(num3>n/2 and num2<n/2 and a[j][0][i]<a[j][1][i]) {
				two+=a[j][1][i];num2+=1;
			}
			
		}
		b = b+one+two+three;
		
		answer[i] = b;
		one=0;
		two=0;
		three=0;
		b=0;
		num1=0;
		num2=0;
		num3=0;
	}
	for(int i=0;i<t;i++) cout<<answer[i]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
