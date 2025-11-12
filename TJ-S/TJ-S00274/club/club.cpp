#include<bits/stdc++.h>
using namespace std;
int t;
struct s1{
	int a;
	int id;
};

struct s{
	s1 a[3];
}arr[100001];

bool cmd(s1 x,s1 y){
	return x.a>y.a;
}
bool cmd1(s x,s y){
	return x.a[0].a>y.a[0].a;
}

bool cmd2(s x,s y){
	return x.a[1].a>y.a[1].a;
}

bool cmd3(s x,s y){
	return x.a[2].a>y.a[2].a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int n;
for(;t;t--)
{
	cin>>n;
	int sumarr[3]={},sum=0,n1=n/2;
	for(int i=0;i<n;i++){
		cin>>arr[i].a[0].a>>arr[i].a[1].a>>arr[i].a[2].a;
		for(int j=0;j<3;j++)arr[i].a[j].id=j;
		sort(arr[i].a,arr[i].a+3,cmd);
	}
	sort(arr,arr+n,cmd1);
	int pop_sum=0;
	for(int i=0;i<n;i++){
		if(sumarr[arr[i].a[0].id]<n1){
			sum+=arr[i].a[0].a;
			sumarr[arr[i].a[0].id]++;
		}
		else{
			arr[pop_sum]=arr[i];
			pop_sum++;
		}
	}
	sort(arr,arr+pop_sum,cmd2);
	pop_sum=0;
	for(int i=0;i<pop_sum;i++){
		if(sumarr[arr[i].a[1].id]<n1){
			sum+=arr[i].a[1].a;
			sumarr[arr[i].a[1].id]++;
		}
		else{
			arr[pop_sum]=arr[i];
			pop_sum++;
		}
	}
	sort(arr,arr+pop_sum,cmd3);
	pop_sum=0;
	for(int i=0;i<pop_sum;i++){
		if(sumarr[arr[i].a[2].id]<n1){
			sum+=arr[i].a[2].a;
			sumarr[arr[i].a[2].id]++;
		}
		else{
			arr[pop_sum]=arr[i];
			pop_sum++;
		}
	}
	cout<<sum<<endl;
}	
	fclose(stdin);
	fclose(stdout);
return 0;
}

