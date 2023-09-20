#include <iostream>
#include <queue>

int main() {

    std::ios::sync_with_stdio(false); // 시간 효율성을 위해 진행하기
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin >> n;

    // 최대 힙과 최소 힙을 선언합니다.
    std::priority_queue<int> max_heap; // 작은 숫자들을 관리
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap; // 큰 숫자들을 관리

    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;

        // 숫자를 두 힙 중 하나에 넣습니다.
        if (max_heap.size() > min_heap.size()) {
            min_heap.push(num);
        } else {
            max_heap.push(num);
        }

        // 두 힙의 최상위 원소를 비교하여 필요하면 교환합니다.
        if (!min_heap.empty() && max_heap.top() > min_heap.top()) {
            int max_val = max_heap.top();
            int min_val = min_heap.top();
            max_heap.pop();
            min_heap.pop();
            max_heap.push(min_val);
            min_heap.push(max_val);
        }

        // 중간값(최대 힙의 최댓값)을 출력합니다.
        std::cout << max_heap.top() << '\n';
    }

    return 0;
}
