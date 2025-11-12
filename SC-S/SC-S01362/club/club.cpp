#include <bits/stdc++.h>
using namespace std;
int t;
long long n,l1=0,l2=0,l3=0,ans=0;
bool o1,o2,o3;

struct nma{
	int a;
	int b;
	int c;
};
nma p[200050];

struct cnm{
	long long xj;
	long long num;
	long long num2;
	long long num3;
};
cnm dl1[600050],dl2[600050],dl3[600050];

bool cmp(cnm x,cnm y){
	if(x.xj<y.xj){
		return 0;
	}
	
	return 1;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++){
		cin>>n;
		ans=0;
		o1=0;
		o2=0;
		o3=0;
		l1=0;
		l2=0;
		l3=0;
		memset(dl1,0,sizeof(dl1));
		memset(dl2,0,sizeof(dl2));
		memset(dl3,0,sizeof(dl3));
		for(int i=1;i<=n;i++){
			
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(p[i].a>p[i].b and p[i].a>p[i].c){
				l1++;
				dl1[l1].xj=p[i].a-max(p[i].b,p[i].c);
				dl1[l1].num=p[i].a;
				dl1[l1].num2=p[i].b;
				dl1[l1].num3=p[i].c;
			}
			else if(p[i].b>p[i].a and p[i].b>p[i].c){
				l2++;
				dl2[l2].xj=p[i].b-max(p[i].a,p[i].c);
				dl2[l2].num=p[i].a;
				dl2[l2].num2=p[i].b;
				dl2[l2].num3=p[i].c;
			}
			else {
				l3++;
				dl3[l3].xj=p[i].c-max(p[i].a,p[i].b);
				dl3[l3].num3=p[i].c;
				dl3[l3].num2=p[i].b;
				dl3[l3].num=p[i].a;
			}
			
		}
		
		if(l1>=l2 and l1>=l3){
			sort(dl1+1,dl1+1+l1,cmp);
			int r=0;
			while(1){
				r++;
				ans+=dl1[r].num;
				//cout<<dl1[r].num<<" ";
				if(r==n/2){
					break;
				}
			}
			
			for(int i=n/2+1;i<=l1;i++){
				if(dl1[i].num2>=dl1[i].num3){
					l2++;
					dl2[l2].num2=dl1[i].num2;
					dl2[l2].num3=dl1[i].num3;
					dl2[l2].xj=dl1[i].num2-dl1[i].num3;
				}
				else {
					l3++;
					dl3[l3].num2=dl1[i].num2;
					dl3[l3].num3=dl1[i].num3;
					dl3[l3].xj=dl1[i].num3-dl1[i].num2;
				}
			}
			o1=1;
			
		}
		else if(l2>=l1 and l2>=l3){
			sort(dl2+1,dl2+1+l2,cmp);
			int r=0;
			while(1){
				r++;
				ans+=dl2[r].num2;
				//cout<<dl2[r].num2<<" ";
				if(r==n/2){
					break;
				}
				
			}
			for(int i=n/2+1;i<=l2;i++){
				if(dl2[i].num>=dl2[i].num3){
					l1++;
					dl1[l1].num=dl2[i].num;
					dl1[l1].num3=dl2[i].num3;
					dl1[l1].xj=dl2[i].num-dl2[i].num3;
				}
				else {
					l3++;
					dl3[l3].num=dl2[i].num;
					dl3[l3].num3=dl2[i].num3;
					dl3[l3].xj=dl2[i].num3-dl2[i].num;
				}
			}
			o2=1;
		}
		else {
			sort(dl3+1,dl3+1+l3,cmp);
			int r=0;
			while(1){
				r++;
				ans+=dl3[r].num3;
				///cout<<dl3[r].num3<<" ";
				if(r==n/2){
					break;
				}
				
			}
			for(int i=n/2+1;i<=l1;i++){
				if(dl1[i].num2>=dl1[i].num3){
					l1++;
					dl1[l1].num2=dl3[i].num2;
					dl1[l1].num=dl3[i].num;
					dl1[l1].xj=dl3[i].num-dl3[i].num2;
				}
				else {
					l2++;
					dl2[l2].num2=dl3[i].num2;
					dl2[l2].num=dl3[i].num;
					dl2[l2].xj=dl3[i].num2-dl3[i].num;
				}
			}
			o3=1;
		}
		if(o1==1){
			sort(dl2+1,dl2+1+l2,cmp);
			sort(dl3+1,dl3+1+l3,cmp);
			for(int i=1;i<=min(l2+1,n/2);i++){
				ans+=dl2[i].num2;
				//cout<<dl2[i].num2<<" ";
			}
			for(int i=n/2+1;i<=l2;i++){
				ans+=dl2[i].num3;
				//cout<<dl2[i].num3<<" ";
			}
			for(int i=1;i<=min(l3+1,n/2);i++){
				ans+=dl3[i].num3;
				//cout<<dl3[i].num3<<" ";
			}
			for(int i=n/2+1;i<=l3;i++){
				ans+=dl3[i].num2;
				//cout<<dl3[i].num2<<" ";
			}
		}
		else if(o2==1){
			sort(dl1+1,dl1+1+l1,cmp);
			sort(dl3+1,dl3+1+l3,cmp);
			for(int i=1;i<=min(l1+1,n/2);i++){
				ans+=dl1[i].num;
				//cout<<dl1[i].num<<" ";
			}
			for(int i=n/2+1;i<=l1;i++){
				ans+=dl1[i].num3;
				//cout<<dl1[i].num3<<" ";
			}
			for(int i=1;i<=min(l3+1,n/2);i++){
				ans+=dl3[i].num3;
				//cout<<dl3[i].num3<<" ";
			}
			for(int i=n/2+1;i<=l3;i++){
				ans+=dl3[i].num;
				//cout<<dl3[i].num<<" ";
			}
		}
		else if(o3==1){
			sort(dl2+1,dl2+1+l2,cmp);
			sort(dl1+1,dl1+1+l1,cmp);
			for(int i=1;i<=min(l1+1,n/2);i++){
				ans+=dl1[i].num;
				//cout<<dl1[i].num<<" ";
			}
			for(int i=n/2+1;i<=l1;i++){
				ans+=dl1[i].num2;
				//cout<<dl1[i].num2<<" ";
			}
			for(int i=1;i<=min(l2+1,n/2);i++){
				ans+=dl2[i].num2;
				//cout<<dl3[i].num2<<" ";
			}
			for(int i=n/2+1;i<=l2;i++){
				ans+=dl2[i].num;
				//cout<<dl3[i].num<<" ";
			}
		}
		
		cout<<ans<<endl;
	}
	
	
	
	return 0;
} 