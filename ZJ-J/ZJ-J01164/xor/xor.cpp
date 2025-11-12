#include<bits/stdc++.h>
using namespace std;
int const N=5e5+5;
struct node{
	int x,y;
}arr[N];
int n,k,a[N];
int r,id,ans,sum,cnt;
bool cmp(node p,node q){
	if(p.x!=q.x) return p.x<q.x;
	else return p.y<q.y;
}
void not_true(){
	for(int i=1;i<=n;i++){
		while(sum<k && r<=n){
			sum^=a[r];
			r++;
		}
		if(sum==k && r-1<=n){
			arr[++cnt].x=i;
			arr[cnt].y=r-1;
		} 
		sum^=a[i];
	}
	sort(arr+1,arr+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(arr[i].x==-1 || arr[i].y==-1) continue;
		id=i+1;
		while(arr[i].x==arr[id].x && id<=cnt){
			id++;
		}
		if(id!=i+1){
			for(int j=i+1;j<id;j++){
				arr[j].x=-1;
			}
		}
		id=i+1;
		while(arr[i].y==arr[id].y && id<=cnt){
			id++;
		}
		if(id!=i+1){
			for(int j=i+1;j<id;j++){
				arr[j].y=-1;
			}
		}
		id=i+1; 
		while(((arr[i].y>=arr[id].y && arr[i].x<=arr[id].x) || arr[i].y>=arr[id].x) && id<=cnt){
			id++;
		}
		if(id!=i+1){
			for(int j=i+1;j<id;j++){
				arr[j].y=-1;
			}
		}
		ans++;
	}
	cout<<ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=false;
	}
	if(flag){//È«ÊÇ1 
		cout<<n/2;
	}else{
		not_true();
	}
	return 0;
}
