#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
struct st{
	int md1;
	int md2;
	int md3;
	int jc1;
	int jc2;
	int jc3;
	int flag;
}a[100005];
bool cmp(st x,st y){
	if(x.jc1!=y.jc1){
		return x.jc1<y.jc1;
	}
	if(x.jc2!=y.jc2){
		return x.jc2>y.jc2;
	}
	return x.jc3>y.jc3;
}
bool cmp1(st x,st y){
	if(x.jc2!=y.jc2){
		return x.jc2<y.jc2;
	}
	if(x.jc3!=y.jc3){
		return x.jc3>y.jc3;
	}
	return x.jc1>y.jc1;
}
bool cmp2(st x,st y){
	if(x.jc3!=y.jc3){
		return x.jc3<y.jc3;
	}
	if(x.jc1!=y.jc1){
		return x.jc1>y.jc1;
	}
	return x.jc2>y.jc2;
}
bool cmp3(st x,st y){
	return x.flag>y.flag;
}
vector<int> v;
int zzh=0;
int maxxx=-1;
void dfs(int id){
	if(id==n){
		int h1=0;
		int h2=0;
		int h3=0;
		zzh=0;
		for(int i=0;i<v.size();i++){
			if(v[i]==1){
				zzh+=a[i+1].md1;
				h1++;
			}
			else if(v[i]==2){
				zzh+=a[i+1].md2;
				h2++;
			}
			else{
				zzh+=a[i+1].md3;
				h3++;
			}
			if(h1>n/2||h2>n/2||h3>n/2){
				break;
			}
		}
		if(h1<=n/2&&h2<=n/2&&h3<=n/2){
			maxxx=max(maxxx,zzh);
//			cout<<zzh<<" ";
		}
//		for(int i=0;i<v.size();i++){
//			cout<<v[i];
//		}
//		cout<<"\n";
		return;
	}
	for(int i=1;i<=3;i++){
		v.push_back(i);
		dfs(id+1);
		v.pop_back();
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].md1>>a[i].md2>>a[i].md3;
		}
		if(n<=20){
			maxxx=-1;
			dfs(0);
		cout<<maxxx<<"\n";
		}
		else{
		int zrs=n;
		int h1=n/2;
		int h2=n/2;
		int h3=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].md1>>a[i].md2>>a[i].md3;
			a[i].flag=1;
			if(a[i].md1>=a[i].md2&&a[i].md1>=a[i].md3){
				a[i].jc1=0;
				a[i].jc2=a[i].md1-a[i].md2;
				a[i].jc3=a[i].md1-a[i].md3;
			}
			else if(a[i].md2>=a[i].md1&&a[i].md2>=a[i].md3){
				a[i].jc1=a[i].md2-a[i].md1;
				a[i].jc2=0;
				a[i].jc3=a[i].md2-a[i].md3;
			}
			else{
				a[i].jc1=a[i].md3-a[i].md1;
				a[i].jc2=a[i].md3-a[i].md2;
				a[i].jc3=0;
			}
		}
			sort(a+1,a+1+n,cmp);
			int cs=1;
			int zh=0;
			int cs1=0;
			while(1){
				if(cs1<n/2&&a[cs].jc1==0){
					if(a[cs].flag==1){
						a[cs].flag=0;
						zh+=a[cs].md1;
						cs1++;
					}
					cs++;
				}
				else{
					break;
				}
			}
			h1=h1-cs1;
			zrs-=cs1;
		sort(a+1,a+1+n,cmp1);
		cs=1;
		cs1=0;
		while(1){
			if(cs1<n/2&&a[cs].jc2==0){
				if(a[cs].flag==1){
					a[cs].flag=0;
					zh+=a[cs].md2;
					cs1++;
				}
				cs++;
			}
			else{
				break;
			}
		}
		h2=h2-cs1;
		zrs-=cs1;
		sort(a+1,a+1+n,cmp2);
		cs=1;
		cs1=0;
		while(1){
			if(cs1<n/2&&a[cs].jc3==0){
				if(a[cs].flag==1){
					a[cs].flag=0;
					zh+=a[cs].md3;
					cs1++;
				}
				cs++;
			}
			else{
				break;
			}
		}
		h3=h3-cs1;
		zrs-=cs1;
		sort(a+1,a+1+n,cmp3);
		while(zrs--){
			int rrr=1;
			if(a[rrr].jc1==0){
				if(a[rrr].md2>a[rrr].md3){
					if(h2>0){
						zh+=a[rrr].md2;
						h2--;
					}
					else{
						zh+=a[rrr].md3;
						h3--;
					}
				}
				else{
					if(h3>0){
						zh+=a[rrr].md3;
						h3--;
					}
					else{
						zh+=a[rrr].md2;
						h2--;
					}
				}
			}
			else if(a[rrr].jc2==0){
				if(a[rrr].md1>a[rrr].md3){
					if(h1>0){
						zh+=a[rrr].md1;
						h1--;
					}
					else{
						zh+=a[rrr].md3;
						h3--;
					}
				}
				else{
					if(h3>0){
						zh+=a[rrr].md3;
						h3--;
					}
					else{
						zh+=a[rrr].md1;
						h1--;
					}
				}
			}
			else if(a[rrr].jc3==0){
				if(a[rrr].md2>a[rrr].md1){
					if(h2>0){
						zh+=a[rrr].md2;
						h2--;
					}
					else{
						zh+=a[rrr].md1;
						h1--;
					}
				}
				else{
					if(h1>0){
						zh+=a[rrr].md1;
						h1--;
					}
					else{
						zh+=a[rrr].md2;
						h2--;
					}
				}
			}
			rrr++;
		}
		cout<<zh<<"\n";
		}
	}
	return 0;
}