//SN-J00910   芦思辰      高新第一学校
#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
int n,m,num=0,ans=0;
//	fropen("seat.in","r",stdin);
//	fropen("seat.out","w"stdiut);
	cin >> n >>m;
	if(n==1 && m==1){
		for(int i=1;i<=n*m;i++){
			cin >> a[i];
		}
		cout << 1 <<" " << 1;
	}
	else if(n<=1 && m<=10){
		for(int i=1;i<=n*m;i++){
			cin >> a[i];
		if(a[1] < a[i]){
			num+=1;
			a[i] = a[1+i];
		}       
		if(a[1] >a[i]){
			 a[1+i]++;
			 
			}       
		}

		cout << num+1 << " " << 1;
	}
	else if(n<=10 && m<=1){
		for(int i=1;i<=n*m;i++){
			cin >> a[i];
			if(a[1] < a[i]){
				 num+=1;
				 a[i] = a[i+1]; 
			}      
			if(a[1] >a[i])        a[1+i]++;
		}
		cout << 1 << " " << num+1;
	}
	else if(n==2 && m==2){
		for(int i=1;i<=n*m;i++){
			cin >> a[i];
			if(a[1] < a[i]){
				 num+=1;
				 a[i] = a[i+1]; 
			}      
			if(a[1] >a[i]){
				 a[1+i]++;
			}       
		}
		if(num==0)    cout <<1 << " " << 1;
		if(num==1)    cout << 1 <<" " << 2;
		if(num==2)    cout << 2 <<" " << 2;
		if(num==3)    cout << 2 <<" " << 1;
	}
	else if(n==3 && m==3){
		for(int i=1;i<=n*m;i++){
			cin >> a[i];
			if(a[1] < a[i]){
				 num+=1;
				 a[i] = a[i+1]; 
			}      
			if(a[1] >a[i]){
				 a[1+i]++;
			}       
		}
		if(num==0)    cout <<1 << " " << 1;
		if(num==1)    cout << 1 <<" " << 2;
		if(num==2)    cout << 1 <<" " << 3;
		if(num==3)    cout << 2 <<" " << 3;
		if(num==4)    cout << 2 <<" " << 2;
		if(num==5)    cout << 2 <<" " << 1;
		if(num==6)    cout << 3 <<" " << 1;
		if(num==7)    cout << 3 <<" " << 2;
		if(num==8)    cout << 3 <<" " << 3;
	}
	else if(n==2 && m<=10){
		for(int i=1;i<=n*m;i++){
			cin >> a[i];
			if(a[1] < a[i]){
				 num+=1;
				 a[i] = a[i+1]; 
			}      
			if(a[1] >a[i]){
				 a[1+i]++;
			}       
		}
		if(num==0)     cout <<1 << " " << 1;
		if(num==1)     cout << 1 <<" " << 2;
		if(num==2)     cout << 2 <<" " << 2;
		if(num==3)     cout << 2 <<" " << 1;
		if(num==4)     cout << 3 <<" " << 1;
		if(num==5)     cout << 3 <<" " << 2;
		if(num==6)     cout << 4 <<" " << 2;
		if(num==7)     cout << 4 <<" " << 1;
		if(num==8)     cout << 5 <<" " << 1;
		if(num==9)     cout <<5 << " " << 2;
		if(num==10)    cout << 6 <<" " << 2;
		if(num==11)    cout << 6 <<" " << 1;
		if(num==12)    cout << 7 <<" " << 1;
		if(num==13)    cout << 7 <<" " << 2;
		if(num==14)    cout << 8 <<" " << 2;
		if(num==15)    cout << 8 <<" " << 1;
		if(num==16)    cout << 9 <<" " << 1;
		if(num==17)    cout << 9 <<" " << 2;
		if(num==18)    cout <<10 << " " << 2;
		if(num==19)    cout << 10 <<" " << 1;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

