#include<bits/stdc++.h>
using namespace std;
int n,t;
int bumen[100];
int num[100];
int duoyu1=0;
int duoyu2=0;
int main(){
	int sum[100];
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a=0;
	cin>>t;
	while(a<t){
		sum[a]=0;
		cin>>n;
		if(n%2!=0){
			cout<<"ÒªÊäÈëÅ¼Êý"; 
		}
		for(int i=0;i<n;i++){
		cin>>num[1];
		cin>>num[2];
		cin>>num[3];
		if(num[1]>num[2] && num[1]>num[3]){
			bumen[1]+=1;
			duoyu1=num[2];
			duoyu2=num[3];
		}else if(num[2]>num[1] && num[2]>num[3]){
			bumen[2]+=1;
			duoyu1=num[1];
			duoyu2=num[3];
		}else if(num[3]>num[1] && num[2]<num[3]){
			bumen[3]+=1;
			duoyu1=num[2];
			duoyu2=num[1];
		}
		if(num[1]<num[2]){
			num[1]=num[2];
		} else {
			if(num[3]>num[1]){  
			num[1]=num[3];
		}
		}
		if(bumen[1]>n/2 || bumen[2]>n/2 || bumen[3]>n/2){
			if(duoyu1>duoyu2){
				sum[a]+=duoyu1;
			}else if(duoyu1<duoyu2){
				sum[a]+=duoyu2; 
			}
		}else{
			sum[a]+=num[1];
		}
		}
		a++;
	}
	for(int k=0;k<t;k++){
		cout<<sum[k]<<endl;
	}
	return 0;
}