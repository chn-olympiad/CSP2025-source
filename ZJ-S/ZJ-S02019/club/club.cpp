//1
//1 4 0 1 0 0 2 0 0 1 0 0 2 0
#include<bits/stdc++.h>
using namespace std;
struct xxx{
	int x,y,z;	
};
xxx a[100005];
int cmp1(xxx a,xxx b){
	return a.x>b.x;
}
int cmp2(xxx a,xxx b){
	return (a.x-a.y)>(b.x-b.y);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int q=0;q<t;q++){
		int n;
		bool fa=1,fb=1;
		long long sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0||a[i].z!=0)fa=0;
			if(a[i].z!=0)fb=0;
		}
		if(fa){//5point get
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++)sum+=a[i].x;
			cout<<sum<<endl;
		}
		else if(fb){//15point get
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n/2;i++)sum=sum+a[i].x;
			for(int i=n/2+1;i<=n;i++)sum=sum+a[i].y;
			cout<<sum<<endl;
		}
		else{//20point get
			for(long long k=0;k<pow(3,n);k++){
				int kk=k,wei=1,can[205]={0},ashu=0,bshu=0,cshu=0;
				long long num=0;
				while(kk){
					can[wei]=kk%3;
					wei++;
					kk/=3;
				}
				for(int i=1;i<=n;i++){
					if(can[i]==0){
						ashu++;
						num=num+a[i].x;
					}
					else if(can[i]==1){
						bshu++;
						num=num+a[i].y;
					}
					else{
						cshu++;
						num=num+a[i].z;
					}
					if(max(ashu,max(bshu,cshu))<=n/2){
						sum=max(num,sum);
					}
				}
			}
			cout<<sum<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
