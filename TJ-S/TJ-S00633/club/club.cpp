#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct node{
	long long a,b,c,id;
}arr[100005],brr[100005];
bool cmp(node a,node b){
	if((a.a-a.b)==(b.a-b.b)) return a.b>b.b;
	return (a.a-a.b)<(b.a-b.b);
}
bool cmp2(node a,node b){
	if((a.a-a.c)==(b.a-b.c)) return a.c>b.c;
	return (a.a-a.c)<(b.a-b.c);
}
bool cmp3(node a,node b){
	if((a.b-a.c)==(b.b-b.c)) return a.c>b.c;
	return (a.b-a.c)<(b.b-b.c);
}
bool cmp4(node a,node b){
	if((a.b-a.a)==(b.b-b.a)) return a.a>b.a;
	return (a.b-a.a)<(b.b-b.a);
}
long long am,bm,cm,cnt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		am=n;
		bm=0;
		cm=0;
		cnt=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i].a>>arr[i].b>>arr[i].c;
			arr[i].id=1;
		}
		sort(arr+1,arr+n+1,cmp);
		for(int i=1;i<=n && bm<(n/2);i++){
			if((arr[i].c-arr[i].b)<0){
				bm++;
				am--;
				arr[i].id=2;
			}
		}
		sort(arr+1,arr+n+1,cmp2);
		for(int i=1;i<=n && cm<(n/2);i++){
			if((arr[i].a-arr[i].c<0) && arr[i].id==1){
				cm++;
				am--;
				arr[i].id=3;
			}
		}
		sort(arr+1,arr+n+1,cmp4);
		for(int i=1;i<=n && am<(n/2);i++){
			if((arr[i].b-arr[i].a<0) && arr[i].id==2){
				am++;
				bm--;
				arr[i].id=1;
			}
		}
		sort(arr+1,arr+n+1,cmp3);
		for(int i=1;i<=n && cm<(n/2);i++){
			if((arr[i].b-arr[i].c<0) && arr[i].id==2){
				cm++;
				bm--;
				arr[i].id=3;
			}
		}

		for(int i=1;i<=n;i++){
			int idx=arr[i].id;
			if(idx==1) cnt+=arr[i].a;
			if(idx==2) cnt+=arr[i].b;
			if(idx==3) cnt+=arr[i].c;
		}
		cout<<cnt<<endl;
	}
}
