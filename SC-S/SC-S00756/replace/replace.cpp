#include <cstdio>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

typedef long long i64;
typedef char const *CStr;
#define MAGIC (13731ll)
#define MODNUM (199999)
#define MAXN (200000 + 4)
#define MAXLEN (5000000 + 4)

inline bool checkchar(char c) {
    return isspace(c) || c == EOF;
}
char input[20000004];
i64 powmg[MAXLEN];
int inputsiz, inputptr;

struct String {
    CStr begin, end;
    std::vector<i64> hsh;
    inline int size() const {
        return end - begin;
    }
    void print() const {
        for (CStr iter = begin; iter != end; ++iter) {
            putchar(*iter);
        }
        putchar('\n');
    }
    void make_hash() {
        int mysz = size();
        hsh.resize(mysz);
        hsh[0] = begin[0];
        for (int i = 1; i < mysz; ++i) {
            hsh[i] = (hsh[i - 1] * MAGIC + begin[i]) % MODNUM;
        }
    }
    i64 get_hash(int l, int r) {
        if (l == 0) {
            return hsh[r];
        } else {
            i64 ans = hsh[r] - ((hsh[l - 1] * powmg[r - l + 1]) % MODNUM);
            if (ans < 0) ans += MODNUM;
            return ans;
        }
    }
    int compare(String const &rhs) const {
        int len = std::min(size(), rhs.size());
        for (int i = 0; i < len; ++i) {
            if (begin[i] < rhs.begin[i]) {
                return -1;
            } else if (begin[i] > rhs.begin[i]) {
                return 1;
            }
        }
        if (size() < rhs.size()) {
            return -1;
        } else if (size() > rhs.size()) {
            return 1;
        } else {
            return 0;
        }
    }
    inline char operator[](int index) const {
        return begin[index];
    }
};
String *getstr() {
    while (isspace(input[inputptr])) ++inputptr;
    CStr begin = input + inputptr;
    while (inputptr < inputsiz && !isspace(input[inputptr])) ++inputptr;
    return new String {begin, input + inputptr, {}};
}

struct Replacer {
    String *fr, *to;
    int i = -1;
    bool operator<(Replacer const &rhs) {
        // printf("Comparing %d(%p) %d(%p)\n", i, fr, rhs.i, rhs.fr);
        return fr->compare(*rhs.fr) == -1;
    }
} rep[MAXN];

String *src, *dst;
int srclen;
bool preeq[MAXN], sufeq[MAXN];
struct HashTable {
    int head[MODNUM], next[MAXN];
    HashTable() {
        memset(head, -1, sizeof head);
    }
    void insert(int h, int i) {
        next[i] = head[h];
        head[h] = i;
    }
};
std::map<int, HashTable> oflen;
HashTable &touchof(int len) {
    auto iter = oflen.find(len);
    if (iter == oflen.end()) {
        return oflen.insert({len, HashTable()}).first->second;
    } else {
        return iter->second;
    }
}

signed main() {
#define FILENAME "replace"
    freopen(FILENAME ".in", "r", stdin);
    freopen(FILENAME ".out", "w", stdout);

    int n, q;
    scanf("%d%d", &n, &q);

    inputsiz = fread(input, sizeof(char), sizeof(input) / sizeof(char), stdin);
    inputptr = 0;
    powmg[0] = 1;
    for (int i = 1; i < MAXLEN; ++i) {
        powmg[i] = (powmg[i - 1] * MAGIC) % MODNUM;
    }
    for (int i = 0; i < n; ++i) {
        rep[i].fr = getstr();
        rep[i].to = getstr();
        rep[i].i = i;
        // // DEBUG
        // rep[i].fr->print();
        // rep[i].to->print();
    }
    for (int i = 0; i < n; ++i) {
        rep[i].fr->make_hash();
        rep[i].to->make_hash();
        int len = rep[i].fr->size();
        touchof(len).insert(rep[i].fr->get_hash(0, len - 1), i);
        // printf("This hash is %lld\n", rep[i].fr->get_hash(0, len - 1));
    }
    for (int i = 0; i < q; ++i) {
        src = getstr();
        dst = getstr();
        srclen = src->size();
        memset(preeq, 0, sizeof(bool) * srclen);
        memset(sufeq, 0, sizeof(bool) * srclen);
        // make_sa(*src);
        src->make_hash();
        dst->make_hash();
        int lastpre = -1;
        for (int cur = 0; cur < srclen && src->begin[cur] == dst->begin[cur]; ++cur) {
            preeq[cur] = true;
            lastpre = cur;
        }
        ++lastpre;
        // printf("lastpre = %d\n", lastpre);
        for (int cur = srclen - 1; cur >= 0 && src->begin[cur] == dst->begin[cur]; --cur) {
            sufeq[cur] = true;
            // printf("sufeq[%d] is true\n", cur);
        }
        sufeq[srclen] = true;
        int ans = 0;
        for (int pos = lastpre; pos >= 0; --pos) {
            // printf("ps = %d\n", pos);
            for (auto &iter : oflen) {
                int len = iter.first;
                auto &table = iter.second;
                // printf("len = %d\n", len);
                if (pos + len - 1 >= srclen || !sufeq[pos + len]) continue;
                i64 srchash = src->get_hash(pos, pos + len - 1);
                i64 dsthash = dst->get_hash(pos, pos + len - 1);
                int cur = table.head[srchash];
                // printf("srchash = %lld, dsthash = %lld\n", srchash, dsthash);
                // printf("at pos = %d, len = %d\n", pos, len);
                while (cur != -1) {
                    // printf("Found %d\n", cur);
                    if (dsthash == rep[cur].to->get_hash(0, len - 1)) {
                        ++ans;
                    }
                    cur = table.next[cur];
                }
            }
        }
        printf("%d\n", ans);

        delete src;
        delete dst;
    }
    

    fclose(stdin);
    fclose(stdout);
    return 0;
}