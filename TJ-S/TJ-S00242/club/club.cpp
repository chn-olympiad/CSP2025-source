#include<bits/stdc++.h>
using namespace std;
int T,n;
struct student{
	int ID,like_value1,like_value2,like_value3;
	bool used_type=false;
}a[100009],b[100009],c[100009];
bool cmp1(student x,student y){
	return x.like_value1>y.like_value1;
}bool cmp2(student x,student y){
	return x.like_value2>y.like_value2;
}bool cmp3(student x,student y){
	return x.like_value3>y.like_value3;
}
//map<int,bool> be_used;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			a[i].ID=i;
			cin>>a[i].like_value1>>a[i].like_value2>>a[i].like_value3;
		} 
		int value_cnt=0;
		int id_cnt=0;
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(a[i].like_value2<a[i].like_value1&&a[i].like_value3<a[i].like_value1){
//				be_used[a[i].ID]=true;
				a[i].used_type=true;
				value_cnt+=a[i].like_value1;
				id_cnt++;
				if(2*id_cnt==n)break;
			}
		}
		id_cnt=0;
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(a[i].like_value3<a[i].like_value2&&a[i].used_type!=true){
//				be_used[a[i].ID]=true;
				a[i].used_type=true;
				value_cnt+=a[i].like_value2;
				id_cnt++;
				if(2*id_cnt==n)break;
			}
		}
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n;i++){
			if(a[i].used_type!=true){
//				be_used[a[i].ID]=true;
				a[i].used_type=true;
				value_cnt+=a[i].like_value3;
				id_cnt++;
				if(2*id_cnt==n)break;
			}
		}
		cout<<value_cnt;
	}
	
	
	
	
	return 0;
} 
