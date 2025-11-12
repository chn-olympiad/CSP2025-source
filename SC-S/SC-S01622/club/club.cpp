#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int n[114514];
struct node{
	int a1,a2,a3;
}a[114514];
int r[114514],s[114514],t[114514];
inline int cmp1(node a,node b){
	return a.a1>b.a1;
}
inline int cmp2(node a,node b){
	return a.a2>b.a2;
}
inline int cmp3(node a,node b){
	return a.a3>b.a3;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n[i];
		int sum=0;
		int maxn=n[i]/2;
		int x=0,y=0,z=0;
		for(int j=0;j<n[i];j++){
			cin>>a[j].a1>>a[j].a2>>a[j].a3;
			r[j]=a[j].a1;
			s[j]=a[j].a2;
			t[j]=a[j].a3;
		}
//		sort(r,r+n[i]);
//		sort(s,s+n[i]);
//		sort(t,t+n[i]);
//		int rr=0,ss=0,tt=0;
//		for(int j=0;j<maxn;j++){
//			rr+=r[n[i]-1-j];
//			ss+=s[n[i]-1-j];
//			tt+=t[n[i]-1-j];
//		}
////		cout<<rr<<' '<<ss<<' '<<tt<<endl;
//		if(rr>=ss&&rr>=tt){
////			cout<<1<<endl;
//		    sort(a,a+n[i],cmp1);
//		}
//		else if(ss>=rr&&ss>=tt){
////			cout<<2<<endl;
//            sort(a,a+n[i],cmp2);
//		}
//		else if(tt>=ss&&tt>=rr){
////			cout<<3<<endl;
//		    sort(a,a+n[i],cmp3);
//		}
		if(n[i]==2){
			int ans[6];
			ans[0]=a[0].a1+a[1].a2;
			ans[1]=a[0].a1+a[1].a3;
			ans[2]=a[0].a2+a[1].a1;
			ans[3]=a[0].a2+a[1].a3;
			ans[4]=a[0].a3+a[1].a1;
			ans[5]=a[0].a3+a[1].a2;
			sort(ans,ans+6);
			sum=ans[5];
		}
		else if(n[i]==4){
			for(int j=0;j<4;j++){
				int ans[54];
				ans[0]=a[0].a1+a[1].a1+a[2].a2+a[3].a2;
				ans[1]=a[0].a1+a[1].a1+a[2].a2+a[3].a3;
				ans[2]=a[0].a1+a[1].a1+a[2].a3+a[3].a2;
				ans[3]=a[0].a1+a[1].a1+a[2].a3+a[3].a3;
				ans[4]=a[0].a1+a[1].a2+a[2].a1+a[3].a2;
				ans[5]=a[0].a1+a[1].a2+a[2].a1+a[3].a3;
				ans[6]=a[0].a1+a[1].a2+a[2].a2+a[3].a1;
				ans[7]=a[0].a1+a[1].a2+a[2].a2+a[3].a3;
				ans[8]=a[0].a1+a[1].a2+a[2].a3+a[3].a1;
				ans[9]=a[0].a1+a[1].a2+a[2].a3+a[3].a2;
				ans[10]=a[0].a1+a[1].a2+a[2].a3+a[3].a3;
				ans[11]=a[0].a1+a[1].a3+a[2].a1+a[3].a2;
				ans[12]=a[0].a1+a[1].a3+a[2].a1+a[3].a3;
				ans[13]=a[0].a1+a[1].a3+a[2].a2+a[3].a1;
				ans[14]=a[0].a1+a[1].a3+a[2].a2+a[3].a2;
				ans[15]=a[0].a1+a[1].a3+a[2].a2+a[3].a3;
				ans[16]=a[0].a1+a[1].a3+a[2].a3+a[3].a1;
				ans[17]=a[0].a1+a[1].a3+a[2].a3+a[3].a2;
				//
				ans[18]=a[0].a2+a[1].a1+a[2].a1+a[3].a2;
				ans[19]=a[0].a2+a[1].a1+a[2].a1+a[3].a3;
				ans[20]=a[0].a2+a[1].a1+a[2].a2+a[3].a1;
				ans[21]=a[0].a2+a[1].a1+a[2].a2+a[3].a3;
				ans[22]=a[0].a2+a[1].a1+a[2].a3+a[3].a1;
				ans[23]=a[0].a2+a[1].a1+a[2].a3+a[3].a2;
				ans[24]=a[0].a2+a[1].a1+a[2].a3+a[3].a3;
				ans[25]=a[0].a2+a[1].a2+a[2].a1+a[3].a1;
				ans[26]=a[0].a2+a[1].a2+a[2].a1+a[3].a3;
				ans[27]=a[0].a2+a[1].a2+a[2].a3+a[3].a1;
				ans[28]=a[0].a2+a[1].a2+a[2].a3+a[3].a3;
				ans[29]=a[0].a2+a[1].a3+a[2].a1+a[3].a1;
				ans[30]=a[0].a2+a[1].a3+a[2].a1+a[3].a2;
				ans[31]=a[0].a2+a[1].a3+a[2].a1+a[3].a3;
				ans[32]=a[0].a2+a[1].a3+a[2].a2+a[3].a1;
				ans[33]=a[0].a2+a[1].a3+a[2].a2+a[3].a3;
				ans[34]=a[0].a2+a[1].a3+a[2].a3+a[3].a1;
				ans[35]=a[0].a2+a[1].a3+a[2].a3+a[3].a2;
				//
				ans[36]=a[0].a3+a[1].a1+a[2].a1+a[3].a2;
				ans[37]=a[0].a3+a[1].a1+a[2].a1+a[3].a3;
				ans[38]=a[0].a3+a[1].a1+a[2].a2+a[3].a1;
				ans[39]=a[0].a3+a[1].a1+a[2].a2+a[3].a2;
				ans[40]=a[0].a3+a[1].a1+a[2].a2+a[3].a3;
				ans[41]=a[0].a3+a[1].a1+a[2].a3+a[3].a1;
				ans[42]=a[0].a3+a[1].a1+a[2].a3+a[3].a2;
				ans[43]=a[0].a3+a[1].a2+a[2].a1+a[3].a1;
				ans[44]=a[0].a3+a[1].a2+a[2].a1+a[3].a2;
				ans[45]=a[0].a3+a[1].a2+a[2].a1+a[3].a3;
				ans[46]=a[0].a3+a[1].a2+a[2].a2+a[3].a1;
				ans[47]=a[0].a3+a[1].a2+a[2].a2+a[3].a3;
				ans[48]=a[0].a3+a[1].a2+a[2].a3+a[3].a1;
				ans[49]=a[0].a3+a[1].a2+a[2].a3+a[3].a2;
				ans[50]=a[0].a3+a[1].a3+a[2].a1+a[3].a1;
				ans[51]=a[0].a3+a[1].a3+a[2].a1+a[3].a2;
				ans[52]=a[0].a3+a[1].a3+a[2].a2+a[3].a1;
				ans[53]=a[0].a3+a[1].a3+a[2].a2+a[3].a2;
				sort(ans,ans+54);
				sum=ans[53];
			}
		}
		else if(n[i]==1){
			sum=max(a[0].a1,max(a[0].a2,a[0].a3));
		}
		else{
			for(int j=0;j<n[i];j++){
				if(a[j].a1>=a[j].a2&&a[j].a1>=a[j].a3){
					if(x<maxn){
						x++;
						sum+=a[j].a1;
					}
					else{
						if(a[j].a2>=a[j].a3){
							if(y<maxn){
								y++;
								sum+=a[j].a2;
							}
							else{
								z++;
								sum+=a[j].a3;
							}
						}
					}
				}
				else if(a[j].a2>=a[j].a1&&a[j].a2>=a[j].a3){
					if(y<maxn){
						y++;
						sum+=a[j].a2;
					}
					else{
						if(a[j].a1>=a[j].a3){
							if(x<maxn){
								x++;
								sum+=a[j].a1;
							}
							else{
								z++;
								sum+=a[j].a3;
							}
						}
					}
				}
				else if(a[j].a3>=a[j].a1&&a[j].a3>=a[j].a2){
					if(z<maxn){
						z++;
						sum+=a[j].a3;
					}
					else{
						if(a[j].a1>=a[j].a2){
							if(x<maxn){
								x++;
								sum+=a[j].a1;
							}
							else{
								z++;
								sum+=a[j].a2;
							}
						}
					}
				}
			}
		}
		cout<<sum<<'\n';
	}		
	return 0;
}
//10pts