#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;

struct node{
	int a,b,c;
};

node arr2[maxn];

node arr[maxn];

int t,n;
int ww1,ww2;
int a,b,c;

bool check(node a,node b){
	return a.a > b.a;
}

bool check2(node a,node b){
	return a.a-a.b > b.a-b.b;
}

int aa(int i){
	if(arr[i].a > max(arr[i].b,arr[i].c)){
		return 0;
	}
	if(arr[i].b > max(arr[i].a,arr[i].c)){
		return 1;
	}
	if(arr[i].c > max(arr[i].a,arr[i].b)){
		return 2;
	}
	return -1;
}

int bb(int i){
	if(arr[i].a > max(arr[i].b,arr[i].c)){
		return max(arr[i].b,arr[i].c);
	}
	if(arr[i].b > max(arr[i].a,arr[i].c)){
		return max(arr[i].a,arr[i].c);
	}
	if(arr[i].c > max(arr[i].a,arr[i].b)){
		return max(arr[i].a,arr[i].b);
	}
	return max(arr[i].a,arr[i].c);
}

int www(node a){
	if(a.a > max(a.b,a.c)){
		return max(a.b,a.c);
	}
	if(a.b > max(a.a,a.c)){
		return max(a.a,a.c);
	}
	if(a.c > max(a.a,a.b)){
		return max(a.a,a.b);
	}
	return max(a.a,a.c);
}

bool check3(node a,node b){
	return max(a.a,max(a.b,a.c))-www(a) > max(b.a,max(b.b,b.c))-www(b);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		bool flag=1,flag2=1;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].c);
			if(!(arr[i].b == 0 && arr[i].c == 0)){
				flag=0;
			}
			if(arr[i].c != 0){
				flag2=0;
			}
			arr2[i].a=arr[i].a,arr2[i].b=arr[i].b,arr2[i].c=arr[i].c;
		}
		if(n==2){
			if(aa(0) == aa(1) && aa(1)!=-1){
				cout<<max(max(arr[0].c,max(arr[0].a,arr[0].b))+bb(1),max(arr[1].c,max(arr[1].a,arr[1].b))+bb(0))<<endl;
			}else{
				cout<<max(arr[0].c,max(arr[0].a,arr[0].b))+max(arr[1].c,max(arr[1].a,arr[1].b))<<endl;
			}
		}else{
			if(flag){
				sort(arr,arr+n,check);
				long long ans=0;
				for(int i=0;i<n/2;i++){
					ans+=arr[i].a;
				}
				printf("%d\n",ans);
			}else if(flag2){
				sort(arr,arr+n,check2);
				long long ans=0;
				for(int i=0;i<n/2;i++){
					ans+=arr[i].a;
				}
				for(int j=n/2;j<n;j++){
					ans+=arr[j].b;
				}
				printf("%lld\n",ans);
			}else{
				sort(arr,arr+n,check3);
				int cnt[3]={0,0,0};
				long long ans=0;
				for(int i=0;i<n;i++){
					a=arr[i].a,b=arr[i].b,c=arr[i].c;
					if(a >= b && a >= c){
						ww1=0;
						if(b>=c){
							ww2=1;
						}else{
							ww2=2;
						}
					}else if(b >=a && b >= c){
						ww1=1;
						if(a>=c){
							ww2=0;
						}else{
							ww2=2;
						}
					}else if(c >= a && c >= b){
						ww1=2;
						if(a>=b){
							ww2=0;
						}else{
							ww2=1;
						}
					}
					if(cnt[ww1] == n/2){
						cnt[ww2]++;
						ans+=www(arr[i]);
					}else{
						ans+=max(arr[i].a,max(arr[i].b,arr[i].c));
						cnt[ww1]++;
					}
				}
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
