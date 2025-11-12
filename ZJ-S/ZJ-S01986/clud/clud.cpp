#include<bits/stdc++.h>
using namespace std;
int t,n,x,y,z,f1,f0,sum,mx;
struct manyi{
	int a,b,c;
}arr[100010];
bool xx(manyi a,manyi b){
	return a.a>b.b;
}
bool xxx(manyi a,manyi b){
	return abs(a.a-a.b)>abs(b.a-b.b);
}
void ok1(){
	sort(arr,arr+n,xx);
	for(int i=0;i<n/2;i++){
		sum+=arr[i].a;
	}cout<<sum<<'\n';
	return;
}
void ok2(){
	sort(arr,arr+n,xxx);
	for(int i=0;i<n;i++){
		if(arr[i].a>=arr[i].b&&x<n/2||arr[i].a<arr[i].b&&y>=n/2){
			x++;
			sum+=arr[i].a;
		}else{
			y++;
			sum+=arr[i].b;
		}
	}
	cout<<sum;
	return;
}
void dfs(int s,int k){
	if(k==n){
		mx=max(mx,s);
		return;
	}
	if(x<n/2){
		x++;
		dfs(s+arr[k].a,k+1);
		x--;
	}
	if(y<n/2){
		y++;
		dfs(s+arr[k].b,k+1);
		y--;
	}
	if(z<n/2){
		z++;
		dfs(s+arr[k].c,k+1);
		z--;
	}
}
int main(){
	freopen("clud.in","r",stdin);
	freopen("clud.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0,f0=0,f1=0;
		x=0,y=0,z=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i].a>>arr[i].b>>arr[i].c;
			if(arr[i].b||arr[i].c){
				f0=1;
			}if(arr[i].c){
				f1=1;
			}
		}
		if(f0==0){
			ok1();
		}else if(f1==0){
			ok2();
		}else{
			dfs(0,0);
			cout<<mx;
		}
	}
}	
