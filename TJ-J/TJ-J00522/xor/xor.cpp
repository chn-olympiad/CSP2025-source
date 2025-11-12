#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1e7+1314;
long long k,cnt=1,sum;
int a[N];
struct node{
	int x,y;
	int w;
}t[N]; 
int amns(int l,int r){
	if(r>n) return 0;
	int o=a[l];
	for(int i=l+1;i<=r;i++){
		o=(o^a[i]);
	}
	int f=0;
	if(o==k){
		if(l==t[cnt-1].x){
			if(r-l<t[cnt-1].w){
				t[cnt-1].x=l;
				t[cnt-1].y=r;
			}
		}else if(r==t[cnt-1].y){
			if(r-l<t[cnt-1].w){
				t[cnt-1].x=l;
				t[cnt-1].y=r;
			}			
		}else if((l>t[cnt-1].x&&l<t[cnt-1].y)||(r>t[cnt-1].x&&r<t[cnt-1].y)){
			if(r-l<t[cnt-1].w){
				t[cnt-1].x=l;
				t[cnt-1].y=r;
			}
		}else{
			t[cnt].x=l;
			t[cnt].y=r;
			t[cnt].w=r-l;
			cnt++;	
		}
	}
	amns(l,r+1);
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		amns(i,i);
	}
	cout<<cnt-1;
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
