#include<bits/stdc++.h>
using namespace std;
struct p{
	int first,sceond,third;
	int xfir,xsce,xthi;
}a[500010];
void sor(int id){
	if(a[id].xfir<a[id].xsce){
		swap(a[id].xfir,a[id].xsce);
		swap(a[id].first,a[id].sceond);
	}
	if(a[id].xsce<a[id].xthi){
		swap(a[id].xsce,a[id].xthi);
		swap(a[id].third,a[id].sceond);
	}
	if(a[id].xfir<a[id].xsce){
		swap(a[id].xfir,a[id].xsce);
		swap(a[id].first,a[id].sceond);
	}
}
bool cmp1(p a,p b){
	if(a.xfir-a.xsce !=b.xfir-b.xsce )return a.xfir-a.xsce > b.xfir-b.xsce;
	else return a.xsce-a.xthi>b.xsce-b.xthi;
}
int sm[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			a[i].first=1;
			a[i].sceond=2;
			a[i].third =3;
			scanf("%d%d%d",&a[i].xfir,&a[i].xsce,&a[i].xthi);
			sor(i);
			//cout<<a[i].xfir<<" "<<a[i].xsce<<" "<<a[i].xthi<<endl;
		}
		sort(a+1,a+n+1,cmp1);
		long long sum=0;
		sm[1]=sm[2]=sm[3]=0;
		for(int i=1;i<=n;i++){
			if(n/2>sm[a[i].first]){
				sm[a[i].first]++;
				sum+=a[i].xfir;
			}else{
				sm[a[i].sceond]++;
				sum+=a[i].xsce;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}