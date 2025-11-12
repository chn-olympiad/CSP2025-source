#include<bits/stdc++.h>
using namespace std;
struct city{
	int a;
	int b;
	int prize;
};
bool cmp(city a,city b){
	if(a.a!=b.b){
		return a.a<b.a;
	}else{
		return a.b<b.b;
	}
}
city arr[1000000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,count=0;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>arr[i].a>>arr[i].b>>arr[i].prize;
	}
	sort(arr,arr+m,cmp);
	for(int i=0,l=0;i<m;i++){
		if(arr[i].a>l&&arr[i].b==arr[i].a+1){
			l=arr[i].b;
			count+=arr[i].prize;
		}
	}
	cout<<count;
	return 0;
}

