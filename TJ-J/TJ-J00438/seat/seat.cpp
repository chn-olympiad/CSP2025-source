#include<bits/stdc++.h>
using namespace std;
long long int n,m;
long long int num,pm,lie;
long long int fs;
	long long int a[1000000];
	long long int dx[1000000]; 
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long int w=0;
	cin>>n>>m;
	num=n*m;
		
	 for(int i=0;i<num;i++){
	 	cin>>fs;
	 	a[i]=fs;
	 }
	 w=a[0];
	sort(a,a+num);
	for(int i=0;i<num;i++){
		dx[i]=a[num-i-1];
	}
	for(int i=0;i<num;i++){
		if(w!=dx[i]){
			pm+=1;
		}else{
			pm+=1;
			break;
		}
	}
	
	if(pm%n==0){
		cout<<pm/n<<" ";
		lie=pm/n;
	}else{
		cout<<(pm/n)+1<<" ";
		lie=(pm/n)+1;
	}
	
	if(pm%n==0 && (pm/n)%2==0){
		cout<<1;
	}else if(pm%n==0 && (pm/n)%2==1){
		cout<<n;
	}else if((pm/n)%n!=0 && lie%2==0){
		cout<<n-(pm%n)+1;
	}else{
		cout<<pm%n;
	}
	
	
	fclose(stdin);
	fclose(stdout);	
	return 0;
} 
