#include <bits/stdc++.h>
using namespace std;

/*
club
oh no. skipped at 15:15. etw ~ 40pts
Finally passed all pretests, hope that there's no MLE.
I have become schlecter, honestly speaking. at 17:36.
*/

constexpr int N = 1e5+4;
int n;

inline int maxi(int a, int b) {
	return a > b ? a : b;
}

inline int mini(int a, int b) {
	return a < b ? a : b;
}

struct person {
	int id, s1, s2, s3, cgid;
	person() {
		
	}
	int getas(int x) const {
		if (x == 1) return s1;
		else if (x == 2) return s2;
		else return s3;
	}
};

struct bill {
	int cpid;
	long long intent;
	bill() {
		
	}
	bill(int cpid, long long intent)
		: cpid(cpid), intent(intent) {
			
		}
};

bool operator < (const bill &a, const bill &b) {
	return a.intent < b.intent;
}

bool operator > (const bill &a, const bill &b) {
	return a.intent > b.intent;
}

// intents[from][to]
priority_queue<bill> intents[4][4];

person ps[N];

// It is still wrong, I don't know why
bool cmp(const person &a, const person &b) {
	if ((a.s1 - a.s2) == (b.s1 - b.s2)) {
		return (a.s3 - a.s1) > (b.s3 - b.s1);
	}
	return (a.s1 - a.s2) > (b.s1 - b.s2);
}

bool cmp2(const person &a, const person &b) {
	return (a.s3 - a.s2) > (b.s3 - b.s2);
}

void cleanup() {
//	cerr << "Pre cleaning!\n";
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			while (!intents[i][j].empty()) intents[i][j].pop();
		}
	}
	return;
}

int assigned[N], best_ans[N], ans = 0;	// 1 or 2 or 3

void dfs(int cur) {
	if (cur > n) {
		int s1 = 0, s2 = 0, s3 = 0;
		for (int i = 1; i <= n; i++) {
			if (assigned[i]==1) s1++;
			else if (assigned[i]==2) s2++;
			else s3++;
		}
		if (s1 <= (n>>1) && s2 <= (n>>1) && s3 <= (n>>1)) {
			int cur = 0;
			for (int i = 1; i <= n; i++) {
				if (assigned[i]==1) cur+=ps[i].s1;
				else if (assigned[i]==2) cur+=ps[i].s2;
				else cur+=ps[i].s3;
			}
			if (cur>ans) {
				for (int i = 1; i <= n; i++) best_ans[i] = assigned[i];
				ans=cur;
			}
		}
		return;
	} else {
		for (int i = 1; i <= 3; i++) {
			assigned[cur] = i;
			dfs(cur+1);
		}
	}
}

void baoli() {
	ans = 0;
//	cerr<<"CALL BAOLI\n";
	dfs(1);
	cout<<ans<<'\n';
//	cerr<<"Current best: ";
//	for (int i = 1; i <= n; i++) cerr<<best_ans[i]<<' ';
//	cerr<<endl;
}

constexpr bool ALLOW_BAOLI = true;

void tidies(priority_queue<bill> &obj, int origin) {
	while (!obj.empty()) {
		auto tops = obj.top();
		if (origin != ps[tops.cpid].cgid) obj.pop();
		else break;
	}
}

void ps_enter(int i) {
//	cerr << "Pse " << i << ", gid " << ps[i].cgid << endl;
	for (int cat = 1; cat <= 3; cat++) {
		if (cat == ps[i].cgid) continue;
		intents[ps[i].cgid][cat].push(bill(i, ps[i].getas(cat) - ps[i].getas(ps[i].cgid)));
	}
}

int curcnt[4];

void subgroup() {
	cin>>n;
	for (int i = 1; i <= n; i++) {
		cin>>ps[i].s1>>ps[i].s2>>ps[i].s3;
		ps[i].id = i;
	}
	if (ALLOW_BAOLI && n <= 10) {
		baoli();
		return;
	}
	sort(ps+1,ps+n+1,cmp);
	long long ans = 0;
//	cerr << "Sort ende\n";
	// step 1: s1 - s2  reordering
	for (int i = 1; i <= (n>>1); i++) {
		ans += ps[i].s1;
		ps[i].cgid = 1;
		ps_enter(i);
	}
	for (int i = (n>>1)+1; i <= n; i++) {
		ans += ps[i].s2;
		ps[i].cgid = 2;
		ps_enter(i);
	}
	// Tackle with all bills
	curcnt[1] = curcnt[2] = (n>>1);
	curcnt[3] = 0;
//	cerr << "Bill anfangen\n";
	while (true) {
		int cgmax = -1, cabout = -1, cgatheap = -1, corigin = -1;
		int swapneed = -1;	// what point to participate
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) tidies(intents[i][j], i);
		}
		// no need to check empty
//		cerr << "Loop begin:\n";
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				if (i == j) continue;
				if ((!intents[i][j].empty()) && (intents[i][j].top().intent > 0)) {
					int curr = intents[i][j].top().intent;
					if (curcnt[j] >= (n>>1)) {
						// Seek for swap
						if (intents[j][i].empty()) continue;
						curr += intents[j][i].top().intent;
						if (curr <= 0) continue;
						if (curr > cgmax) {
							cgmax = curr;
							cabout = intents[i][j].top().cpid;
							cgatheap = j;	// swap target
							corigin = i;	// swap source
							swapneed = intents[j][i].top().cpid;
						}
					} else {
						if (curr > cgmax) {
							cgmax = curr;
							cabout = intents[i][j].top().cpid;
							cgatheap = j;	// swap target
							corigin = i;	// swap source
							swapneed = -1;
						}
					}
				}
			}
		}
		
		if (cgatheap < 0) break;
		intents[corigin][cgatheap].pop();
		if (swapneed != -1) intents[cgatheap][corigin].pop();
		// Accept this
		int kosten = ps[cabout].getas(corigin);
		if (swapneed != -1) kosten += ps[swapneed].getas(cgatheap);
		
		int besser = ps[cabout].getas(cgatheap);
		if (swapneed != -1) besser += ps[swapneed].getas(corigin);
		
		if (besser < kosten) {
			cerr << "[WARNING] no-profit moving!\n";
			continue;	// No movement
			
		}
//		cerr << "Do: " << cabout << " and " << swapneed << " (between " << corigin << "," << cgatheap << "): ";
//		cerr << besser << " - " << kosten << endl;
		ans += besser - kosten;
		ps[cabout].cgid = cgatheap;
		ps_enter(cabout);
		if (swapneed != -1) {
			ps[swapneed].cgid = corigin;
			ps_enter(swapneed);
		} else {
			curcnt[corigin]--; curcnt[cgatheap]++;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		assigned[ps[i].id] = ps[i].cgid;
	}
//	cerr << "final: a = " << curcnt[1] << ", b = " << curcnt[2] << ", c = " << curcnt[3] << endl;
//	cerr << "assignment: ";
//	for (int i = 1; i <= n; i++) cerr << assigned[i] << ' ';
//	cerr << endl;
	cout<<ans<<'\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin>>t;
	for (int i = 0; i < t; i++) {
		cleanup();
		subgroup();
	}
	
	cout<<flush;
	return 0;
}