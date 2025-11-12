#include<bits/stdc++.h>
using namespace std;
long long n,t,A,B,C,ans=0;
struct node{
	long long from,a,b,c;
}arr[120100];
long long maxx(node a){
	return max(max(a.a,a.b),a.c);
}
long long minx(node a){
	return min(min(a.a,a.b),a.c);
}
long long nx(node a){
	//long long aa[4];aa[1]=a.a;aa[2]=a.b;aa[3]=a.c;
	//sort(aa+1,aa+4);
	long long sum=a.a+a.b+a.c;
	return sum-maxx(a)-minx(a);
	//return aa[2];//红温了这个cs代码取中间值调了我一个小时 
}//我tm甚至没看出来错哪了 
bool cmp1(node a,node b){
	return maxx(a)>maxx(b);
}
bool cmp2(node a,node b){
	return maxx(a)-nx(a)<maxx(b)-nx(b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		A=0;B=0;C=0;ans=0;
		n=0;memset(arr,0,sizeof(arr));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i].a>>arr[i].b>>arr[i].c;
		}
		sort(arr+1,arr+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(arr[i].a==maxx(arr[i])){
				A++;arr[i].from=1;
				ans+=arr[i].a;
			}
			else if(arr[i].b==maxx(arr[i])){
				B++;arr[i].from=2;
				ans+=arr[i].b;
			}
			else{
				C++;arr[i].from=3;
				ans+=arr[i].c;
			}
		}
		if(A<=n/2&&B<=n/2&&C<=n/2){
			cout<<ans<<endl;
			continue;
		}
		sort(arr+1,arr+1+n,cmp2);
		if(A>n/2){
			int idx=1;
			while(A>n/2&&idx<=n){
				if(arr[idx].from==1){
					if(arr[idx].b==nx(arr[idx])){
						arr[idx].from=2;
						ans-=arr[idx].a;
						ans+=arr[idx].b;
						B++;
					}
					else{
						arr[idx].from=3;
						ans-=arr[idx].a;
						ans+=arr[idx].c;
						C++;
					}
					A--;
				}
				idx++;
			}
		}
		else if(B>n/2){
			int idx=1;
			while(B>n/2&&idx<=n){
				if(arr[idx].from==2){
					if(arr[idx].a==nx(arr[idx])){
						arr[idx].from=1;
						ans-=arr[idx].b;
						ans+=arr[idx].a;
						A++;
					}
					else{
						arr[idx].from=3;
						ans-=arr[idx].b;
						ans+=arr[idx].c;
						C++;
					}
					B--;
				}
				idx++;
			}
		}
		else if(C>n/2){
			int idx=1;
			while(C>n/2&&idx<=n){
				if(arr[idx].from==3){
					if(arr[idx].a==nx(arr[idx])){
						arr[idx].from=1;
						ans-=arr[idx].c;
						ans+=arr[idx].a;
						A++;
					}
					else{
						arr[idx].from=2;
						ans-=arr[idx].c;
						ans+=arr[idx].b;
						B++;
					}
					C--;
				}
				idx++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
