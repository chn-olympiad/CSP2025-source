#include<bits/stdc++.h>
using namespace std;
struct tw{
	int l,r;
};
int n,q;
string t1,t2;
struct eyz{
	string s1,s2;
	int l,r;
}a[200005]={};
int oo1[5000005]={},oo2[5000005]={},o11=0,o22=0;
tw sam(string a,string b){
	int n=a.size();
	int l=0,r=n-1;
	while(l<n && a[l]!=b[l])l++;
	while(r>=0 && a[r]!=b[r])r--;
	tw re;
	re.l=l;re.r=r;
	return re;
}
tw dif(string a,string b){
	int n=a.size();
	int l=0,r=n-1;
	while(l<n && a[l]==b[l])l++;
	while(r>=0 && a[r]==b[r])r--;
	tw re;
	re.l=l;re.r=r;
	return re;
}
int find(string a,string b){
	int m=a.size(),n=b.size();
	for(int i=0;i<m;i++){
		if(a[i]==b[0]){
			for(int j=0;j<n && (i+j)<m;j++){
				if(a[i+j]!=b[j])break;
				if(j==n-1)return i;
			}
		}
	}
	return -1;
}
string yd(string a,int l,int r){
	string re;
	for(int i=l;i<=r;i++)re+=a[i];
	return re;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a[i].s1 >> a[i].s2;
		tw o=sam(a[i].s1,a[i].s2);
		a[i].l=o.l;
		a[i].r=o.r;
	}
	while(q--){
		cin >> t1 >> t2;
		if(t1.size()!=t2.size()){
			cout << 0 << endl;
		}else{
			int ans=0;
			o11=0;
			o22=0;
			for(int i=1;i<=n;i++){
				int f1=find(t1,a[i].s1),f2=find(t2,a[i].s2);
				while(f1>=0){
					o11++;
					oo1[o11]=f1;
					f1=find(yd(t1,f1+1,t1.size()-1),a[i].s1);
				}
				while(f2>=0){
					o22++;
					oo2[o22]=f1;
					f2=find(yd(t2,f2+1,t2.size()-1),a[i].s2);
				}
				for(int ii=1;ii<=o11;ii++){
					for(int jj=1;jj<=o22;jj++){
						if(oo1[ii]==oo2[jj])ans++;
					}
				}
			}
			cout << ans << endl;

			
			
//			int ans=0;
//			tw chan=dif(t1,t2);
//			string chan1=yd(t1,chan.l,chan.r),chan2=yd(t2,chan.l,chan.r);
//			for(int i=1;i<=n;i++){
//				int x1=find(a[i].s1,chan1),x2=find(a[i].s2,chan2);
//				while(x1==x2 && x1!=-1){
//					int xx1=find(t1,a[i].s1),xx2=find(t2,a[i].s2);
//					if(xx1==xx2 && xx1!=-1)
//					{
//						ans++;
//						
//					}
//				}
//			}
		}
	}
//	for(int i=0;i<q;i++){
//		cin >> t1 >> t2;
//		if(t1.size()!=t2.size()){
//			cout << 0 << endl;
//			continue;
//		}
//		int ans=0;
//		tw chan=dif(t1,t2);
//		string chan1=yd(t1,chan.l,chan.r),chan2=yd(t2,chan.l,chan.r);
//		
//		for(int j=1;j<=n;j++){
//			if(a[i].s1==chan1 && a[i].s2==chan2)ans++;
//			else{
//				int tmp1=find(t1,a[i].s1),tmp2=find(t2,a[i].s2);
//				while(tmp1==tmp2 && tmp1!=-1){
//					
//				}
//			}
//		}
//	}
	return 0;
}
