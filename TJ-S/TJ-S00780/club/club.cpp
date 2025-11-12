#include<bits/stdc++.h>
using namespace std;
int arr[100005],brr[100005],crr[100005];
struct ai1{
	int idx1;
	int s1;
}a1[100005];
struct ai2{
	int idx2;
	int s2;
}a2[100005];
struct ai3{
	int idx3;
	int s3;
}a3[100005];
struct aj1{
	int idx1;
	int s1;
}b1[100005];
struct aj2{
	int idx2;
	int s2;
}b2[100005];
struct aj3{
	int idx3;
	int s3;
}b3[100005];
bool cmp1(ai1 a,ai1 b){
	return a.s1>b.s1;
}
bool cmp2(ai2 a,ai2 b){
	return a.s2>b.s2;
}
bool cmp3(ai3 a,ai3 b){
	return a.s3>b.s3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		int maxa=-1,maxb=-1,maxc=-1;
		int ans;
		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i]>>brr[i]>>crr[i];
			a1[i].s1=arr[i];
			a2[i].s2=brr[i];
			a3[i].s3=crr[i];
			a1[i].idx1=i;
			a2[i].idx2=i;
			a3[i].idx3=i;
			b1[i].s1=arr[i];
			b2[i].s2=brr[i];
			b3[i].s3=crr[i];
			b1[i].idx1=i;
			b2[i].idx2=i;
			b3[i].idx3=i;
		}
		sort(a1+1,a1+n+1,cmp1);
		sort(a2+1,a2+n+1,cmp2);
		sort(a3+1,a3+n+1,cmp3);
		maxa=a1[1].idx1;
		maxb=a2[1].idx2;
		maxc=a3[1].idx3;
		ans=arr[maxa]+brr[maxb]+crr[maxc];
		int idxa=1,idxb=1,idxc=1;
		for(int i=1;i<=n;i++){
			if(i==maxa||i==maxb||i==maxc){
				continue;
			}
			int maxx=max(b1[i].s1,max(b2[i].s2,b3[i].s3));
			
			if(maxx=b1[i].s1){
				if(idxa<=n/2){
					ans+=b1[i].s1;
				}else{
					if(b2[i].s2>b3[i].s3){
						if(idxb<=n/2){
							ans+=b2[i].s2;
						}else{
							ans+=b3[i].s3;
						}
					}else{
						if(idxc<=n/2){
							ans+=b3[i].s3;
						}else{
							ans+=b2[i].s2;
						}
					}
				}
			}else if(maxx=b2[i].s2){
				if(idxb<=n/2){
					ans+=b2[i].s2;
				}else{
					if(b1[i].s1>b3[i].s3){
						if(idxa<=n/2){
							ans+=b1[i].s1;
						}else{
							ans+=b3[i].s3;
						}
					}else{
						if(idxc<=n/2){
							ans+=b3[i].s3;
						}else{
							ans+=b1[i].s1;
						}
					}
				}
			}else{
				if(idxc<=n/2){
					ans+=b3[i].s3;
				}else{
					if(b1[i].s1>b2[i].s2){
						if(idxa<=n/2){
							ans+=b1[i].s1;
						}else{
							ans+=b2[i].s2;
						}
					}else{
						if(idxb<=n/2){
							ans+=b2[i].s2;
						}else{
							ans+=b1[i].s1;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
