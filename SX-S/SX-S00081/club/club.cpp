#include<bits/stdc++.h>
using namespace std;

struct love{
	int aa;
	int bb;
	int cc;
	char maxx;
	int maxxx;
};
bool t0(love a){
	if(a.aa==0&&a.bb==0||a.aa==0&&a.cc==0||a.bb==0&&a.cc==0)return 1;
	return 0;
}
bool cmp(love a,love b){
	if(a.maxx<b.maxx)return 1;
	else if(a.maxx==b.maxx&&a.maxxx>b.maxxx)return 1;
	else if(t0(b)==1)return 1;
	return 0;
}



int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	for(int ii=1;ii<=t;ii++){
		int n;cin>>n;
		love a[n+3];
		int sum[6]={0},num[6]={0};

		for(int i=1;i<=n;i++){
			cin>>a[i].aa>>a[i].bb>>a[i].cc;

			if(n==2){
	if(a[1].maxx==a[2].maxx){
		if(a[1].aa==a[2].aa){
			if(a[2].bb>a[2].cc){
				cout<<a[1].aa+a[2].bb;
				return 0;
			}
			else{
				cout<<a[1].aa+a[2].cc;
				return 0;
			}
		}
		else if(a[1].bb==a[2].bb){
			if(a[2].aa>a[2].cc){
				cout<<a[1].bb+a[2].aa;
				return 0;
			}
			else{
				cout<<a[1].bb+a[2].cc;
				return 0;
			}
		}
		else{
			if(a[2].aa>a[2].bb){
				cout<<a[1].cc+a[2].aa;
				return 0;
			}
			else{
				cout<<a[1].cc+a[2].bb;
				return 0;
			}
		}
	}
}




			if(a[i].aa>a[i].bb&&a[i].aa>a[i].cc){
				a[i].maxx='a';
				a[i].maxxx=a[i].aa;
			}
			else if(a[i].bb>a[i].aa&&a[i].bb>a[i].cc){
				a[i].maxx='b';
				a[i].maxxx=a[i].bb;
			}
			else if(a[i].cc>a[i].aa&&a[i].cc>a[i].bb){
				a[i].maxx='c';
				a[i].maxxx=a[i].cc;
			}
		}
		sort(a+1,a+1+n,cmp);

		int sx=n/2;
		for(int i=1;i<=n;i++){
			if(a[i].maxx=='a'&&num[1]<sx){
				sum[1]+=a[i].maxxx;
				num[1]++;
			}
			else if(a[i].maxx=='b'&&num[2]<sx){
				sum[2]+=a[i].maxxx;
				num[2]++;
			}
			else if(a[i].maxx=='c'&&num[3]<sx){
				sum[3]+=a[i].maxxx;
				num[3]++;
			}
			else{
				if(num[1]<num[2]&&num[1]<num[3]){
					if(num[1]<sx){
						num[1]++;
						sum[1]+=a[i].aa;
					}
					else if(num[2]<num[3]&&num[2]<sx){
						num[2]++;
						sum[2]+=a[i].bb;
					}
					else{
						num[3]++;
						sum[3]+=a[i].cc;
					}
				}
				else if(num[2]<num[3]){
					if(num[2]<sx){
						num[2]++;
						sum[2]+=a[i].bb;
					}
					else{
						num[3]++;
						sum[3]+=a[i].cc;
					}
				}
				else{
					num[3]++;
					sum[3]+=a[i].cc;
				}
			}
		}
		//sort(sum+1,sum+1+3);
		//cout<<num[1]<<" "<<num[2]<<" "<<num[3]<<endl;
		cout<<sum[1]+sum[2]+sum[3]<<endl;
		//cout<<endl;
	}




	return 0;
}