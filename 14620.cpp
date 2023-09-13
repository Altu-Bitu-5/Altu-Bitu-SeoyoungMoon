#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
int cost[10][10];
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};
int answer = INT_MAX;

// 해당 위치에 꽃을 심을 수 있는지 확인하는 함수
bool canPlant(int x, int y, vector<vector<bool>>& visited) {
    for (int i = 0; i < 5; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny]) {
            return false;
        }
    }
    return true;
}

// 해당 위치에 꽃을 심었을 때의 방문 체크 or 체크 해제
void setVisited(int x, int y, vector<vector<bool>>& visited, bool flag) {
    for (int i = 0; i < 5; ++i) {
        visited[x + dx[i]][y + dy[i]] = flag;
    }
}

// 해당 위치에 꽃을 심었을 때의 비용을 반환하는 함수
int getCost(int x, int y) {
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += cost[x + dx[i]][y + dy[i]];
    }
    return sum;
}

// 꽃을 심을 수 있는 모든 위치를 탐색하며 최소비용을 계산하는 DFS 함수
void dfs(int idx, int curCost, vector<vector<bool>>& visited) {
    if (idx == 3) {
        answer = min(answer, curCost);
        return;
    }

    for (int i = 1; i < N - 1; ++i) {
        for (int j = 1; j < N - 1; ++j) {
            if (canPlant(i, j, visited)) {
                setVisited(i, j, visited, true);
                dfs(idx + 1, curCost + getCost(i, j), visited);
                setVisited(i, j, visited, false);
            }
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> cost[i][j];
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    dfs(0, 0, visited);

    cout << answer << '\n';

    return 0;
}
