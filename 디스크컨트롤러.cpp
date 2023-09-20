#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 우선순위 큐에서 작업 처리 시간이 더 짧은 작업이 먼저 나오게 하는 비교 연산자 정의
struct Compare {
    bool operator()(vector<int> a, vector<int> b) {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    int totalProcessingTime = 0;    // 전체 처리 시간
    int jobIndex = 0;               // 현재 점검 중인 작업의 인덱스
    int currentTime = 0;            // 현재 시간

    // 작업의 도착 시간을 기준으로 정렬
    sort(jobs.begin(), jobs.end());

    // 처리 시간을 기준으로 하는 최소 힙 선언
    priority_queue<vector<int>, vector<vector<int>>, Compare> waitingJobs;

    // 모든 작업이 처리될 때까지 반복
    while (jobIndex < jobs.size() || !waitingJobs.empty()) {
        // 만약 더 이상 대기 중인 작업이 없고, 현재 작업이 아직 처리되지 않았다면
        if (jobIndex < jobs.size() && currentTime >= jobs[jobIndex][0]) {
            waitingJobs.push(jobs[jobIndex++]);
            continue;
        }

        // 대기 중인 작업이 있을 경우, 그 작업을 처리
        if (!waitingJobs.empty()) {
            currentTime += waitingJobs.top()[1];
            totalProcessingTime += currentTime - waitingJobs.top()[0];
            waitingJobs.pop();
        }
        // 대기 중인 작업이 없을 경우, 다음 작업의 도착 시간으로 시간을 갱신
        else {
            currentTime = jobs[jobIndex][0];
        }
    }

    // 평균 처리 시간을 반환
    return totalProcessingTime / jobs.size();
}
