#include<bits/stdc++.h>
using namespace std;
long long t,n,ans=0,m,x,y,z;
long long a1[100005],a2[100005],a3[100005],maxa[15],mm[4]={0};
long long mmm[11][4];
bool x2=true,x3=true;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		m=n/2;
		long long a=m,b=m;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			a1[i]=x;
			a2[i]=y;
			a3[i]=z;
			if(x>=y && x>=z) maxa[i]=1;
			if(y>=x && y>=z) maxa[i]=2;
			if(z>=x && z>=y) maxa[i]=3;
			if(y!=0) x2=false;
			if(z!=0) x3=false;
		}
		if(x2 && x3){
			sort(a1+1,a1+n+1);
			for(int j=n;j>m;j--){
				ans+=a1[j];
			}
			cout<<ans<<endl;
			continue;
		}
		if(n==2){
			if(maxa[1]==1 && maxa[2]==2) ans=a1[1]+a2[2];
			else if(maxa[1]==1 && maxa[2]==3) ans=a1[1]+a3[2];
			else if(maxa[1]==2 && maxa[2]==1) ans=a2[1]+a1[2];
			else if(maxa[1]==2 && maxa[2]==3) ans=a2[1]+a3[2];
			else if(maxa[1]==3 && maxa[2]==1) ans=a3[1]+a1[2];
			else if(maxa[1]==3 && maxa[2]==2) ans=a3[1]+a2[2];
			else if(maxa[1]==1 && maxa[2]==1) ans=max(a1[1]+max(a2[2],a3[2]),a1[2]+max(a2[1],a3[1]));
			else if(maxa[1]==2 && maxa[2]==2) ans=max(a2[1]+max(a1[2],a3[2]),a2[2]+max(a1[1],a3[1]));
			else if(maxa[1]==3 && maxa[2]==3) ans=max(a3[1]+max(a2[2],a1[2]),a3[2]+max(a2[1],a1[1]));
			cout<<ans<<endl;
			continue;
		}
		if(n==4){
			for(int p=1;p<=4;p++){
				mmm[p][1]=a1[p];
				mmm[p][2]=a2[p];
				mmm[p][3]=a3[p];
			}
			for(int i1=1;i1<=3;i1++){
				if(mm[i1]>1) continue;
				mm[i1]++;
				for(int i2=1;i2<=3;i2++){
					if(mm[i2]>1) continue;
					mm[i2]++;
					for(int i3=1;i3<=3;i3++){
						if(mm[i3]>1) continue;
						mm[i3]++;
						for(int i4=1;i4<=3;i4++){
							if(mm[i4]>1) continue;
							mm[i4]++;
							ans=max(ans,mmm[1][i1]+mmm[2][i2]+mmm[3][i3]+mmm[4][i4]);
							mm[i4]--;
						}
						mm[i3]--;
					}
					mm[i2]--;
				}
				mm[i1]--;
			}
			cout<<ans<<endl;
			continue;
		}
		if(n==10){
			for(int p=1;p<=10;p++){
				mmm[p][1]=a1[p];
				mmm[p][2]=a2[p];
				mmm[p][3]=a3[p];
			}
			for(int i1=1;i1<=3;i1++){
				if(mm[i1]>4) continue;
				mm[i1]++;
				for(int i2=1;i2<=3;i2++){
					if(mm[i2]>4) continue;
					mm[i2]++;
					for(int i3=1;i3<=3;i3++){
						if(mm[i3]>4) continue;
						mm[i3]++;
						for(int i4=1;i4<=3;i4++){
						if(mm[i4]>4) continue;
						mm[i4]++;
						for(int i5=1;i5<=3;i5++){
						if(mm[i5]>4) continue;
						mm[i5]++;
						for(int i6=1;i6<=3;i6++){
						if(mm[i6]>4) continue;
						mm[i6]++;
						for(int i7=1;i7<=3;i7++){
						if(mm[i7]>4) continue;
						mm[i7]++;
						for(int i8=1;i8<=3;i8++){
						if(mm[i8]>4) continue;
						mm[i8]++;
						for(int i9=1;i9<=3;i9++){
						if(mm[i9]>4) continue;
						mm[i9]++;
						for(int i0=1;i0<=3;i0++){
							if(mm[i0]>4) continue;
							mm[i0]++;
							ans=max(ans,mmm[1][i1]+mmm[2][i2]+mmm[3][i3]+mmm[4][i4]+mmm[5][i5]+mmm[6][i6]+mmm[7][i7]+mmm[8][i8]+mmm[9][i9]+mmm[10][i0]);
							mm[i0]--;
						}
						mm[i9]--;
					}
						mm[i8]--;
					}
						mm[i7]--;
					}
						mm[i6]--;
					}
						mm[i5]--;
					}
						mm[i4]--;
					}
						mm[i3]--;
					}
					mm[i2]--;
				}
				mm[i1]--;
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}

