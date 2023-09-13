#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int tmp = N;   // 현재 주어진 물병의 개수를 저장
    int ans = 0;   // 필요한 추가 물병의 개수

    while (true) {
        int cnt = 0;   // 2개의 물병을 합쳐야하는 횟수를 저장
        int total = tmp;  // 전체 물병의 개수를 저장

        for (int i = 0; total; ++i) {
            if (total % 2) {
                cnt++;  // 현재 자리의 물병이 있다면 cnt를 증가
            }
            total /= 2;
        }

        if (cnt <= K) {
            break;   // 만들어야하는 물병의 개수가 K 이하라면 종료
        }

        tmp++;  // 물병을 하나 추가
        ans++;  // 필요한 물병의 개수를 증가
    }

    cout << ans << '\n';

    return 0;
}
