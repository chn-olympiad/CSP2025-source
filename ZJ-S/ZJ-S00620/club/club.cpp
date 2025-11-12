#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n;
struct p{
	int a1,a2,a3;
}a[N];
bool cmp1(int x,int y){
	return a[x].a1<a[y].a1;
}bool cmp2(int x,int y){
	return a[x].a2<a[y].a2;
}bool cmp3(int x,int y){
	return a[x].a3<a[y].a3;
}
int sum=0;
void f(vector <int> d1,vector <int> d2,vector <int> d3){
//	printf("222\n");
	int l1=d1.size(),l2=d2.size(),l3=d3.size();
	int l=0;
//	printf("n/2.%d\n",n/2);
//	if(l1<2) printf("l1.%d  555\n",l1);
	while(l1>n/2){
//		printf("l1.%d\n",l1);
		if(a[d1[l]].a2>a[d1[l]].a3){
			d2.push_back(d1[l++]);
			l2++;
		}else{
			d3.push_back(d1[l++]);
			l3++;
		}
		l1--;
	}
//	printf("444\n");
	for(int i=l;i<l1;i++){
//		printf("%d ",a[d1[i]].a1);
		sum+=a[d1[i]].a1;
	}
//	cout<<endl;
	for(int i=0;i<l2;i++){
//		printf("%d ",a[d2[i]].a2);
		sum+=a[d2[i]].a2;
	}
//	cout<<endl;
	for(int i=0;i<l3;i++){
//		printf("%d ",a[d3[i]].a3);
		sum+=a[d3[i]].a3;
	}
//	cout<<endl;
	
//	printf("99\n");
	cout<<sum<<endl;
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;cin>>T;
	while(T--){
		vector <int> d1,d2,d3;
		int l1=0,l2=0,l3=0;
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a1>a[i].a2&&a[i].a1>a[i].a3 ){
				d1.push_back(i);
				l1++;
			}if(a[i].a2>a[i].a1&&a[i].a2>a[i].a3 ){
				d2.push_back(i);
				l2++;
			}if(a[i].a3>a[i].a2&&a[i].a3>a[i].a1 ){
				d3.push_back(i);
				l3++;
			}
		}
		sort(d1.begin(),d1.end(),cmp1);
		sort(d2.begin(),d2.end(),cmp2);
		sort(d3.begin(),d3.end(),cmp3);
//		printf("111\n");
		if(l1<<1 > n){
//			printf("l1.%d\n",l1);
			f(d1, d2,d3);
		}else if(l2<<1 >n){
//			printf("l2.%d\n",l2);
			f(d2,d1,d3);
		}else if(l3<<1 >n){
//			printf("l3.%d\n",l3);
			f(d3,d2,d1);
		}
		f(d3,d2,d1);
	}
	
	
	return 0;
}
