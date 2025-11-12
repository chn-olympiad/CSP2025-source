#include<bits/stdc++.h>
using namespace std;

struct ds{
	int b1,b2,b3;
};
ds data[1000002];

bool cmp1(ds _1,ds _2){
	return (_1.b1 > _2.b1);
}
bool cmp2(ds _1,ds _2){
	return (_1.b2 > _2.b2);
}
bool cmp3(ds _1,ds _2){
	return (_1.b3 > _2.b3);
}
void answer(){
	int n=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>data[i].b1>>data[i].b2>>data[i].b3;
	}
	int ans1=0;
	int ans2=0;
	int ans3=0;
	int pn=0;
	//1
	sort(data,data+n,cmp1);
	for(int i=0;i*2<n;i++){
		if(data[i].b1>=data[i].b2){
			ans1+=data[i].b1;
			pn++;
		}else{
			break;
		}
	}
	sort(data+pn,data+n,cmp2);
	int up=((n-pn)*2>=n?n/2+pn:n);
	for(int i=pn;i<up;i++){
		if(data[i].b2>=data[i].b3){
			ans1+=data[i].b2;
			pn++;
		}else{
			break;
		}
	}
	for(int i=pn;i<n;i++){
		ans1+=data[i].b3;
	}
	//2
	pn=0;
	sort(data,data+n,cmp2);
	for(int i=0;i*2<n;i++){
		if(data[i].b2>data[i].b3){
			ans2+=data[i].b2;
			pn++;
		}else{
			break;
		}
	}
	sort(data+pn,data+n,cmp3);
	up=((n-pn)*2>=n?n/2+pn:n);
	for(int i=pn;i<up;i++){
		if(data[i].b3>=data[i].b1){
			ans2+=data[i].b3;
			pn++;
		}else{
			break;
		}
	}
	for(int i=pn;i<n;i++){
		ans2+=data[i].b1;
	}
	//3
	pn=0;
	sort(data,data+n,cmp3);
	for(int i=0;i*2<n;i++){
		if(data[i].b3>=data[i].b1){
			ans3+=data[i].b3;
			pn++;
		}else{
			break;
		}
	}
	sort(data+pn,data+n,cmp1);
	up=((n-pn)*2>=n?n/2+pn:n);
	for(int i=pn;i<up;i++){
		if(data[i].b1>=data[i].b2){
			ans3+=data[i].b1;
			pn++;
		}else{
			break;
		}
	}
	for(int i=pn;i<n;i++){
		ans3+=data[i].b2;
	}
	
	cout<<max(ans1,max(ans2,ans3))<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int num=0;
	cin>>num;
	for(int i=0;i<num;i++){
		answer();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}