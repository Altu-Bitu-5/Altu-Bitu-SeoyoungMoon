#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // 우선순위 큐 선언
    std::priority_queue<int> pq;

    // 마지막 행의 숫자들을 모두 큐에 넣음
    for(int j = 0; j < n; ++j) {
        pq.push(matrix[n-1][j]);
    }

    // 우선순위 큐에서 숫자를 하나 꺼내고, 해당 숫자보다 작은 가장 큰 숫자를 다시 큐에 넣는 과정을 반복
    for(int i = 0; i < n-1; ++i) {
        int current_max = pq.top();
        pq.pop();

        for(int j = 0; j < n; ++j) {
            if(matrix[n-2-i][j] < current_max) {
                pq.push(matrix[n-2-i][j]);
                break;
            }
        }
    }

    // 결과 출력
    std::cout << pq.top() << std::endl;

    return 0;
}
