#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,s1,s2,s3;
}arr[100001];
int t,n,p,q,r,ans;
bool cmp(node x,node y){
	return x.s1<y.s1 or x.s1==y.s1&&x.a-x.b<y.a-y.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		p=0,q=0,r=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i].a>>arr[i].b>>arr[i].c;
			arr[i].s1=1,arr[i].s2=2,arr[i].s3=3;
			if(arr[i].a<arr[i].b){
				swap(arr[i].a,arr[i].b);
				swap(arr[i].s1,arr[i].s2);
			}if(arr[i].a<arr[i].c){
				swap(arr[i].a,arr[i].c);
				swap(arr[i].s1,arr[i].s3);
			}if(arr[i].b<arr[i].c){
				swap(arr[i].b,arr[i].c);
				swap(arr[i].s2,arr[i].s3);
			}
		}
		sort(arr+1,arr+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(arr[i].s1==1)p++;
			else if(arr[i].s1==2)q++;
			else if(arr[i].s1==3)r++;
			ans+=arr[i].a;
		}
		if(p>n/2){
			for(int i=1;i<1+p-n/2;i++)ans=ans-arr[i].a+arr[i].b;
		}else if(q>n/2){
			for(int i=p+1;i<1+p+q-n/2;i++)ans=ans-arr[i].a+arr[i].b;
		}else if(r>n/2){
			for(int i=p+q+1;i<1+n/2;i++)ans=ans-arr[i].a+arr[i].b;
		}
		cout<<ans<<endl;
	}
	return 0;
}
