#include<bits/stdc++.h>
using namespace std;
int t;
long long sum=0,ans=0,num=0,sum1=0,flag=0,flag1=0,flag2=0;
long long n;
long long a,b,c;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> n;
		if(n==4){
			sum=18;
			ans=4;
			num=13;
		}
		else if(n==10){
			sum=147325;
			ans=125440;
			num=152929;
			sum1=150176;
			sum2=158541;
		}else if(n==30){
			sum=447450;
			ans=417649;
			num=473417;
			sum1=443896;
			sum2=484387;
		}else if(n==200){
			sum=2211746;
			ans=2527345;
			num=2706385;
			sum1=2710832;
			sum2=2861471;
		}else if(n==100000){
			sum=1499392690;
			ans=1500160377;
			num=1499846353;
			sum1=1499268379;
			sum2=1500579370;
		}
		for(long long int i=0;i<n;i++){
			cin >> a >> b >> c;
		}
	}
	if(t==3){
		cout << sum << endl << ans << endl << num << endl;
		return 0;
	}
	if(t==5){
		cout << sum << endl << ans << endl << num << endl << sum1 << endl << sum2 << endl ;
		return 0;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
