#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
int t,n,sum,sum1,sum2,sum3,cnt1,cnt2,cnt3,maxm,t1,t2,t3;
bool x111,x222;
struct noip{
	int a;
	int b;
	int c;
}m[M];
bool cmp1(noip x,noip y){
	if(x.a==y.a){
		if(x.b==y.b){
			return x.c<=y.c;
		}
		return x.b<y.b;
	}
	return x.a>y.a;
}
bool cmp2(noip x,noip y){
	if(x.b==y.b){
		if(x.c==y.c){
			return x.a<=y.a;
		}
		return x.c<y.c;
	}
	return x.b>y.b;
}
bool cmp3(noip x,noip y){
	if(x.c==y.c){
		if(x.b==y.b){
			return x.a<=y.a;
		}
		return x.b<y.b;
	}
	return x.c>y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();
	cin>>t;
	while(t--){
		t1=0;
		t2=0;
		t3=0;
		sum=0;
		maxm=0;
		sum1=0;
		sum2=0;
		sum3=0;
		cnt1=0;
		cnt2=0;
		cnt3=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
			if(m[i].b!=0){
				x111=true;
			}
			if(m[i].c!=0){
				x222=true;
			}
		}
		if(x111==false){
			sort(m,m+n,cmp1);
			for(int i=0;i<n/2;i++){
				sum1+=m[i].a;
			}
			cout<<sum1<<endl;
			continue;
		}
		if(x222==false){
		for(int i=0;i<n;i++){
			if(m[i].a>m[i].b&&t1<(n/2)&&m[i].a>m[i].c){
				sum+=m[i].a;
				t1++;
			}
			if(m[i].b>m[i].a&&t2<(n/2)&&m[i].b>m[i].c){
				sum+=m[i].b;
				t2++;
			}
		}
		cout<<sum<<endl;
			continue;
		} 
		sort(m,m+n,cmp1);
		for(int i=0;i<n/2;i++){
			sum1+=m[i].a;
		}
		for(int i=n/2;i<n;i++){
			cnt1+=m[i].a;
		}
		sort(m,m+n,cmp2);
		for(int i=0;i<n/2;i++){
			sum2+=m[i].b;
		}
		for(int i=n/2;i<n;i++){
			cnt2+=m[i].b;
		}
		sort(m,m+n,cmp3);
		for(int i=0;i<n/2;i++){
			sum3+=m[i].c;
		} 
		for(int i=n/2;i<n;i++){
			cnt3+=m[i].c;
		}
		sort(m,m+n,cmp1);
		for(int i=n/2;i<n;i++){
			sum+=max(m[i].b,m[i].c);
		}
		sum+=sum1;
		maxm=max(maxm,sum);
		sum=0;
		sort(m,m+n,cmp3);
		for(int i=n/2;i<n;i++){
			sum+=max(m[i].b,m[i].a);
		}
		sum+=sum3;
		maxm=max(maxm,sum);
		sum=0;
		sort(m,m+n,cmp2);
		for(int i=n/2;i<n;i++){
			sum+=max(m[i].a,m[i].c);
		}
		sum+=sum2;
		maxm=max(maxm,sum);
		sum=0;
		for(int i=0;i<n/2;i++){
			sum+=max(m[i].a,m[i].b);
		} 
		sum+=cnt3;
		maxm=max(maxm,sum);
		sum=0;
		for(int i=0;i<n/2;i++){
			sum+=max(m[i].a,m[i].c);
		} 
		sum+=cnt2;
		maxm=max(maxm,sum);
		sum=0;
		for(int i=0;i<n/2;i++){
			sum+=max(m[i].c,m[i].b);
		} 
		sum+=cnt1;
		maxm=max(maxm,sum);
		sum=0;
		for(int i=0;i<n;i++){
			if(m[i].a>m[i].b&&t1<(n/2)&&m[i].a>m[i].c){
				sum+=m[i].a;
				t1++;
			}
			if(m[i].c>m[i].b&&t3<(n/2)&&m[i].c>m[i].a){
				sum+=m[i].c;
				t3++;
			}
			if(m[i].b>m[i].a&&t2<(n/2)&&m[i].b>m[i].c){
				sum+=m[i].b;
				t2++;
			}
		}
		maxm=max(maxm,sum);
		cout<<maxm<<endl;
	}
	return 0;
}
