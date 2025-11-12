#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    FILE *ifp = freopen("replace.in", "r", stdin);
    FILE *ofp = freopen("replace.out", "w+", stdout);

    std::cout << "MEI XIE WAN AAAAAAAAAAA TAT" << std::endl;

    fclose(ifp);
    fclose(ofp);
    return 0;
}