#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int initWeight, baseMetabolism, threshold, days, intake, burn;

    // 입력
    cin >> initWeight >> baseMetabolism >> threshold;
    cin >> days >> intake >> burn;

    int currWeight1 = initWeight;
    int currWeight2 = initWeight;

    // 변화된 기초대사량
    int adjustedMetabolism = baseMetabolism;

    for (int day = 0; day < days; day++)
    {
        currWeight1 += intake - (baseMetabolism + burn);
        currWeight2 += intake - (adjustedMetabolism + burn);

        // 기초대사량 변화 - currWeight2에만 반영, 체중 변화 후에 발생
        if (abs(intake - (adjustedMetabolism + burn)) > threshold)
            adjustedMetabolism += floor((intake - (adjustedMetabolism + burn)) / 2.0);
    }

    // 결과 출력 - 기초대사량 변화 반영하지 않은 경우
    if (currWeight1 <= 0)
        cout << "Danger Diet\n";
    else
        cout << currWeight1 << " " << baseMetabolism << "\n";

    // 결과 출력: 기초대사량 변화 반영된 경우
    if (currWeight2 <= 0 || adjustedMetabolism <= 0)
        cout << "Danger Diet\n";
    else
    {
        cout << currWeight2 << " " << adjustedMetabolism << " ";
        if (baseMetabolism - adjustedMetabolism > 0)
            cout << "YOYO";
        else
            cout << "NO";
    }
}
