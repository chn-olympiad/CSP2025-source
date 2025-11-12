#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int t;
int n;
int a[100005][4];
int q1[200005],q2[200005],q3[200005];
int o1,o2,o3;
void swap1(int d1,int d2){
	int qq=q1[d1];
	q1[d1]=q1[d2],q1[d2]=qq;
}
void push1(int d){
	if(d>1&&q1[d]<q1[d/2])swap1(d,d/2),push1(d/2);
}
void add1(int x){
	q1[++o1]=x;
	push1(o1);
}
void push11(int d){
	if(d*2<=o1){
		if(d*2+1<=o1){
			if(q1[d*2]<q1[d*2+1])swap1(d,d*2),push11(d*2);
			else swap1(d,d*2+1),push11(d*2+1);
		}else{
			swap1(d,d*2);
			o1--;
		}
	}else{
		if(d!=o1){
			swap1(d,o1);
			push1(d);
		}
		o1--;
	}
}
void swap2(int d1,int d2){
	int qq=q2[d1];
	q2[d1]=q2[d2],q2[d2]=qq;
}
void push2(int d){
	if(d>1&&q2[d]<q2[d/2])swap2(d,d/2),push2(d/2);
}
void add2(int x){
	q2[++o2]=x;
	push2(o2);
}
void push22(int d){
	if(d*2<=o2){
		if(d*2+1<=o2){
			if(q2[d*2]<q2[d*2+1])swap2(d,d*2),push22(d*2);
			else swap2(d,d*2+1),push22(d*2+1);
		}else{
			swap2(d,d*2);
			o2--;
		}
	}else{
		if(d!=o2){
			swap2(d,o2);
			push2(d);
		}
		o2--;
	}
}
void swap3(int d1,int d2){
	int qq=q3[d1];
	q3[d1]=q3[d2],q3[d2]=qq;
}
void push3(int d){
	if(d>1&&q3[d]<q3[d/2])swap3(d,d/2),push3(d/2);
}
void add3(int x){
	q3[++o3]=x;
	push3(o3);
}
void push33(int d){
	if(d*2<=o3){
		if(d*2+1<=o3){
			if(q3[d*2]<q3[d*2+1])swap3(d,d*2),push33(d*2);
			else swap3(d,d*2+1),push33(d*2+1);
		}else{
			swap3(d,d*2);
			o3--;
		}
	}else{
		if(d!=o3){
			swap3(d,o3);
			push3(d);
		}
		o3--;
	}
}
int l1,l2,l3;
long long ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		o1=0,o2=0,o3=0;
		l1=0,l2=0,l3=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)cin>>a[i][j];
		}
		for(int i=1;i<=n;i++){
			int mx=0,d=0;
			for(int j=1;j<=3;j++){
				if(a[i][j]>mx)mx=a[i][j],d=j;
			}
			if(d==1){
				if(l1<n/2)add1(mx-max(a[i][2],a[i][3])),ans+=mx,l1++;
				else{
					if(mx-max(a[i][2],a[i][3])>q1[1]){
						ans-=q1[1];
						ans+=mx;
						push11(1);
						add1(mx-max(a[i][2],a[i][3]));
					}else{
						ans+=max(a[i][2],a[i][3]);
					}
				}
				//cout<<ans<<endl;
			}
			if(d==2){
				if(l2<n/2)add2(mx-max(a[i][1],a[i][3])),ans+=mx,l2++;
				else{
					if(mx-max(a[i][1],a[i][3])>q2[1]){
						ans-=q2[1];
						ans+=mx;
						push22(1);
						add2(mx-max(a[i][1],a[i][3]));
					}else{
						ans+=max(a[i][1],a[i][3]);
					}
				}
				//cout<<ans<<endl;
			}
			if(d==3){
				if(l3<n/2)add3(mx-max(a[i][1],a[i][2])),ans+=mx,l3++;
				else{
					if(mx-max(a[i][1],a[i][2])>q3[1]){
						ans-=q3[1];
						ans+=mx;
						push33(1);
						add3(mx-max(a[i][1],a[i][2]));
					}else{
						ans+=max(a[i][1],a[i][2]);
					}
				}
				//cout<<ans<<endl;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
