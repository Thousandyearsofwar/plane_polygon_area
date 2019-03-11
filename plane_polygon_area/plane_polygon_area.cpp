
#include <iostream>
#include<vector>
#include<math.h>
using namespace std;
template<class T>
void caculate(T first,T last) {
	float area = 0;
	for (; (first +1) != last; ++first) {
			float k = ((*first)[1] - (*(first + 1))[1]) / ((*first)[0] - (*(first + 1))[0]);
			float b = (*first)[1] - k * ((*first)[0]);
			float delta_x = (*first)[0] - (*(first + 1))[0];
			area += k / 2 * pow(delta_x, 2) + b * delta_x;
		}
		printf("%.1f",&area);
}
int main()
{
	int pointnum;
	cin >> pointnum;
	vector<vector<int *>>sample;
	int point[2];
	
	while (true) {
		vector<int*> polygon;
		sample.push_back(polygon);
		while (pointnum != 0) {
			scanf_s("%d%d",&point[0],&point[1]);
			polygon.push_back(point);
			pointnum--;
		}
		cin >> pointnum;
		if (pointnum == 0) {
			vector<vector<int *>>::iterator iter = sample.begin();
			for (; iter != sample.end(); ++iter)
				caculate((*iter).begin(), (*iter).end());
			break;
		}
	}
	return 0;
}
